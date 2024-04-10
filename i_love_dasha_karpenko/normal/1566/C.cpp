#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;

int A[2][N],dp[N],last[2][N];

void solve(){
    int n;
    cin>>n;
    for(int c = 0;c<2;++c)
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[c][i] = ch-'0';
    }
    last[0][n+1] = last[1][n+1] = n+1;
    for(int i = n;i>=1;--i){
        for(int c = 0;c<2;++c)
            last[c][i] = last[c][i+1];
        for(int c = 0;c<2;++c){
            last[A[c][i]][i] = i;
        }
    }
    for(int i = 1;i<=n;++i){
        if (A[0][i]^A[1][i]){
            dp[i+1] = max(dp[i+1],dp[i]+2);
        }
        else{
            dp[i+1] = max(dp[i+1],dp[i]+(A[0][i]==0));
            int pos = last[A[0][i]^1][i];
            dp[pos+1] = max(dp[pos+1],dp[i]+2);
        }
    }
    cout<<dp[n+1]<<endl;
    for(int i = 0;i<=n+2;++i){
        dp[i] = last[0][i] = last[1][i] = A[0][i] = A[1][i] = 0;
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