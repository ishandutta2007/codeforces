#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,t,m,dp[300500],res,x,y;
vector<int> v[300500];

void dfs(int x,int fa){
	int tmp=0;
	if(v[x].size()==1&&x!=1){dp[x]=1;}
	for(auto i:v[x]){
		if(i==fa){continue;}
		dp[x]++;dfs(i,x);tmp=max(tmp,dp[i]);
	}
	dp[x]+=tmp;
}

void dfs2(int x,int fa,int fn){
	int m1,m2,n1,n2;
	m1=m2=n1=n2=0;
	for(auto i:v[x]){
		if(i==fa){continue;}
		if(dp[i]>m1){m2=m1;n2=n1;m1=dp[i];n1=i;}
		else{if(dp[i]>m2){m2=dp[i];n2=i;}}
	}
	if(x==1){res=max(res,dp[1]+m2-1+(m2==0));}
	else{res=max(res,dp[x]+max(fn,m2));}
	for(auto i:v[x]){
		if(i==fa){continue;}
		if(i==n1){dfs2(i,x,dp[x]-m1+max(m2,fn)-1);}
		else{dfs2(i,x,dp[x]-m1+max(m1,fn)-1);}
	}
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);res=0;
		for(i=1;i<=n;i++){v[i].clear();dp[i]=0;}
		for(i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		dfs2(1,0,0);
		printf("%d\n",res);
	}
}