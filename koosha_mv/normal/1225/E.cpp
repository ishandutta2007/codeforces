#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(1ll*a,1ll*b);
#define minm(a,b) a=min(1ll*a,1ll*b);
#define S second
#define F first
const int N=2020,mod=1e9+7;
// 1 : az bala 2 : az az chap # c[0]=row c[1]=col
int n,m,dp1[N][N],dp2[N][N],mv1[N][N],mv2[N][N],c[2][N][N],l,r,mid,sfr,p;
char mp[N][N];
int binary_search(int src,int x,int an){
	l=0;
	if(src==0) r=m+1;
	else r=n+1;
	while(l+1<r){
		mid=(l+r)/2;
		if(c[src][an][mid]<=x)
			r=mid;
		else l=mid;
	}
	return max(l-1,sfr);
}
int main(){
	Gett(n,m);
	f(i,1,n+1){
		f(j,1,m+1)
			cin>>mp[i][j];
	}
	f(i,1,n+1){
		f_(j,m,1)
			c[0][i][j]=c[0][i][j+1]+(mp[i][j]=='R');
	}
	f(i,1,m+1){
		f_(j,n,1)
			c[1][i][j]=c[1][i][j+1]+(mp[j][i]=='R');
	}
	mv1[1][1]=mv2[1][1]=dp1[1][1]=dp2[1][1]=1;
	f(i,1,n+1){
		f(j,1,m+1){
			if(i!=1 || j!=1){
			p=binary_search(1,n-i,j);
			dp1[i][j]=(mv2[i-1][j]+mod-mv2[p][j])%mod;
			mv1[i][j]=(mv1[i][j-1]+dp1[i][j])%mod;
			p=binary_search(0,m-j,i);
			dp2[i][j]=(mv1[i][j-1]+mod-mv1[i][p])%mod;
			mv2[i][j]=(mv2[i-1][j]+dp2[i][j])%mod;
			}	
		}
	}
	if(n==1 && m==1){
		cout<<1;return 0;
	}
	cout<<(dp1[n][m]+dp2[n][m])%mod;
}