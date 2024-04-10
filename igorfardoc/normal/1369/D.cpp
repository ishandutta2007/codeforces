#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int mod = 1000000007;
int dp[2000001];



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    for(int i = 1; i <= 2000000; i++) {
        if(i < 3) {
            continue;
        }
        dp[i] = ((ll)2 * dp[i - 2] + dp[i - 1] + (i % 3 == 0)) % mod;
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << ((ll)dp[n] * 4) % mod << '\n';
    }
}