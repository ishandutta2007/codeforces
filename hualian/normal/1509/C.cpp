#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e3+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int dp[N][N];
int a[N];
signed main(){
	int n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int len=0;len<n;len++){
		for(int l=1;l+len<=n;l++){
			int r=l+len;
			dp[l][r]=min(dp[l+1][r],dp[l][r-1])+a[r]-a[l];
		}
	}cout<<dp[1][n];
	return 0;
}