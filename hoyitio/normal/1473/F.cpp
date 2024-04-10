#include<iostream>
#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;
const int maxn = 3e3 + 50;
const int inf = 0x3f3f3f3f;
struct node{
	int u,v,nxt;
	int f;
}e[maxn*400];
int cnt = 0;
int head[maxn];
void add(int u,int v,int f){
	e[cnt].u = u;
	e[cnt].v = v;
	e[cnt].f = f;
	e[cnt].nxt = head[u];
	head[u] = cnt++;

	e[cnt].u = v;
	e[cnt].v = u;
	e[cnt].f = 0;
	e[cnt].nxt = head[v];
	head[v] = cnt++;
}
int st,ed,ex;
int S = 0;
int a[maxn], b[maxn];
int n;
int last[maxn];

void init(){
    memset(head, -1, sizeof head);
    cnt = 0;
    cin>>n;
    st = 0; ed = n+1; ex = ed+1;
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
        if(b[i] > 0) add(st, i, b[i]), S += b[i];
        else add(i, ed, -b[i]);
    }
        for(int j = 1; j <= n; ++j){
            for(int x = 1; x*x <= a[j]; ++x){
                if(a[j]%x) continue;
                if(last[x])add(j, last[x], inf);
                if(last[a[j]/x]) add(j, last[a[j]/x], inf);
            }
            last[a[j]] = j;
        }
//    for(int i = n; i > 0; --i){
//        for(int j = 1; j < i; ++j) if(a[i]%a[j] == 0) add(i, j, inf);
//    }
}
int dep[maxn];
int q[maxn*2];
int tot,tail;
bool bfs(){
	memset(dep,-1,(ex+1)<<2);
	dep[st] = 1;
	q[tot = 0] = st,tail = 1;
	while(tot < tail){
		int u = q[tot++];
		if(u == ed) break;
		for(int i = head[u];~i;i = e[i].nxt){
			int v = e[i].v;
			if(dep[v]!=-1 || !e[i].f) continue;
			dep[v] = dep[u] + 1;
			q[tail++] = v;
		}
	}
	return dep[ed]!=-1;
}
int cur[maxn];
int dfs(int u,int flow){
	int res = flow;
	if(u == ed) return flow;
	for(int &i = cur[u];~i;i = e[i].nxt){
		int v = e[i].v;
		if(dep[v]!=dep[u] + 1 || !e[i].f) continue;
		int d = dfs(v,min(res,e[i].f));
		e[i].f -= d;
		e[i^1].f += d;
		res -= d;
		if(res == 0) break;
	}
	if(flow == res) dep[u] = -1;//
	return flow - res;
}
int dinic(){
	int ans = 0;
	int d;
	while(bfs()){
		for(int i = 0;i <= ex;++i) cur[i] = head[i];
		while(d = dfs(st,inf)) ans += d;
	}
	return ans;
}
void sol(){
    int ans = S-dinic();
	printf("%d\n",ans);
}
int main(){
    init();sol();
}