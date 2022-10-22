#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
map<pii,int> mp;
int T,n,nxt[110000],p[110000];
bool vis[110000];
vector<int> vec[110000];
void rev(int x,int y,int i){
	if (!mp[pii(x,y)]){
		mp[pii(x,y)]=i;
		mp[pii(y,x)]=i;
	} else{
		vec[i].push_back(mp[pii(x,y)]);
		vec[mp[pii(x,y)]].push_back(i);
		mp[pii(x,y)]=0;
		mp[pii(y,x)]=0;
	}
	nxt[x]^=y; nxt[y]^=x;
}
void dfs(int u,int f){
	for (int v:vec[u]){
		if (v==f) continue;
		dfs(v,u);
	}
	printf("%d ",u);
}
void work(int u,int v){
	int cnt=0;
	vis[u]=true; p[++cnt]=u; printf("%d ",u);
	while (!vis[v]){
		vis[v]=true; p[++cnt]=v; printf("%d ",v);
		u^=nxt[v]; swap(u,v);
	}
	putchar('\n'); dfs(1,0); putchar('\n');
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n); mp.clear();
		int a,b,c;
		for (int i=1;i<=n-2;i++){
			scanf("%d%d%d",&a,&b,&c);
			rev(a,b,i); rev(a,c,i); rev(b,c,i);
		}
		int x,y;
		for (auto t:mp)
			if (t.second) x=t.first.first,y=t.first.second;
		work(x,y);
		for (int i=1;i<=n;i++) vis[i]=false,nxt[i]=0,vec[i].clear();
	}
	return 0;
}