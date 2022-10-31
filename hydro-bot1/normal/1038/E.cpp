// Hydro submission #6243a6a89fb50a4911f43909@1648600745749
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 105;
int n, deg[5], odd;
bool vis[5];
int sum, val[5], ans;
struct edge{
	int u, v, w;
}e[N];
int f[5];
int find(int x){
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}
void merge(int x, int y){
	x = find(x), y = find(y);
	f[x] = y;
}
bool check(){
	int f = find(1);
	if(find(2) != f || find(3) != f || find(4) != f) return false;
	return true;
}
int main(){
	for(int i = 1; i <= 4; i++) f[i] = i;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d",&e[i].u,&e[i].w,&e[i].v);
		deg[e[i].u]++, deg[e[i].v]++;
		merge(e[i].u, e[i].v);
		sum += e[i].w;
	}
	for(int i = 1; i <= n; i++) val[find(e[i].u)] += e[i].w;
	if(!check()){
		for(int i = 1; i <= 4; i++) ans = max(ans, val[find(i)]);
		printf("%d\n",ans);
		return 0;
	}
	for(int i = 1; i <= 4; i++) if(deg[i] & 1) odd++;
	if(!odd || odd == 2){
		printf("%d\n",sum);
		return 0;
	}
	for(int i = 1; i <= n; i++) if(e[i].u != e[i].v){
		for(int j = 1; j <= 4; j++) f[j] = j;
		for(int j = 1; j <= n; j++) if(j != i) merge(e[j].u, e[j].v);
		if(check()) ans = max(ans, sum - e[i].w);
	}
	printf("%d\n",ans);
	return 0;
}