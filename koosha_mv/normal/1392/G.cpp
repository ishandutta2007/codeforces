#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e6+99,K=20;

int n,m,k,L,R,ans=K,a[N],b[N],lg[N];
pair<int,int> dp[N];
vector<int> p1,p2;
string s,t;

int fb(int x){
	if(x==0) return k;
	return lg[x&-x];
}
void op(vector<int> &v,int _u,int _v){
	f(i,0,v.size()){
		if(v[i]==_u || v[i]==_v){
			v[i]=v[i]^_u^_v;
		}
	}
}
void dfs(int mask,int mc,int dist,int x){
	if(dp[mask].F<=dist) return ;
	dp[mask]=mp(dist,x);
	int l=fb(mc)-1;
	f_(i,l,0){
		dfs(mask^(1<<i),mc^(1<<i),dist+1,x);
	}
}
void Add(int x){
	int mask=0;
	f(i,0,p2.size()){
		int u=i,v=p2[i];
		mask|=(1<<u)*(t[u]!=t[v]);
	}
	dfs(mask,0,0,x);
}
void solve(int x){
	int mask=0;
	f(i,0,p1.size()){
		mask|=(1<<i)*(s[p1[i]]!=t[i]);
	}
	if(dp[mask].F<ans){
		ans=dp[mask].F;
		L=x,R=dp[mask].S;
	}
}


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	f(i,0,N) dp[i]=mp(N,N);
	f(i,0,K) lg[(1<<i)]=i;
	cin>>n>>m>>k;
	cin>>s>>t;
	f(i,0,n){
		cin>>a[i]>>b[i];
		a[i]--,b[i]--;
	}
	f(i,0,k){
		p1.pb(i);
		p2.pb(i);
	}
	f_(i,n-1,0){
		op(p1,a[i],b[i]);
		if(i+m<=n){
			op(p2,a[i+m],b[i+m]);
			Add(i+m);
			solve(i);
		}
	}
	cout<<k-ans<<endl<<L+1<<" "<<R;
}
/*
3 1 3
100
001
1 3
1 3
2 3

3 3 5
11000
00011
1 3
3 5
4 2
*/