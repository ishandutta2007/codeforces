#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int N = 100005;
const int INF = 0x3f3f3f3f;
int n, h[N], Max[N], Min[N];

int main() {
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++)
			scanf("%d", &h[i]);
		Max[n + 1] = 0; Min[n + 1] = INF;
		for (int i = n; i >= 1; i--) {
			Max[i] = max(Max[i + 1], h[i]);
			Min[i] = min(Min[i + 1], h[i]);
		}
		int mi = INF, ma = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			ma = max(ma, h[i]);
			mi = min(mi, h[i]);
			if (ma <= Min[i + 1]) {
				cnt++;
				mi = INF;
				ma = 0;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}