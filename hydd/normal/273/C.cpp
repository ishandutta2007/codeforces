#include<bits/stdc++.h>
using namespace std;
int n,m,col[310000];
int head,tail,que[1210000];//n+3m
vector<int> vec[310000];
int main(){
	scanf("%d%d",&n,&m);
	int u,v,s;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	head=1; tail=0;
	for (int i=1;i<=n;i++){
		col[i]=0;
		que[++tail]=i;
	}
	while (head<=tail){
		u=que[head++]; s=0;
		for (int v:vec[u]) s+=(col[v]==col[u]);
		if (s>=2){
			col[u]^=1;
			for (int v:vec[u]) que[++tail]=v;
		}
	}
	for (int i=1;i<=n;i++) putchar(col[i]+'0');
	return 0;
}