#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+9;
const int mn=1e5+10;
vector<int>aa,bb;
ll p[19];
ll dp[38][19];
bool bac[38][19];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    string s;
    cin>>n>>s;
    p[0]=1;
    for(int i=1;i<=n;i++)p[i]=p[i-1]*10;
    memset(dp,0xc0,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<n*2;i++){
        for(int j=0;j<=n;j++){
            int k=i+1-j;
            ll p0=0xc0c0c0c0c0c0c0c0,p1=p0;
            if(j) {
                p0=dp[i][j-1]+(s[i]-'0')*p[n-j];
            }
            if(k){
                p1=dp[i][j]+(s[i]-'0')*p[n-k];
            }
            if(p0>p1)dp[i+1][j]=p0,bac[i+1][j]=0;
            else dp[i+1][j]=p1,bac[i+1][j]=1;
        }
    }
    int b=n;
    string ans;
    for(int i=n*2;i;i--){
        if(bac[i][b])ans.push_back('H');
        else ans.push_back('M'),b--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}