#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int n,m;
char ans[25][25];
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&m);
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
			if((i==1||i==n)||(j==1||j==m)) if(!ans[i-1][j-1]&&!ans[i-1][j]&&!ans[i-1][j+1]&&!ans[i][j-1])ans[i][j]=1;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)ans[i][j]+=48;
		for(int i=1;i<=n;i++)puts(ans[i]+1);
		puts("");
	}
}