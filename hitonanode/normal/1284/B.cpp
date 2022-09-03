#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


int main()
{
    lint N;
    cin >> N;
    vector<int> lo;
    vector<int> hi;
    lint ok = 0;
    REP(i, N)
    {
        int L;
        cin >> L;
        int l = 1e9, h = -1;
        bool f = false;
        while (L--) {
            int tmp;
            cin >> tmp;
            if (tmp > l) f = true;
            mmin(l, tmp);
            mmax(h, tmp);
        }
        if (f)
        {
            ok++;
            continue;
        }
        lo.emplace_back(l);
        hi.emplace_back(h);
    }
    sort(ALL(lo));
    lint r2 = 0;
    for (auto x : hi) {
        auto itr = lower_bound(ALL(lo), x);
        r2 += itr - lo.begin();
    }
    cout << ok * ok + 2 * (N - ok) * ok + r2 << endl;
}