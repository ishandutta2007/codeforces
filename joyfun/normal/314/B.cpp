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

const int N = 105;
int b, d;
char a[N], c[N];
int n, m, to[N];

int main() {
	scanf("%d%d", &b, &d);
	scanf("%s%s", a, c);
	n = strlen(a); m = strlen(c);
	for (int i = 0; i < m; i++) {
		int x = 0;
		for (int j = 0; j < n; j++) {
			if (c[(x + i) % m] != a[j]) continue;
			x++;
		}
		to[i] = x;
	}
	int u = 0;
	ll ans = 0;
	for (int i = 0; i < b; i++) {
		ans += to[u];
		u = (u + to[u]) % m;
	}
	printf("%lld\n", ans / m / d);
	return 0;
}