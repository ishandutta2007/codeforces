#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
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

const int N=12005,e=6002;

int n,t,a[N],dp[2][N];

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		f(i,1,n*2+1) gett(a[i]);
		a[2*n+1]=N;
		f(i,0,N) dp[0][i]=-1,dp[1][i]=0;
		dp[0][0]=0;
		f(i,1,2*n+1){
			int p;
			for(p=i;a[p]<a[i+1] && p;p--){}
			f(j,0,N){
				if((-i)<=j-e && j-e<=i)
					dp[1][j]=(dp[0][i-(j-e)]>=p);
				else
					dp[1][j]=0;
			}
			f(j,0,N)
				if(dp[1][j] && i+j-e>=0 && i+j-e<N)
					dp[0][i+j-e]=i;
		}
		cout<<(dp[1][e] ? "YES" : "NO" )<<endl;
	}
}