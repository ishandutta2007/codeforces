#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,a[20],x,y;
int f[20][20][20][20],fa[20][20][20][20];
vector<int> v;

int dp(int d,int h1,int h2,int h3){
	h1=max(h1,0);h2=max(h2,0);h3=max(h3,0);
	if(!h1){
		return (d==n)?0:dp(d+1,h2,h3,a[d+3]);
	}
	if(~f[d][h1][h2][h3]){return f[d][h1][h2][h3];}
	int res=114514;
	if(d!=1&&d!=n&&res>dp(d,h1-x,h2-y,h3)){res=dp(d,h1-x,h2-y,h3);fa[d][h1][h2][h3]=d;}
	if(d!=n-1&&res>dp(d,h1-y,h2-x,h3-y)){res=dp(d,h1-y,h2-x,h3-y);fa[d][h1][h2][h3]=d+1;}
	return f[d][h1][h2][h3]=res+1;
}

void dfs(int d,int h1,int h2,int h3){
	h1=max(h1,0);h2=max(h2,0);h3=max(h3,0);
	if(!h1){if(d!=n){dfs(d+1,h2,h3,a[d+3]);}return;}
	int k=fa[d][h1][h2][h3];
	printf("%d ",(k==n+1)?n-1:k);
	if(k==d){dfs(d,h1-x,h2-y,h3);}
	else{dfs(d,h1-y,h2-x,h3-y);}
}

int main(){
	memset(f,-1,sizeof(f));
	scanf("%d%d%d",&n,&x,&y);
	for(i=1;i<=n;i++){scanf("%d",&a[i]);a[i]++;}
	printf("%d\n",dp(1,a[1],a[2],a[3]));
	dfs(1,a[1],a[2],a[3]);
}