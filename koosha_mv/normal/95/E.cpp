#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+99,lg=18;

int n,m,ans=N,a[N],dp[N],cnt[N],par[N];

int Get_par(int u){
	if(par[u]<0) return u;
	return par[u]=Get_par(par[u]);
}
void merge(int u,int v){
	u=Get_par(u),v=Get_par(v);
	if(u==v) return ;
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
void upd(int x,int val){
	f_(i,n,x){
		minm(dp[i],dp[i-x]+val);
	}	
}
void lucky(int x){
	if(x>N) return ;
	minm(ans,dp[x]);	
	lucky(x*10+4);
	lucky(x*10+7);
}

int main(){
	fill(par,par+N,-1);
	fill(dp+1,dp+N,N);
	cin>>n>>m;
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		merge(u,v);
	}
	f(i,1,n+1){
		if(par[i]<0){
			cnt[-par[i]]++;
		}
	}
	f(i,1,n+1){
		for(;cnt[i]>0;){
			int x=(cnt[i]+1)/2;
			upd(i*x,x);
			cnt[i]-=x;
		}
	}
	lucky(4);
	lucky(7);
	if(ans==N) cout<<-1;
	else cout<<ans-1;
}