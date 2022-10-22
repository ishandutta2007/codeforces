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
ll t=1,n,e=11,dp[25][100];
string s1,s2;
int main(){
	dp[0][e]=1;
	cin>>s1>>s2;n=s1.size()+e;
	f(i,0,s1.size())
		n-=(s1[i]=='-')*2;
	f(i,0,s2.size()){
		t+=t*(s2[i]=='?');
		f(j,1,44){
			dp[i+1][j]=dp[i][j-1]*(s2[i]=='?' || s2[i]=='+');
			dp[i+1][j]+=dp[i][j+1]*(s2[i]=='?' || s2[i]=='-');
		}
	}

	double ans = (double) dp[s2.size()][n] / t;
	printf("%.10lf",(double)dp[s2.size()][n]/(double)t);
}