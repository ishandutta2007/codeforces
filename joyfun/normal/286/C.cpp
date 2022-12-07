#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 1000005;
int n, p[N], vis[N];
int st[N], top;
int ans[N], tmp[N];

bool go(int x) {
	while (top && p[st[top - 1]] != x) {
		ans[st[top - 1]] = 1;
		int x = p[st[--top]];
		if (!go(x)) return false;
	}
	if (!top) return false;
	top--;
	return true;
}

int main() {
	scanf("%d", &n); for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	int t, q;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &q);
		vis[q] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) st[top++] = i;
		else {
			ans[i] = 1;
			if (!go(p[i])) {
				printf("NO\n");
				return 0;
			}
		}
	}
	while (top) {
		ans[st[top - 1]] = 1;
		int x = p[st[--top]];
		if (!go(x)) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++) if (!ans[i]) printf("%d ", p[i]); else printf("%d ", -p[i]);
	return 0;
}