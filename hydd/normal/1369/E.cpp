#include<bits/stdc++.h>
using namespace std;
int n,m,w[210000],c[210000],top,s[210000];
int num[210000],ans,Ans[210000];
vector<int> vec[210000]; bool vis[210000];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]),c[i]=-c[i];
	int x,y;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y); num[i]=x^y;
		vec[x].push_back(i); c[x]++;
		vec[y].push_back(i); c[y]++;
	}
	for (int i=1;i<=n;i++)
		if (c[i]<=0) s[++top]=i;
	while (top){
		int u=s[top--];
		vis[u]=true;
		for (int v:vec[u])
			if (!vis[num[v]^u]){
				c[num[v]^u]--;
				if (c[num[v]^u]==0) s[++top]=(num[v]^u);
			} else Ans[++ans]=v;
	}
	if (ans!=m) puts("DEAD");
	else{
		puts("ALIVE");
		for (int i=m;i>=1;i--) printf("%d ",Ans[i]);
	}
	return 0;
}