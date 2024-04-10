#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;


int main()
{
    int N, K;
    cin >> N >> K;
    lint ret = 0, atot = 0, btot = 0;
    bitset<1000> dp;
    dp[0] = 1;
    for (int i = 0; i < N; i++)
    {
        lint a, b;
        cin >> a >> b;
        atot += a, btot += b;
        auto dpnxt = dp;
        for (int ia = 1; ia <= min<int>(K - 1, a); ia++) if (b >= K - ia) dpnxt |= (dp << ia);
        dpnxt |= dpnxt >> K;
        dp = dpnxt;
        for (int b = K; b < dp.size(); b++) dp[b] = 0;
    }

    for (int i = 0; i < K; i++) if (dp[i])
    {
        lint a = atot - i, b = btot;
        lint tmp = a / K;
        if (i) b -= K - i, tmp++;
        tmp += b / K;
        ret = max(ret, tmp);
    }
    cout << ret << '\n';
}