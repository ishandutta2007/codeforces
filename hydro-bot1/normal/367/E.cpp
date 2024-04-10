// Hydro submission #624db793fcdfb741b9e4762b@1649260435904
#include<bits/stdc++.h>
using namespace std;
#define maxn 200009
#define minn 325
const long long mod=1000000007;
int dp[maxn][minn];
int n,m,x;
int id(int i,int j){
	return i*(n+1)+j;
} 
inline int read(){
	int sum=0,fh=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')fh=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=c-'0';
		c=getchar();
	}
	return sum*fh;
}
int main(){
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
	n=read(),m=read(),x=read();
	if(n<=m){
		dp[id(0,0)][0]=1;
		for(int i=1;i<=m;i++){
			if(i!=x)dp[id(i,0)][0]=dp[id(i-1,0)][0];
			for(int j=1;j<=n;j++){
				if(i!=x)dp[id(i,j)][0]=(1ll*dp[id(i-1,j-1)][0]+dp[id(i-1,j)][0])%mod; 
				else dp[id(i,j)][0]=dp[id(i-1,j-1)][0]; 
				for(int k=1;k<=j;k++){
					if(i!=x){
						dp[id(i,j)][k]=(1ll*dp[id(i-1,j)][k]+dp[id(i-1,j-1)][k]+(dp[id(i-1,j)][k-1])+dp[id(i-1,j-1)][k-1])%mod;
					} 
					else{
						dp[id(i,j)][k]=(1ll*dp[id(i-1,j-1)][k]+dp[id(i-1,j-1)][k-1])%mod; 	
					}
				}
			}
		}
		long long ans=dp[id(m,n)][n];
		for(int i=1;i<=n;i++)ans=(ans*i)%mod;
		cout<<ans;
	}
	else{
		cout<<0;
	}
//	  fclose(stdin);
//    fclose(stdout);
	return 0;
}