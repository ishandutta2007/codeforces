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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    cin >> A;
    vector<vector<int>> req(200001);
    for (auto v : A)
    {
        int t = 0;
        while (v)
        {
            req[v].push_back(t);
            v /= 2;
            t++;
        }
        req[v].push_back(t);
    }
    lint ans = 1e18;
    for (auto &v : req) if ((int)v.size() >= K)
    {
        sort(ALL(v));
        mmin(ans, accumulate(v.begin(), v.begin() + K, 0LL));
    }
    cout << ans << endl;
}