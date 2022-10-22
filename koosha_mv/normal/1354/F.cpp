#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=77,inf=-1e9;

int n,k,t,dp[N][N],par[N][N],mark[N];
pair<int,pair<int,int> > a[N];

int main(){
	cin>>t;
	f(q,0,t){
		fill(mark,mark+N,0);
		cin>>n>>k;
		f(i,1,n+1){ cin>>a[i].S.F>>a[i].F; a[i].S.S=i;};
		sort(a+1,a+n+1);
		f(i,1,n+1) dp[0][i]=inf;
		f(i,1,n+1){
			dp[i][0]=dp[i-1][0]+a[i].F*(k-1);
			f(j,1,k+1){
				par[i][j]=0;
				dp[i][j]=dp[i-1][j]+a[i].F*(k-1);
				if(dp[i][j]<dp[i-1][j-1]+a[i].S.F+a[i].F*(j-1)) dp[i][j]=dp[i-1][j-1]+a[i].S.F+a[i].F*(j-1),par[i][j]=1;
			}
		}
		cout<<n*2-k<<endl;
		int now=k;
		f_(i,n,1){
			if(par[i][now]) mark[i]=1,now--;
		}
		f(i,1,n+1){
			if(mark[i] && k>1){
				k--;
				cout<<a[i].S.S<<" ";
			}
		}
		f(i,1,n+1)
			if(!mark[i])
				cout<<a[i].S.S<<" "<<-a[i].S.S<<" ";
		f_(i,n,1)
			if(mark[i]){
				cout<<a[i].S.S<<endl;
				break;
			}
	}	
}