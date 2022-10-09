#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MAXN = 1 << 22;
int n, m;
int a[MAXN];
bool ima[MAXN], vis[3*MAXN];

void dfs(int x) {
	if (x < MAXN && !ima[x])
		return;
	if (vis[x])
		return;
	vis[x] = 1;
	if (x < MAXN) {
		dfs(x+MAXN);
	} else if (x < 2*MAXN) {
		for (int i=0; i<22; i++) {
			int y = x | (1 << i);
			dfs(y);
		}
		dfs((1<<22)-1-(x-MAXN) + 2*MAXN);
	} else {
		for (int i=0; i<22; i++) {
			if (x & (1 << i))
				dfs(x - (1 << i));
		}
		dfs(x-2*MAXN);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> m >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		ima[a[i]] = 1;
	}
	int z = 0;
	for (int i=0; i<n; i++) {
		if (!vis[a[i]]) {
			dfs(a[i]);
			z++;
		}
	}
	cout << z << '\n';
}