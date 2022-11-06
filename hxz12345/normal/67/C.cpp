#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
int ti,tj,V1[4010][33],V2[4010][33],dp[4010][4010],A,n,m,i,j,B,C,D;
char S[10100],T[10100];
int main(){
	A=read();B=read();C=read();D=read();
	scanf("%s",S+1);scanf("%s",T+1);
	n=strlen(S+1);m=strlen(T+1);
	for (i=1;i<=n+1;i++){
		for (j=0;j<26;j++) V1[i][j]=V1[i-1][j];
		if (i>1) V1[i][S[i-1]-'a']=i-1;
	}
	for (i=1;i<=m+1;i++){
		for (j=0;j<26;j++) V2[i][j]=V2[i-1][j];
		if (i>1) V2[i][T[i-1]-'a']=i-1;
	}
	for (i=0;i<=n;i++)
	   for(j=0;j<=m;j++)
	      dp[i][j]=1e9;
		dp[0][0]=0;
	for (i=0;i<=n;i++)
	   for (j=0;j<=m;j++)
	       {
	       if ((S[i]==T[j])&&(i>0)&&(j>0)) dp[i][j]=dp[i-1][j-1];
	       else if ((i>0)&&(j>0))dp[i][j]=dp[i-1][j-1]+C;
	       if (i>0)dp[i][j]=min(dp[i][j],dp[i-1][j]+B);
	       if (j>0) dp[i][j]=min(dp[i][j],dp[i][j-1]+A);
	       if ((i>0)&&(j>0))
		     {
		   ti=V1[i][T[j]-'a'];
	          tj=V2[j][S[i]-'a'];
	          if ((ti>=1)&&(tj>=1))
	            dp[i][j]=min(dp[i][j],dp[ti-1][tj-1]+(i-ti-1)*B+(j-tj-1)*A+D);
	         }
	       }
	printf("%d\n",dp[n][m]);
	return 0;
}