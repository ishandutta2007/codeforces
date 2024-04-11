#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=1005;
string s,t;
ll dp[N][N][11],g[N][N],sz1,sz2,k;
int main(){
	cin>>sz1>>sz2>>k>>s>>t;
	s=' '+s,t=' '+t;sz1++;sz2++;
	f(i,1,sz1){
		f(j,1,sz2)
			g[i][j]=(1+g[i-1][j-1])*(s[i]==t[j]);
	}
	f(i,1,sz1){
		f(j,1,sz2){
			f(l,1,k+1){
				dp[i][j][l]=max(max(dp[i-1][j][l],dp[i][j-1][l]),dp[i-g[i][j]][j-g[i][j]][l-1]+g[i][j]);
				if(l>0) maxm(dp[i][j][l],dp[i][j][l-1]);
			}
		}
	}
	cout<<dp[sz1-1][sz2-1][k];
}