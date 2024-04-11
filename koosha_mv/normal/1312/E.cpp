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
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1005;
int n,a[N],dp1[N][N],dp2[N][N];
int main(){
	cin>>n;
	f(i,0,n){cin>>a[i];}
	f(i,0,n) dp1[i][i]=1,dp2[i][i]=a[i];
	f(i,1,n){
		f_(j,i-1,0){
			dp1[j][i]=2e5+9;
			f(l,j,i){
				minm(dp1[j][i],dp1[j][l]+dp1[l+1][i]);
				if(dp2[j][l]==dp2[l+1][i] && dp2[j][l]!=0){
					dp1[j][i]=1;
					dp2[j][i]=dp2[j][l]+1;
				}
			}
		}
	}
	cout<<dp1[0][n-1];
}