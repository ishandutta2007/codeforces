#include<bits/stdc++.h>
const int MAXN=200,P=10007,MAXS=MAXN*2;
int m,n,sz;
char s[MAXN+5];
int dp[MAXN+5][MAXN+5][MAXN+5],cnt[MAXN+5];
int a[MAXS+5][MAXS+5],b[MAXS+5][MAXS+5],g[MAXS+5][MAXS+5];
int ans;
void work(){
	memset(dp,0,sizeof(dp));
	memset(cnt,0,sizeof(cnt));
	dp[1][m][0]=1;
	for(int i=1;i<=m;++i)
		for(int j=m;j>=i;--j)
			for(int k=0;k<=m-1;++k)
				if(s[i]==s[j])
					if(j-i<=1)
						cnt[k]=(cnt[k]+dp[i][j][k])%P;
					else
						dp[i+1][j-1][k]=(dp[i+1][j-1][k]+dp[i][j][k])%P;
				else{
					dp[i+1][j][k+1]=(dp[i+1][j][k+1]+dp[i][j][k])%P;
					dp[i][j-1][k+1]=(dp[i][j-1][k+1]+dp[i][j][k])%P;
				}
}
void work1(){
	memset(dp,0,sizeof(dp));
	memset(cnt,0,sizeof(cnt));
	dp[1][m][0]=1;
	for(int i=1;i<=m;++i)
		for(int j=m;j>=i;--j)
			for(int k=0;k<=m-1;++k)
				if(s[i]==s[j]){
					if(j-i==1)
						cnt[k]=(cnt[k]+dp[i][j][k])%P;
					else if(j-i>1)
						dp[i+1][j-1][k]=(dp[i+1][j-1][k]+dp[i][j][k])%P;
				}else{
					dp[i+1][j][k+1]=(dp[i+1][j][k+1]+dp[i][j][k])%P;
					dp[i][j-1][k+1]=(dp[i][j-1][k+1]+dp[i][j][k])%P;
				}
}
void build(){
	sz=m-1+(m+1)/2*2;
	for(int i=1;i<=m-1;++i){
		a[i][i]=24;
		a[i][i+1]=1;
	}
	for(int i=m;i<=m+(m+1)/2-1;++i){
		a[i][i]=25;
		if(i!=m+(m+1)/2-1)
			a[i][i+1]=1;
		a[i][i+(m+1)/2]=1;
	}
	for(int i=m+(m+1)/2;i<=sz;++i)
		a[i][i]=26;
}
void mul(int a[MAXS+5][MAXS+5],int b[MAXS+5][MAXS+5]){
	static int c[MAXS+5][MAXS+5];
	for(int i=1;i<=sz;++i)
		for(int j=i;j<=sz;++j){
			c[i][j]=0;
			for(int k=i;k<=j;++k)
				c[i][j]=(c[i][j]+a[i][k]*b[k][j])%P;
		}
	for(int i=1;i<=sz;++i)
		for(int j=i;j<=sz;++j)
			a[i][j]=c[i][j];
}
void calc(int n){
	for(int i=1;i<=sz;++i)
		for(int j=1;j<=sz;++j)
			b[i][j]=i==j;
	for(int i=1;i<=sz;++i)
		for(int j=1;j<=sz;++j)
			g[i][j]=a[i][j];
	while(n){
		if(n&1)
			mul(b,g);
		mul(g,g);
		n>>=1;
	}
}
int main(){
	scanf("%s",s+1);
	scanf("%d",&n);
	m=strlen(s+1);
	build();
	if((m+n)&1){
		work1();
		calc((n+m)/2);
		for(int i=0;i<=m-1;++i)
			ans=(ans-cnt[i]*b[m-i][m+(m-i+1)/2-1]+P)%P;
	}
	work();
	if((n+m)&1)
		mul(b,a);
	else
		calc((n+m+1)/2);
	for(int i=0;i<=m-1;++i)
		ans=(ans+cnt[i]*b[m-i][m+(m-i+1)/2+(m+1)/2-1])%P;
	printf("%d\n",ans);
	return 0;
}