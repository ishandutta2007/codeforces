#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int M=100009;
int n,m;
char s[M],t[M];
int f[M],dp[M];
int main(){
	scanf("%s%s",t+1,s+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(int i=1,j=0;i<=n;f[++i]=++j)while(j&&s[i]!=s[j])j=f[j];
	for(int i=1,j=1;i<=m;++i,++j){
		while(j&&s[j]!=t[i])j=f[j];
		if(j!=i)dp[j+1]++;
		else dp[f[j+1]]++;
	}
	for(int i=n+1;i>=1;--i){
		dp[f[i]]+=dp[i];
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		ans+=m;
		if(f[i+1]>1)ans-=dp[i+1-f[i+1]+1];
	}
	printf("%lld\n",ans);
	return 0;
}
/*
8 10
1 3 2 7 8 2 5 4 6 1
*/