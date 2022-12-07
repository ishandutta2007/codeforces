#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 100005;
const int INF = 1100000000;

int n, m, w;
int a[N], tmp[N];

bool judge(int h) {
	int cnt = 0;
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < n; i++) {
		if (i) tmp[i] += tmp[i - 1];
		if (a[i] + tmp[i] < h) {
			int add = h - tmp[i] - a[i];
			cnt += add;
			tmp[i] += add;
			tmp[min(i + w, n)] -= add;
		}
		if (cnt > m) return false;
	}
	return true;
}

int solve() {
	int l = 0, r = INF;
	while (l < r) {
		int mid = (l + r) / 2;
		if (judge(mid)) l = mid + 1;
		else r = mid;
 	}
 	return l - 1;
}

int main() {
	scanf("%d%d%d", &n, &m, &w);
 	for (int i = 0; i < n; i++)
  		scanf("%d", &a[i]);
	printf("%d\n", solve());
	return 0;
}