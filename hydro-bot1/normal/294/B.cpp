// Hydro submission #62f51011ef830476c2efde5e@1660227601990
#include <iostream>

using std::cin;
using std::cout;

int t[110], w[110];
int dp[210];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> t[i] >> w[i];
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += t[i];
    for (int i = 0; i < n; ++i)
        for (int j = sum; j >= w[i] + t[i]; --j)
            dp[j] = dp[j - w[i] - t[i]] + t[i] > dp[j] ? dp[j - w[i] - t[i]] + t[i] : dp[j];
    cout << sum - dp[sum];
    return 0;
}