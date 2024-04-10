#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
int mv[1<<14];
string g[14];
vector<ll>dp[1<<14][14];
vector<int>bts[1<<14],nbts[1<<14];
ll ans[1<<14];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)cin>>g[i];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)g[i][j]-='0';
    for(int i=1;i<1<<n;i++){
        mv[i]=1<<__builtin_popcount(i)-1;
        for(int j=0;j<n;j++)dp[i][j].resize(mv[i]);
        for(int j=0;j<n;j++){
            if(((i>>j)&1))bts[i].push_back(j);
            else nbts[i].push_back(j);
        }
    }
    for(int i=0;i<n;i++)dp[1<<i][i][0]=1;
    for(int i=1;i<1<<n;i++){
        for(int j:bts[i]){
            for(int k:nbts[i]){
                for(int l=0;l<mv[i];l++){
                    dp[i+(1<<k)][k][l+(g[j][k])*mv[i]]+=dp[i][j][l];
                }
            }
        }
    }
    for(int i=0;i<n;i++)for(int j=0;j<dp[(1<<n)-1][i].size();j++)ans[j]+=dp[(1<<n)-1][i][j];
    for(int i=0;i<1<<n-1;i++)printf("%lld ",ans[i]);
}