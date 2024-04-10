#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

constexpr int D = 21;
constexpr int DD = (1 << D);

void zeta_pattern2(vector<int> &f, int n=D) {
    REP(i, n) REP(b, 1<<n) if (!(b & (1 << i))) mmin(f[b], f[b ^ (1 << i)]);
}

void zeta_pattern1(vector<pint> &f, int n=D) {
    REP(i, n) REP(b, 1<<n) if (!(b & (1 << i)))
    {
        int vmax = max(f[b].first, f[b | (1 << i)].first);
        int vnxt = -1;
        if (f[b].first < vmax) mmax(vnxt, f[b].first);
        if (f[b].second < vmax) mmax(vnxt, f[b].second);
        if (f[b | (1 << i)].first < vmax) mmax(vnxt, f[b | (1 << i)].first);
        if (f[b | (1 << i)].second < vmax) mmax(vnxt, f[b | (1 << i)].second);
        f[b] = make_pair(vmax, vnxt);
    }
}


int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;

    vector<int> first_show(DD, N);
    IREP(i, N) first_show[A[i]] = i;

    vector<pint> last_show(DD, pint(-1, -1));
    REP(i, N)
    {
        last_show[A[i]].second = last_show[A[i]].first;
        last_show[A[i]].first = i;
    }
    zeta_pattern2(first_show);
    zeta_pattern1(last_show);

    int ret = 0;
    IREP(d, D)
    {
        int want_to_make = ret + (1 << d);
        // d bit
        REP(k, DD)
        {
            int t1 = k & want_to_make;
            int t2 = want_to_make - t1;
            if (first_show[t1] < last_show[t2].second)
            {
                ret = want_to_make;
                break;
            }
        }
    }
    cout << ret << endl;
}