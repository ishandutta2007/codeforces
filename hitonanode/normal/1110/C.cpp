#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


map<int, int> ma;
int solve()
{
    int a;
    cin >> a;
    if (ma.count(a)) return ma[a];

    if (__builtin_popcount(a + 1) == 1)
    {
        int ret = 1;
        FOR(i, 2, a) if (a % i == 0)
        {
            ret = a / i;
            break;
        }
        ma[a] = ret;
        return ret;
    }
    else
    {
        bool f = false;
        int ret = a;
        IREP(d, 31)
        {
            if ((a >> d) & 1) f = true;
            else
            {
                if (f) ret += 1 << d;
            }
        }
        return ret;
    }
}

int main()
{
    int q;
    cin >> q;
    while (q--) cout << solve() << endl;
}