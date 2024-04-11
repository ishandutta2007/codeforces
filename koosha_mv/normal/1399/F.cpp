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

const int N=4e5+99;

int n,t,c,a[N],l[N],r[N],w[N],dp[N],tn[N];
pair<int,int> mv[N];
vector<int> v[N];

bool check(int x,int y){
	return (l[x]<=l[y] && r[y]<=r[x]);
}
void tabdil(){
	sort(a,a+n+n);
	c=0;
	f(i,0,2*n)
		if(i==0 || a[i]!=a[i-1])
			tn[a[i]]=++c;
	f(i,0,n){
		l[i]=tn[l[i]],r[i]=tn[r[i]];
		mv[i]=mp(r[i],-l[i]);
	}
	sort(mv,mv+n);
	f(i,0,n){
		l[i]=-mv[i].S,r[i]=mv[i].F;
	}
}
void calcwx(int x){
	dp[l[x]-1]=0;
	f(i,l[x],r[x]+1){
		dp[i]=dp[i-1];
		f(j,0,v[i].size())
			if(check(x,v[i][j]))
				maxm(dp[i],dp[l[v[i][j]]-1]+w[v[i][j]]);
	}
	w[x]=dp[r[x]]+1;
}
void calcw(){
	f(i,0,n)
		calcwx(i);
}
void calc(int x){
	dp[x]=dp[x-1];
	f(i,0,v[x].size())
		maxm(dp[x],dp[l[v[x][i]]-1]+w[v[x][i]]);
}
void solve(){
	dp[0]=0;
	f(i,1,n*2+1)
		calc(i);
	cout<<dp[n*2]<<'\n';
}

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		fill(w,w+n,0);
		f(i,0,2*n+2) v[i].clear();
		f(i,0,n){ Gett(l[i],r[i]); a[i*2]=l[i],a[i*2+1]=r[i]; } 
		tabdil();
		f(i,0,n) v[r[i]].pb(i); 
		calcw();
		solve();
	}
}