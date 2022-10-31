#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;
const int masksz = 1<<3;
int dp[N][2][masksz];
int F(int mask){
    for(int bit = 0;bit<=2;++bit){
        if (!(mask&(1<<bit)))
            return bit;
    }
}
void solve(){
    string s;
    cin>>s;
    int n = s.length();
    dp[0][0][0] = 1;
    for(int i = 1;i<=n;++i){
        int cur = s[i-1]-'0';
        for(int sum = 0;sum<2;++sum){
            for(int mask = 0;mask<masksz;++mask){
                if (!dp[i-1][sum][mask])
                    continue;
                dp[i][sum][mask|(1<<cur)] = 1;
                int val = sum+F(mask|(1<<cur));
                if (val<2)
                    dp[i][val][0] = 1;
            }
        }
    }
    if (dp[n][0][0]==1)
        cout<<"0\n";
    else if (dp[n][1][0])
        cout<<"1\n";
    else cout<<"2\n";
    for(int i = 0;i<=n;++i){
        for(int s = 0;s<2;++s){
            for(int mask = 0;mask<masksz;++mask)
                dp[i][s][mask] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}