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


vector<int> Zalgorithm(const string &s) {
    vector<int> ans(s.size());
    ans[0] = s.size();
    int i = 1, j = 0;
    while (i < (int)s.size()) {
        while (i + j < (int)s.size() && s[j] == s[i+j]) ++j;
        ans[i] = j;
        if (!j) {
            ++i;
            continue;
        }
        int k = 1;
        while (i + k < (int)s.size() && k + ans[k] < j) ans[i+k] = ans[k], ++k;
        i += k;
        j -= k;
    }
    return ans;
}

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    vector<int> dp(N + 1, 1e9);
    dp[0] = 0;
    REP(i, N)
    {
        mmin(dp[i + 1], dp[i] + A);
        string T = S.substr(i) + "_" + S.substr(0, i);
        vector<int> z = Zalgorithm(T);
        int t = *max_element(z.begin() + N - i, z.end());
        REP(j, t) if (i + 1 + j < (int)dp.size()) mmin(dp[i + 1 + j], dp[i] + B);
    }
    cout << dp.back() << endl;
}