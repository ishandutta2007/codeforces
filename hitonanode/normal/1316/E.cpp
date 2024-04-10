#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;



int main()
{
    int N, P, K;
    cin >> N >> P >> K;
    vector<pint> a2i(N);
    REP(i, N) {
        cin >> a2i[i].first;
        a2i[i].second = i;
    }
    sort(a2i.rbegin(), a2i.rend());
    vector<vector<int>> S(N, vector<int>(P));
    cin >> S;

    vector<lint> dp(1 << P, -1e18);
    dp[0] = 0;
    REP(t, N) {
        int A = a2i[t].first, i = a2i[t].second;
        vector<lint> dp_nxt = dp;
        REP(se, 1 << P) {
            int nb_ouen = t - __builtin_popcount(se);
            if (nb_ouen < 0) continue;
            if (nb_ouen < K) mmax(dp_nxt[se], dp[se] + A);
            REP(n, P) if (!((se >> n) & 1)) mmax(dp_nxt[se + (1 << n)], dp[se] + S[i][n]);
        }
        dp = dp_nxt;
    }
    cout << dp.back() << endl;
}