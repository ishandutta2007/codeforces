#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
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

const int N=1e6+2,Lg=20;

int n,t,u,v,w,c,sub[N],ep[N];;
ll S,sum,ans[N*Lg];
vector<pair<int,pair<int,int> > > g[N];
set<pair<ll,int> > s[2];

void clear(){
	f(i,1,n+1) g[i].clear();
	s[0].clear(),s[1].clear(),sum=0;
}
void dfs(int x,int par,int w,int c){
	sub[x]=(g[x].size()==1);
	f(i,0,g[x].size())
		if(g[x][i].F!=par)
			dfs(g[x][i].F,x,g[x][i].S.F,g[x][i].S.S),sub[x]+=sub[g[x][i].F];
	sum+=1ll*sub[x]*w;
	if(w)
		s[c].insert(mp(1ll*sub[x]*((w+1)/2),x)),ep[x]=w; 
}
void change(int x,int src){
	ep[x]/=2;
	s[src].insert(mp(1ll*sub[x]*((ep[x]+1)/2),x));
}
void solve1(int src){
	ll res=0;
	for(int i=1;i<=n*Lg;i++){
		if(!s[src].size()) ans[i]=res;
		else{
			pair<ll,int> p=*s[src].rbegin();
			res+=p.F;
			s[src].erase(p);
			change(p.S,src);
			ans[i]=res;
		}
	}
}
void solve0(int src){
	ll res=0;
	int mn=Lg*n*3,p=Lg*n;
	for(int i=0;i<=n*Lg;i++){
		if(i!=0){
			if(s[src].size()){
				pair<ll,int> p=*s[src].rbegin();
				res+=p.F;
				s[src].erase(p);
				change(p.S,src);
			}
		}
		while(p && sum-ans[p-1]-res<=S) p--;
		if(sum-ans[p]-res<=S)
			minm(mn,i+p*2);
	}
	cout<<mn<<'\n';
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>S;
		clear();
		f(i,1,n){
			Gett(u,v);
			Gett(w,c);
			c--;
			g[u].pb(mp(v,mp(w,c)));
			g[v].pb(mp(u,mp(w,c)));
		}
		dfs(1,0,0,0);
		solve1(1);
		solve0(0);
	}
}