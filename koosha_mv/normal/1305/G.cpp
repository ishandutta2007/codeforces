#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int lg=18,N=(1<<lg),m=3;

int n,t,a[N],par[N],dp[N][m];
ll ans;
pair<int,int> b[N];

bool cmp(int i,int j){
	return a[i]>a[j];
}
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
void Add(int mask,int x){
	dp[mask][m-1]=x;
	sort(dp[mask],dp[mask]+m,cmp);
	if(Get_par(dp[mask][0])==Get_par(dp[mask][1])){
		swap(dp[mask][1],dp[mask][2]);
	}
}
void do_it(){
	a[N-1]=-1;
	f(i,0,N){ dp[i][0]=dp[i][1]=dp[i][2]=0; b[i]={N-1,N-1}; }
	f(i,0,n){
		Add(a[i],i);
	}
	f(mask,0,N){
		f(i,0,lg){
			if(mask&(1<<i)){
				f(j,0,m-1){
					Add(mask,dp[mask^(1<<i)][j]);
				}
			}
		}
	}
	f(i,0,n){
		int mask=(1<<lg)-a[i]-1,par=Get_par(i);
		f(j,0,m-1){
			int x=dp[mask][j];
			if(par!=Get_par(x) && a[b[par].F]+a[b[par].S]<=a[i]+a[x]){
				b[par]={i,x};
			}
		}
	}
	f(i,0,n){
		if(par[i]<0 && b[i].F!=N-1 && b[i].S!=N-1 && Get_par(b[i].F)!=Get_par(b[i].S)){
			ans+=a[b[i].F]+a[b[i].S];
			merge(b[i].F,b[i].S);
		}
	}
}
int main(){
	fill(par,par+N,-1);
	cin>>n;
	f(i,1,n+1){ cin>>a[i]; ans-=a[i]; } n++;
	while(-n<par[Get_par(0)]){
		do_it();
	}
	cout<<ans;
}
/*
2
1
2
*/