#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

lint K;

int main()
{
    lint N, S;
    cin >> N >> S;
    if (S < N * 2 - 1 or S > (N + 2) * (N + 1) / 2)
    {
        puts("No");
        return 0;
    }
    puts("Yes");
    for (lint k = 1;; k++)
    {
        lint rem = N;
        lint dsum = 0;
        lint depth = 1;
        lint c = 1;
        while (rem > 0)
        {
            lint use = min(rem, c);
            rem -= use;
            dsum += use * depth;
            depth++;
            c *= k;
        }
        if (dsum <= S)
        {
            K = k;
            break;
        }
    }

    if (K == 1)
    {
        REP(i, N - 1) printf("%d ", i + 1);
        puts("");
        return 0;
    }

    vector<int> nums{0, 1};
    lint rem = N - 1;
    lint srem = S - 1;
    while (rem)
    {
        lint use = min(nums.back() * K, rem);
        rem -= use;
        srem -= nums.size() * use;
        nums.push_back(use);
    }
    int p = nums.size() - 1;
    while (srem)
    {
        if (nums[p] == 1) p--;
        else
        {
            lint imp = min(srem, (lint)nums.size() - p);
            srem -= imp;
            if (imp == (lint)nums.size() - p) nums.push_back(1);
            else nums[p + imp]++;
            nums[p]--;
        }
    }
    vector<int> lo(nums.size());
    lo[0] = 1;
    FOR(i, 1, lo.size()) lo[i] = lo[i - 1] + nums[i - 1];
    for (int d = 2; d < (int)lo.size(); d++)
    {
        int c = 0;
        REP(_, nums[d])
        {
            printf("%d ", lo[d - 1]);
            c++;
            if (c == K) lo[d - 1]++, c = 0;
        }
    }
    puts("");
}