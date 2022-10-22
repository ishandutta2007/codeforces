#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e5+9,Lg=30;
 
int n,m,x,a[N],h[N],ans[N],mask[Lg],mark[N],edge[N][3];
vector<int> v;
vector<pair<int,int> > g[N];
 
void maXor(){
    int res=x,Mask=0;
    f(i,0,n){
        int x=a[i];
        f(j,0,v.size())
            minm(x,x^a[v[j]]);
        if(x){
            int l=v.size();
			v.pb(i),mask[l]|=(1LL<<l);
			f(j,0,l)
				if (a[i]>(a[i]^a[v[j]])){
					a[i]^=a[v[j]];
					mask[l]^=mask[j];
				}
        }
    }
    f(i,0,v.size())
        if((res^a[v[i]])<res)
            res=res^a[v[i]],Mask^=mask[i];
    f(i,0,Lg)
        if(Mask&(1ll<<i))
            ans[v[i]]=1;
    cout<<res;
}
void dfs(int x){
    mark[x]=1;
    f(i,0,g[x].size())
        if(!mark[g[x][i].F]){
            h[g[x][i].F]=h[x]^g[x][i].S;
            dfs(g[x][i].F);
        }
}

int main(){
    cin>>n>>m;
    f(i,0,m){
        int u,v,w;
        Gett(u,v);
        gett(w);
        g[u].pb(mp(v,w));
        g[v].pb(mp(u,w));
        edge[i][0]=u;
        edge[i][1]=v;
        edge[i][2]=w;
    }
    dfs(1);
    x=h[n];
    f(i,0,m){
        a[i]=h[edge[i][0]]^h[edge[i][1]]^edge[i][2];
    }
    n=m;
    maXor();
}