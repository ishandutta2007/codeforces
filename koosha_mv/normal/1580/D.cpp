#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=5005,Max=(1ll<<31);

int n,m,c,a[N];
vector<int> dp[N*10];

void solve(int l,int r,int x){
	int s=++c,t=++c;
	dp[x].pb(0);
	if(r<=l) return ;
	if(l+1==r){
		dp[x].pb(a[l]*m-a[l]);
		return ;
	}
	pair<int,int> mn=mp(Max,Max);
	f(i,l,r) minm(mn,mp(a[i],i));
	if(mn.S==l){
		solve(l,mn.S+1,s);
		solve(mn.S+1,r,t);
	}
	else{
		solve(l,mn.S,s);
		solve(mn.S,r,t);
	}
	f(i,0,max(1ll,mn.S-l)+1){
		f(j,0,min(r-l-1,r-mn.S)+1){
			if(i+j==dp[x].size()) dp[x].pb(0);
			maxm(dp[x][i+j],dp[s][i]+dp[t][j]-2*i*j*mn.F);
		}
	}
}

main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	f(i,1,n+1) cin>>a[i];
	solve(1,n+1,0);
	cout<<dp[0][m];
}