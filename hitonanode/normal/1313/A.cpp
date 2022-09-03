#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

int solve()
{
    vector<int> v(3);
    cin >> v;
    int ret = 0;
    REP(S, 1 << 8)
    {
        vector<int> cnt(3);
        REP(d, 8) if ((S >> d) & 1) {
            REP(i, 3) if ((d >> i) & 1) {
                cnt[i]++;
            }
        }
        bool f = true;
        REP(d, 3) if (cnt[d] > v[d]) f = false;
        if (f) mmax(ret, __builtin_popcount(S));
    }
    return ret - 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << endl;
}