#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
#define ops cout<<"!"<<endl;
const int N=51;
int n,dp[N][N][N][N];
string s[N];
int solve(int a,int b,int c,int d){
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	if(dp[a][b][c][d]>=0) return dp[a][b][c][d];
	if(a==c && b==d){
		if(s[a][b]=='#') return 1;
		return 0;
	}
	dp[a][b][c][d]=max(d-b,c-a)+1;
	if(d-b>c-a){
		f(j,b,d)
			minm(dp[a][b][c][d],solve(a,b,c,j)+solve(a,j+1,c,d));
	}
	else{
		f(j,a,c)
			minm(dp[a][b][c][d],solve(a,b,j,d)+solve(j+1,b,c,d));
	}
	return dp[a][b][c][d];
}
int main(){
	f(i,0,N) f(j,0,N) f(salam,0,N) f(khodafez,0,N) dp[i][j][salam][khodafez]=-1;
	cin>>n;
	f(i,1,n+1){
		cin>>s[i];
		s[i]=' '+s[i];
	}
	cout<<solve(1,1,n,n);
}