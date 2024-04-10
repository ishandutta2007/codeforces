#include<bits/stdc++.h>
using namespace std;
const int N=2005;
char c[N];
const int mod=1e6+3;
int inv[N];
long long dp[N][N];
vector<int>v;
int n;
int qp(int x,int n){int ans=1;for(;n;n>>=1,x=1LL*x*x%mod)if(n&1)ans=1LL*ans*x%mod;return ans;}
int main(){
	scanf("%s",c);
	n=strlen(c);
	for(int i=-1;i+1<n;++i){
		if(!~i||c[i]<48||c[i]>57){
			if(c[i+1]=='*'||c[i+1]=='/'){
				return puts("0");
			}
		}
	}
	if(c[n-1]<48||c[n-1]>57)return puts("0");
	int tmp=0;
	for(int i=0;i<n;++i){
		if(c[i]<48||c[i]>57)++tmp;
		else if(tmp||!i){
			v.push_back(tmp-1);
			tmp=0;
		}
	}++v[0];
	for(int i=1;i<N;++i)inv[i]=qp(i,mod-2);
	int m=v.size();
	dp[0][1]=1;
	for(int i=0;i<m;++i){
		dp[i][0]=0;
		for(int j=1;j<=m;++j)dp[i][j]%=mod;
		int comb=1;
		for(int j=0;j<=m;++j){
			if(j)comb=1LL*comb*(j+v[i])%mod*inv[j]%mod;
			for(int k=j?0:1;k+j-1<=m-i-1;++k){
				dp[i+1][j+k-1]+=1LL*dp[i][k]*comb;
			}
		}
	}
	printf("%d\n",dp[m][0]);
	return 0;
}