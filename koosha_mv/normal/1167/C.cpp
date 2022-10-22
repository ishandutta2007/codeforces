#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+9;

int n,t,k,m,p,x,cmp=1,cnt[N],mark[N];
vector<int> g[N];

void dfs(int x){
	mark[x]=cmp;
	cnt[cmp]++;
	f(i,0,g[x].size())
		if(mark[g[x][i]]==0)
			dfs(g[x][i]);
}
int main(){
	cin>>n>>m;
	f(i,0,m){
		cin>>k;
		f(i,0,k){
			cin>>x;
			if(i>0) g[p].pb(x),g[x].pb(p);
			p=x;
		}
	}
	f(i,1,n+1){
		if(mark[i]==0){
			dfs(i);
			cmp++;
		}
	}
	f(i,1,n+1) cout<<cnt[mark[i]]<<" ";
}