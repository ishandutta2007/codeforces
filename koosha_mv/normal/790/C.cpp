#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
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

const int N=77;
int v,k,n,e,l,r,mid,pv[N],pk[N],pe[N];
pair<int,int> dp[N][N][N];
string s;

int calcv(int x,int k1,int e1){
	int res;
	x=pv[x];
	l=0,r=k1+1;
	while(l+1<r){
		mid=(l+r)/2;
		if(pk[mid]<x) l=mid;
		else r=mid;
	}
	res=k1-l;
	
	l=0,r=e1+1;
	while(l+1<r){
		mid=(l+r)/2;
		if(pe[mid]<x) l=mid;
		else r=mid;
	}
	return res+(e1-l);
}
int calck(int x,int v1,int e1){
	int res;
	x=pk[x];
	l=0,r=v1+1;
	while(l+1<r){
		mid=(l+r)/2;
		if(pv[mid]<x) l=mid;
		else r=mid;
	}
	res=v1-l;
	
	l=0,r=e1+1;
	while(l+1<r){
		mid=(l+r)/2;
		if(pe[mid]<x) l=mid;
		else r=mid;
	}
	return res+(e1-l);
}
int calce(int x,int v1,int k1){
	int res;
	x=pe[x];
	l=0,r=k1+1;
	while(l+1<r){
		mid=(l+r)/2;
		if(pk[mid]<x) l=mid;
		else r=mid;
	}
	res=k1-l;
	
	l=0,r=v1+1;
	while(l+1<r){
		mid=(l+r)/2;
		if(pv[mid]<x) l=mid;
		else r=mid;
	}
	return res+(v1-l);
}

pair<int,int> solve(int a,int b,int c){
	if(dp[a][b][c].F>=0) return dp[a][b][c];
	dp[a][b][c].F=dp[a][b][c].S=N*N;
	if(a>0) minm(dp[a][b][c].F,solve(a-1,b,c).F+calcv(a,b,c));
	if(b>0) minm(dp[a][b][c].S,solve(a,b-1,c).S+calck(b,a,c));
	if(c>0) minm(dp[a][b][c].S,solve(a,b,c-1).F+calce(c,a,b));
	minm(dp[a][b][c].F,dp[a][b][c].S);
	return dp[a][b][c];
}

int main(){
	cin>>n;
	cin>>s;
	f(i,0,n){
		v+=(s[i]=='V');
		k+=(s[i]=='K');
		e+=(s[i]!='K' && s[i]!='V');
		if(s[i]=='V') pv[v]=i+1;
		if(s[i]=='K') pk[k]=i+1;
		if((s[i]!='V') && (s[i]!='K')) pe[e]=i+1;
	}
	f(i,0,N) f(j,0,N) f(l,0,N) dp[i][j][l].F=-1;
	dp[0][0][0].F=dp[0][0][0].S=0;
	cout<<solve(v,k,e).F;
}