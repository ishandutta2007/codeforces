#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char name[2][35];
int cnt[2][105], vis[2][105];

struct Q {
	int a, b;
	char aa[2], bb[2];
	void read() {
		scanf("%d%s%d%s", &a, aa, &b, bb);
	}
} q[105];

bool cmp(Q a, Q b) {
	return a.a < b.a;
}

int main() {
	scanf("%s%s", name[0], name[1]);
	int tot;
	scanf("%d", &tot);
	for (int i = 0; i < tot; i++)
		q[i].read();
	sort(q, q + tot, cmp);
	int a, b;
	char aa[5], bb[5];
	for (int i = 0; i < tot; i++) {
		a = q[i].a; b = q[i].b;
		aa[0] = q[i].aa[0]; bb[0] = q[i].bb[0];
		int v;
		if (aa[0] == 'a') v = 1;
		else v = 0;
		if (vis[v][q[i].b]) continue;
		if (bb[0] == 'r') {
			vis[v][q[i].b] = 1;
			printf("%s %d %d\n", name[v], b, a);
		} else {
			if (cnt[v][b]) {
				vis[v][q[i].b] = 1;
				printf("%s %d %d\n", name[v], b, a);
			} else {
				cnt[v][b] = 1;
			}
		}
	}
	return 0;
}