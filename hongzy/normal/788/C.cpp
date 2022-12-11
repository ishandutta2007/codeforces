#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1010;

int n, k, q[2 * N], dis[2 * N];
bool ans[N];

int main() {
	scanf("%d%d", &n, &k);
	while(k --) { int u; scanf("%d", &u); ans[u] = 1; }
	fill(dis, dis + 2 * N, -1);
	int hd = 0, bk = 0;
	for(int i = 0; i <= 1000; i ++) if(ans[i]) {
		q[bk ++] = i - n; dis[i - n + 1000] = 1;
	}
	while(hd < bk) {
		int u = q[hd ++];
		for(int i = 0; i <= 1000; i ++) if(ans[i]) {
			int v = u + i - n;
			if(-1000 <= v && v <= 1000 && -1 == dis[v + 1000]) {
				dis[v + 1000] = dis[u + 1000] + 1;
				q[bk ++] = v;
			}
		}
	}
	printf("%d\n", dis[1000]);
	return 0;
}