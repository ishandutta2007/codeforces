#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


int main()
{
    string S, T;
    cin >> S >> T;
    int N = S.length(), M = T.length();
    vector<int> dp1(N + 1), dp2(N + 1);
    REP(i, N) {
        dp1[i + 1] = dp1[i];
        if (dp1[i] < M and S[i] == T[dp1[i]]) dp1[i + 1]++;

        dp2[i + 1] = dp2[i];
        if (dp2[i] < M and S[N - 1 - i] == T[M - 1 - dp2[i]]) dp2[i + 1]++;
    }
    int i = N, j = 0;
    int ret = 0;
    while (i >= 0)
    {
        while (dp1[i] + dp2[j] < M) j++;
        ret = max(ret, N - i - j);
        i--;
    }
    cout << ret << endl;
}