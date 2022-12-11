#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
 
#define out() return puts("-1"), 0;
 
const int N = 3e5 + 10;
 
int n, m, bel[N];
vector<int> G[N];
 
int main() {
	scanf("%d%d", &n, &m); int mm = m;
	while(m --) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	static bool vis[N];
	for(int v : G[1]) {
		vis[v] = 1;
	}
	for(int i = 1; i <= n; i ++) if(!vis[i]) {
		bel[i] = 1;
	}
	int s = -1;
	for(int i = 1; i <= n; i ++) {
		if(!bel[i]) {
			s = i;
		}
	}
	if(s == -1) out();
	for(int i = 1; i <= n; i ++) vis[i] = 0;
	for(int v : G[s]) {
		vis[v] = 1;
	}
	for(int i = 1; i <= n; i ++) if(!vis[i]) {
		if(bel[i]) out();
		bel[i] = 2;
	}
	s = -1;
	for(int i = 1; i <= n; i ++) {
		if(!bel[i]) {
			s = i;
		}
	}
	if(s == -1) out();
	for(int i = 1; i <= n; i ++) vis[i] = 0;
	for(int v : G[s]) {
		vis[v] = 1;
	}
	for(int i = 1; i <= n; i ++) if(!vis[i]) {
		if(bel[i]) out();
		bel[i] = 3;
	}
	long long cnt[5] = {0};
	for(int i = 1; i <= n; i ++) if(!bel[i]) out();
	for(int i = 1; i <= n; i ++) cnt[bel[i]] ++;
	if(mm != cnt[3] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[3]) out();
	for(int i = 1; i <= n; i ++) for(int j : G[i]) if(bel[j] == bel[i]) out();
	for(int i = 1; i <= n; i ++) printf("%d ", bel[i]);
	return 0;
}