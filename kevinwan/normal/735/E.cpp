#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=110+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
ll dp[mn][22][22],t[22][22],u[22][22];
int k;
vector<int>g[mn];
void dfs(int x,int p){
    for(int y:g[x])if(y!=p){
            dfs(y,x);
        }
    memset(t,0,sizeof(t));
    t[k+1][0]=1;
    for(int y:g[x])if(y!=p){
            memset(u,0,sizeof(u));
            for(int a=1;a<=k+1;a++){
                for(int b=0;b<k+1;b++){
                    for(int c=1;c<=k+1;c++){
                        for(int d=0;d<k+1;d++){
                            int i=min(a,c),j;
                            int bb=b,dd=d;
                            if(a+d<=k)dd=0;
                            if(b+c<=k)bb=0;
                            j=max(bb,dd);
                            u[i][j]+=t[a][b]*dp[y][c][d],u[i][j]%=mod;
                        }
                    }
                }
            }
            memcpy(t,u,sizeof(t));
        }
    for(int a=1;a<=k+1;a++)for(int b=0;b<=k;b++){
            int i=a+1,j=b+1;
            if(i<=k+1&&j==1)j=0;
            if(i>k+1)i=k+1;
            if(j>k+1)continue;
            dp[x][i][j]+=t[a][b];
            dp[x][i][j]%=mod;
            dp[x][1][0]+=t[a][b];
            dp[x][1][0]%=mod;
        }
}
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n;
    cin>>n>>k;
    if(!k){printf("1\n");return 0;}
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    ll ans=0;
    for(int i=1;i<=k+1;i++)ans+=dp[1][i][0],ans%=mod;
    printf("%lld",ans);
}