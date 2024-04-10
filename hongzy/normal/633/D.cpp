#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

const int N = 1010;

int n, ans = 2, a[N];
map<int, int> cnt;

void dfs(int u, int la, int now) {
	ans = max(ans, u);
	if(cnt[now]) {
		cnt[now] --;
		dfs(u + 1, now, now + la);
		cnt[now] ++;
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i); cnt[a[i]] ++;
	}

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) if(i != j) {
			if(a[i] == 0 && a[j] == 0) {
				ans = max(ans, cnt[0]);
				continue ;
			}
			cnt[a[i]] --; cnt[a[j]] --;
			dfs(2, a[j], a[i] + a[j]);
			cnt[a[i]] ++; cnt[a[j]] ++;
		}
	}
	printf("%d\n", ans);
	return 0;
}