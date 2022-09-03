#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int main()
{
    int N;
    cin >> N;
    vector<lint> A(N);
    cin >> A;
    lint tot = accumulate(ALL(A), 0LL);
    set<lint> ya;

    for (lint i = 1; i * i <= tot; i++) if (tot % i == 0)
    {
        ya.insert(i);
        ya.insert(tot / i);
    }
    ya.erase(1);

    lint ret = -1;
    for (lint m : ya)
    {
        lint cost = 0;
        lint nokori = 0;
        REP(i, N)
        {
            nokori = (nokori + A[i]) % m;
            cost += min(nokori, m - nokori);
        }
        if (ret < 0 or cost < ret) ret = cost;
    }
    cout << ret << endl;
}