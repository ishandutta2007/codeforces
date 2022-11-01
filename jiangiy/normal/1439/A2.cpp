#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=110;
int n,m,ac,ans[N*N*6];
char s[N][N];
void add(int a,int b,int c,int d,int e,int f){
	ans[ac++]=a;
	ans[ac++]=b;
	s[a][b]^=1;
	ans[ac++]=c;
	ans[ac++]=d;
	s[c][d]^=1;
	ans[ac++]=e;
	ans[ac++]=f;
	s[e][f]^=1;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)s[i][j]=s[i][j]=='1';
		for(int i=1;i<=n-2;i++) for(int j=1;j<=m;j++){
			if(s[i][j]){
				if(j==m)add(i,j,i+1,j-1,i+1,j);
				else add(i,j,i+1,j,i+1,j+1);
			}
		}
		for(int i=1;i<=m-2;i++){
			if(s[n-1][i]&&s[n][i])add(n-1,i,n,i,n,i+1);
			else if(s[n-1][i])add(n-1,i,n,i+1,n-1,i+1);
			else if(s[n][i])add(n,i,n,i+1,n-1,i+1);
		}
		int mask=(s[n-1][m-1]?14:0)^(s[n-1][m]?13:0)^(s[n][m-1]?11:0)^(s[n][m]?7:0);
		if(mask&1)add(n-1,m,n,m-1,n,m);
		if(mask&2)add(n-1,m-1,n,m-1,n,m);
		if(mask&4)add(n-1,m-1,n-1,m,n,m);
		if(mask&8)add(n-1,m-1,n-1,m,n,m-1);
		printf("%d\n",ac/6);
		for(int i=0;i<ac;i+=6){
			for(int j=0;j<6;j++)printf("%d ",ans[i+j]);
			puts("");
		}
		ac=0;
	}
}