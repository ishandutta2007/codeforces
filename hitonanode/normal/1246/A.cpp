#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

constexpr int INF = 1e9;

int main()
{
    lint N, P;
    cin >> N >> P;
    int ret = INF;
    FOR(ans, 1, 100000)
    {
        lint tgt = N - ans * P;
        if (tgt <= 0) continue;
        int t = __builtin_popcountll(tgt);
        if (ans >= t and tgt >= ans) mmin(ret, ans);
    }
    cout << (ret == INF ? -1 : ret) << endl;
}