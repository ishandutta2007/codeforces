#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int cnt,p[110000],lim;
unordered_set<int> vec[110000];
queue<int> que;
bool check(int u){
	int cnt=1; p[1]=u;
	for (int v:vec[u]) p[++cnt]=v;
	for (int i=1;i<=cnt;i++)
		for (int j=i+1;j<=cnt;j++)
			if (vec[p[i]].find(p[j])==vec[p[i]].end()) return false;
	return true;
}
void work(){
	while (!que.empty()) que.pop();
	for (int i=1;i<=n;i++)
		if ((int)vec[i].size()<k) que.push(i);
	while (!que.empty()){
		int u=que.front(); que.pop();
		if ((int)vec[u].size()==k-1&&1ll*k*(k-1)/2<=m&&check(u)){
			puts("2");
			for (int i=1;i<k;i++) printf("%d ",p[i]);
			printf("%d\n",p[k]);
			return;
		}
		for (int v:vec[u]){
			vec[v].erase(u);
			if ((int)vec[v].size()==k-1) que.push(v);
		}
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
		if ((int)vec[i].size()>=k) p[++cnt]=i;
	if (cnt){
		printf("1 %d\n",cnt);
		for (int i=1;i<cnt;i++) printf("%d ",p[i]);
		printf("%d\n",p[cnt]);
	} else puts("-1");
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&n,&m,&k);
		int u,v;
		for (int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			vec[u].insert(v); vec[v].insert(u);
		}
		work();
		for (int i=1;i<=n;i++) vec[i].clear();
	}
	return 0;
}