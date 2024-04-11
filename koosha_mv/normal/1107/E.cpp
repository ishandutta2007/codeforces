#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=105;
ll n,dp[N][N],a[N],p[N],dp2[N][N][N];
string s;
int main(){
	f(i,0,N) f(j,0,N) f(l,0,N) dp2[i][j][l]=-1e18;
	f(i,0,N) dp2[i][i][1]=0;
	cin>>n>>s;
	f(i,1,n+1){ get(a[i]); dp[i-1][i-1]=a[1]; }
	
	f(i,1,n){
		f_(j,i-1,0){
			if(s[j]==s[i]){
				f(l,j+1,i+1){
					f(k,2,N){
						maxm(dp2[i][j][k],dp2[i][l][k-1]+dp[j+1][l-1]);
					}
				}
				f(k,2,N)
					maxm(dp[j][i],dp2[i][j][k]+a[k]);
			}
			f(l,j,i)
				maxm(dp[j][i],dp[j][l]+dp[l+1][i]);
		}
	}
	cout<<dp[0][n-1];
}