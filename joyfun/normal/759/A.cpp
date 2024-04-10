#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 200005;
int n, p[N], b[N], vis[N];

int main() {
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]), sum += b[i];
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		int u = i;
		while (!vis[u]) {
			vis[u] = 1;
			u = p[u];
		}
		cnt++;
	}
	if (cnt == 1) cnt = 0;
	printf("%d\n", cnt + !(sum % 2));
	return 0;
}