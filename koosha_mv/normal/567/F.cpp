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
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=100;

int n,k,a[N],x[N],y[N];
ll ans,dp[N][N];
string s[N];
vector<int> g0[N],g1[N],g2[N]; // < <= =

bool check(int l,int r,int x,int y){
	for(auto v : g0[x]){
		if(v<=l || r<=v) return 0;
	}
	for(auto v : g1[x]){
		if(v!=y && (v<=l || r<=v)) return 0;
	}
	for(auto v : g2[x]){
		if(v!=y) return 0;
	}
	swap(x,y);
	for(auto v : g0[x]){
		if(v<=l || r<=v) return 0;
	}
	for(auto v : g1[x]){
		if(v!=y && (v<=l || r<=v)) return 0;
	}
	for(auto v : g2[x]){
		if(v!=y) return 0;
	}
	return 1;
}
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>k;
	f(i,0,k){
		cin>>x[i]>>s[i]>>y[i];
		if(s[i]==">" || s[i]==">=") swap(x[i],y[i]),s[i][0]='<';
		if(x[i]==y[i]){
			if(s[i]=="<"){
				cout<<0;
				exit(0);
			}
			continue ;
		}
		if(s[i]=="<"){
			g0[x[i]].pb(y[i]);
		}
		if(s[i]=="<="){
			g1[x[i]].pb(y[i]);
		}
		if(s[i]=="="){
			g2[x[i]].pb(y[i]);
		}
	}
	dp[0][2*n+1]=1;
	f(l,0,2*n){
		f_(r,2*n+1,l+3){
			if((l+r)%2==0 || dp[l][r]==0) continue ;
			//cout<<l<<" "<<r<<" -> "<<dp[l][r]<<endl;
			int x,y;
			if(check(l+2,r,l+1,l+2)){
				dp[l+2][r]+=dp[l][r];
			}
			if(check(l,r-2,r-1,r-2)){
				dp[l][r-2]+=dp[l][r];
			}
			if(check(l+1,r-1,l+1,r-1)){
				dp[l+1][r-1]+=dp[l][r];
			}
		}
	}
	f(l,0,2*n+1){
		int r=l+3;
		if(check(l+1,r-1,l+1,r-1)){
			ans+=dp[l][r];
		}
	}
	cout<<ans;
}