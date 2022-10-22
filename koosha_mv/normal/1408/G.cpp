#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define pi pair<int,int>
 
const int N=1505,mod=998244353;

int n,c,par[N],edge[N*2],ok[N*2],g[N*2][2],dp[2*N][N];
pair<int,int> a[N*N];
vector<int> cmp[N*2];

int main(){
    cin>>n;
    f(i,1,n+1)
        f(j,1,n+1){
            int x;
            gett(x);
            a[x]=mp(i,j);
        }
    f(i,1,n+1)
        par[i]=i,c=i,cmp[i].pb(i);
    f(i,1,n*(n-1)/2+1){
        int u=a[i].F,v=a[i].S;
        if(par[u]!=par[v]){
            c++;
            edge[c]=edge[par[u]]+edge[par[v]];
            g[c][0]=par[u],g[c][1]=par[v];
            f(j,0,cmp[par[u]].size())
                cmp[c].pb(cmp[par[u]][j]);
            f(j,0,cmp[par[u]].size())
                par[cmp[par[u]][j]]=c;
            f(j,0,cmp[par[v]].size())
                cmp[c].pb(cmp[par[v]][j]);
            f(j,0,cmp[par[v]].size())
                par[cmp[par[v]][j]]=c;                
        }
        int sz=cmp[par[u]].size();
        edge[par[u]]++;
        if(edge[par[u]]==sz*(sz-1)/2)
            ok[par[u]]=1;
    }
    f(i,1,2*n){
        if(g[i][0]){
            int u=g[i][0],v=g[i][1];
            f(j,1,cmp[u].size()+1)
                f(k,1,cmp[v].size()+1)
                    Add(dp[i][j+k],1ll*dp[u][j]*dp[v][k]%mod);
        }
        if(cmp[i].size()==1 || ok[i])
            dp[i][1]=1;
    }
    f(i,1,n+1) cout<<dp[2*n-1][i]<<" ";
}