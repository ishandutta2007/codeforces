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

const int N=2002,Z=26;

int n,T,cop,dp[N][N];
string s,t;
vector<int> v[Z];

void make(){
	f(i,0,Z)
		v[i].clear();
	f_(i,n-1,0)
		v[t[i]-'a'].pb(i+1);
	f(i,1,n+1)
		dp[0][i]=-N;
	f(i,1,n+1)
		f(j,0,n+1)
			dp[i][j]=-N;
}
int find(int an,int x){
	int l=0,r=v[an].size(),mid;
	if(v[an][0]<=x) return 0;
	while(l+1<r){
		mid=(l+r)/2;
		if(v[an][mid]>x) l=mid;
		else r=mid;
	}
	return v[an][l];
}
void solve(){
	cin>>n>>s>>t;
	s=' '+s;
	make();
	f(i,1,n+1){
		int c=s[i]-'a';
		if(!v[c].size()){
			cout<<-1<<'\n';
		   return ;
		}
		f(j,0,n+1){
			if(lst(v[c])<j)
				maxm(dp[i][j],dp[i-1][j])
			if(find(c,j))
				maxm(dp[i][find(c,j)],dp[i-1][j]+1);
		}
		v[c].pop_back();
	}
	cout<<n-dp[n][n]<<endl;
}

int main(){
	cin>>T;
	cop=T;
	while(T--)
		solve();
}