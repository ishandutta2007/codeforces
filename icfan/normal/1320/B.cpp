#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=200000;
const int Maxm=200000;
const int Inf=0x3f3f3f3f;
int n,m;
int head[Maxn+5],arrive[Maxm+5],nxt[Maxm+5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int dis[Maxn+5];
int num;
int p[Maxn+5];
bool vis[Maxn+5];
int sho[Maxn+5];
bool is_sho[Maxm+5];
void bfs(int s){
	queue<int> q;
	memset(dis,0x3f,sizeof dis);
	q.push(s);
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(dis[v]!=Inf){
				continue;
			}
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
}
map<pair<int,int>,int> mp;
int main(){
	read(n),read(m);
	int u,v,w;
	for(int i=1;i<=m;i++){
		read(u),read(v);
		add_edge(v,u);
		mp[make_pair(u,v)]=tot;
	}
	read(num);
	for(int i=1;i<=num;i++){
		read(p[i]);
	}
	bfs(p[num]);
	queue<int> q;
	q.push(p[num]);
	sho[p[num]]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(dis[u]+1==dis[v]){
				if(sho[u]){
					sho[v]++;
					is_sho[i]=1;
				}
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	int ans_1=0,ans_2=0;
	for(int i=1;i<num;i++){
		if(is_sho[mp[make_pair(p[i],p[i+1])]]){
			if(sho[p[i]]>=2){
				ans_2++;
			}
		}
		else{
			ans_1++;
			ans_2++;
		}
	}
	printf("%d %d\n",ans_1,ans_2);
	return 0;
}