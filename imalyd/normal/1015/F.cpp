#include<bits/stdc++.h>
using namespace std;
const int N=205,p=1000000007;
int n,m,s[N],ch[N][2],f[N],dp[N][N][N];
char str[N];
void add(int &a,int b){a+=b;if(p<=a)a-=p;}
int main(){
	scanf("%d%s",&n,str),m=strlen(str);
	for(int i=0;i<m;i++)if(str[i]=='(')s[i+1]=1;
	ch[m][0]=ch[m][1]=m;
	for(int i=2,j=0;i<m;i++){
		while(j&&s[j+1]!=s[i])j=f[j];
		if(s[j+1]==s[i])f[i]=++j;
	}
	for(int i=0;i<m;i++){
		int f0=i;
		while(f0&&s[f0+1]!=0)f0=f[f0];
		if(s[f0+1]==0)ch[i][0]=++f0;
		int f1=i;
		while(f1&&s[f1+1]!=1)f1=f[f1];
		if(s[f1+1]==1)ch[i][1]=++f1;
	}
	//for(int i=0;i<=m;i++)printf("%d %d %d\n",i,ch[i][0],ch[i][1]);
	dp[n<<1][0][m]=1;
	for(int i=(n<<1)-1;~i;i--)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=m;k++){
				if( j)add(dp[i][j][k],dp[i+1][j -1][ch[k][0]]);
				if(1)add(dp[i][j][k],dp[i+1][j+1][ch[k][1]]);
			}
	printf("%d",dp[0][0][0]);
	return 0;
}