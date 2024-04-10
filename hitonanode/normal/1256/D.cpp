#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void solve()
{
    lint N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    deque<int> zeropos;
    REP(i, N) if (S[i] == '0') zeropos.push_back(i);
    string ret;
    while (!zeropos.empty() and K >= 0)
    {
        if (zeropos.front() - (int)ret.length() <= K)
        {
            K -= zeropos.front() - (int)ret.length();
            ret += '0';
            zeropos.pop_front();
        }
        else break;
    }
    int n = ret.length();
    int m = n;
    for (auto c : S)
    {
        if (n and c == '0') n--;
        else ret += c;
    }
    FOR(i, m, (int)ret.length()) if (ret[i] == '0')
    {
        ret[i] = '1';
        ret[i - K] = '0';
        break;
    }

    printf("%s\n", ret.c_str());
}

int main()
{
    int Q;
    cin >> Q;
    while (Q--) solve();
}