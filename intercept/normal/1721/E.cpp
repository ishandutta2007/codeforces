#include<bits/stdc++.h>
using namespace std;
const int M=1e6+109;
int n,m,q;
int f[M],dp[M][26];
char s[M],t[11];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int j=0;
	for(int i=1;i<=n;++i,++j){
		for(int k=0;k<26;++k)dp[i][k]=dp[j][k];
		dp[i][s[i]-'a']=i;
		j=dp[j][s[i]-'a'];
	}
	int now=j;
	scanf("%d",&q);
	for(int o=1;o<=q;++o){
		scanf("%s",t+1);
		m=strlen(t+1);
		j=now;
		for(int i=n+1;i<=n+m;++i,++j){
			for(int k=0;k<26;++k)dp[i][k]=dp[j][k];
			dp[i][t[i-n]-'a']=i;
			j=dp[j][t[i-n]-'a'];
			printf("%d%c",j," \n"[i==n+m]);
		}
	}
	return 0;
}