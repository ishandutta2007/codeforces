#include <bits/stdc++.h>
#define maxn 10086
using namespace std;

struct Edge{
	int x, i;
};

vector<Edge> v[maxn];
int n, m;
int x, y;
int dep[maxn], a[maxn], id, cnt;
int eid[maxn];

void dfs(int i){
	for(int j = 0;j < v[i].size();j++){
		if(!dep[v[i][j].x]){
			dep[v[i][j].x] = dep[i] + 1;
			eid[v[i][j].x] = v[i][j].i;
			dfs(v[i][j].x);
			a[eid[i]] += a[eid[v[i][j].x]];
		}else{
			if(dep[v[i][j].x] + 1 >= dep[i]) continue;
			if((dep[i] - dep[v[i][j].x] + 1) & 1){
				cnt++;
				id = v[i][j].i;
				a[eid[i]]++, a[eid[v[i][j].x]]--;
			}else{
				a[eid[i]]--, a[eid[v[i][j].x]]++;
			}
		}
	}
	//printf("%d %d %d--\n", i, eid[i], a[eid[i]]);
	
}


int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= m;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back((Edge){y, i}), v[y].push_back((Edge){x, i});
	}
	for(int i = 1;i <= n;i++) if(!dep[i]) dep[i] = 1, dfs(i);
	if(!cnt){
		printf("%d\n", m);
		for(int i = 1;i <= m;i++) printf("%d ", i);
		return 0;
	}
	if(cnt == 1) a[id] = cnt;//debug:return   3 
	int ans = 0;
	for(int i = 1;i <= m;i++) if(a[i] == cnt) ans++;
	printf("%d\n", ans);
	for(int i = 1;i <= m;i++) if(a[i] == cnt) printf("%d ", i);
}