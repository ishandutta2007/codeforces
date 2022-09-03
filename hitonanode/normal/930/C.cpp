#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }


vector<int> sol(vector<int> v) {
    int N = v.size();
    vector<int> ret(N + 1);
    vector<int> dp(N + 1, 1e9);
    dp[0] = 0;
    REP(i, N) {
        int t = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        ret[i + 1] = max(ret[i], t);
        dp[t] = v[i];
    }
    return ret;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> imos(M + 1);
    while (N--) {
        int l, r;
        cin >> l >> r;
        imos[l - 1]++;
        imos[r]--;
    }
    REP(i, M) imos[i + 1] += imos[i];
    imos.pop_back();
    vector<int> v = sol(imos);
    reverse(imos.begin(), imos.end());
    vector<int> w = sol(imos);
    int ret = 0;
    REP(i, M + 1) {
        chmax(ret, v[i] + w[M - i]);
    }
    cout << ret << "\n";
}