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

const int N = 30;
int n, c[N];

bool dfs(int s, int u, int sum, int sb) {
	if (u == n) return s == (1<<(n - 1));
	for (int i = sb; i >= 0; i--) {
		if (s>>i&1) {
			if (sum + c[i] < c[u]) {
				if (sum + c[i] + 1 < c[u]) {
					if (dfs(s^(1<<i), u, sum + c[i], i - 1)) return true;
				}
				else {
					if (sum && dfs(s^(1<<i)^(1<<u), u + 1, 0, u)) return true;
				}
			}

		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);
	sort(c + 0, c + n);
	int f = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] > 1) {
			f = dfs((1<<i) - 1, i, 0, i - 1);
			break;
		}
	}
	if (n == 1 && c[n - 1] == 1) f = 1;
	printf("%s\n", f ? "YES" : "NO");
	return 0;
}