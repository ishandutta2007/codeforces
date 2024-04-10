#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
const int mn=1e6+10;
const ll mod=1e9+7;
vector<int>v[3];
int dp[76][76][76][3];
int sub(int a,int b,int c,int x){
    return min((int)(lower_bound(v[0].begin(),v[0].end(),x)-v[0].begin()),a)+
            min((int)(lower_bound(v[1].begin(),v[1].end(),x)-v[1].begin()),b)+
            min((int)(lower_bound(v[2].begin(),v[2].end(),x)-v[2].begin()),c);
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='V')v[0].push_back(i);
        else if(s[i]=='K')v[1].push_back(i);
        else v[2].push_back(i);
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0][2]=0;
    for(int i=0;i<=v[0].size();i++){
        for(int j=0;j<=v[1].size();j++){
            for(int k=0;k<=v[2].size();k++){
                int a=(i!=v[0].size())?v[0][i]-sub(i,j,k,v[0][i]):0x3f3f3f3f,
                b=(j!=v[1].size())?v[1][j]-sub(i,j,k,v[1][j]):0x3f3f3f3f,
                c=(k!=v[2].size())?v[2][k]-sub(i,j,k,v[2][k]):0x3f3f3f3f;
                dp[i+1][j][k][0]=min(dp[i][j][k][0],min(dp[i][j][k][1],dp[i][j][k][2]))+a;
                dp[i][j+1][k][1]=min(dp[i][j][k][1],dp[i][j][k][2])+b;
                dp[i][j][k+1][2]=min(dp[i][j][k][0],min(dp[i][j][k][1],dp[i][j][k][2]))+c;
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=0;i<3;i++)ans=min(ans,dp[v[0].size()][v[1].size()][v[2].size()][i]);
    printf("%d",ans);
}