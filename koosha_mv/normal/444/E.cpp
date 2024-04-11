#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=4e3;

int n,u,v,w,l,r,sz,res,mid,sum,c[N],mark[N];
vector<pair<int,int> > g[N];

void read(){
	cin>>n;
	f(i,1,n){
		Gett(u,v);
		gett(w);
		g[u].pb(mp(v,w));
		g[v].pb(mp(u,w));
	}
	f(i,1,n+1){
		gett(c[i]);
		sum+=c[i];
	}
}
void dfs(int x,int mx){
	sz++;
	mark[x]=1;
	res-=c[x];
	f(i,0,g[x].size())
		if(!mark[g[x][i].F] && g[x][i].S<mx)
			dfs(g[x][i].F,mx);
}
bool check(int x){
	fill(mark,mark+N,0);
	f(i,1,n+1)
		if(!mark[i]){
			sz=0;
			res=sum;
			dfs(i,x);
			if(res<sz) return 0;
		}
	return 1;
}
void solve(){
	l=0,r=2e5;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l<<endl;
}

int main(){
	read();
	solve();
}