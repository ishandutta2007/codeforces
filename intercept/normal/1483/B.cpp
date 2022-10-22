#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=1e5+9; 
int n;
int a[M],nex[M];
bool vis[M];
vector<int>ans;
void work(){
	queue<int>q;
	scanf("%d",&n);
	ans.clear();
	for(int i=1;i<=n;++i){
		vis[i]=0;
		scanf("%d",&a[i]);
		if(i!=1&&__gcd(a[i],a[i-1])==1)q.push(i-1);
		nex[i]=i==n?1:i+1;
	}
	if(__gcd(a[1],a[n])==1)q.push(n);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		ans.eb(nex[u]);
		vis[nex[u]]=1;
		nex[u]=nex[nex[u]];
		if(__gcd(a[u],a[nex[u]])==1)q.push(u);
	}
	printf("%d ",ans.size());
	for(auto o:ans)printf("%d ",o);
	printf("\n");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/* 
1
5
5 9 2 10 15
*/