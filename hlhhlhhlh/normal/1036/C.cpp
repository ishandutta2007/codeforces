// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int i,j,k;
int T,opt;
long long x,y,ans1,ans2,dp[25][5][2],a[maxn];
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
long long work(long long n){
	long long i,j,k,ans=0,r=0;
	if (n<1) return 0;
	memset(dp,0,sizeof(dp));
	while (n!=0){
		r++; a[r]=n%10; n=n/10;
	}
	for (i=1;i<=r/2;i++) swap(a[i],a[r-i+1]);
	dp[0][0][0]=1;
	for (i=0;i<=r;i++){
		for (j=0;j<=3;j++){
			if (i==r){
				ans=ans+dp[i][j][0]+dp[i][j][1];
			}
			if (i==r) continue;
			for (k=0;k<=9;k++){
				if (j+(k!=0)<=3){
					dp[i+1][j+(k!=0)][1]+=dp[i][j][1];
					if (k==a[i+1]) dp[i+1][j+(k!=0)][0]+=dp[i][j][0];
					if (k<a[i+1]) dp[i+1][j+(k!=0)][1]+=dp[i][j][0];
				}
			}
		}
	}
	if (ans>0) ans--;
	return ans;
}
int main(){
	T=read();
	for (opt=1;opt<=T;opt++){
		x=read(); y=read();
		ans1=work(x-1); ans2=work(y);
		printf("%I64d\n",ans2-ans1);
	}
	return 0;
}