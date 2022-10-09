#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int cena[100005];
basic_string<int> e[100005], st;
int idx[100005], low[100005], t;
bool inst[100005];

ll pare = 0;
int ways = 1;
const int mod = 1'000'000'007;

void dfs(int x) {
	idx[x] = low[x] = ++t;
	st += x;
	inst[x] = true;

	for (int y : e[x]) {
		if (idx[y] == 0) {
			dfs(y);
			low[x] = min(low[x], low[y]);
		} else if (inst[y]) {
			low[x] = min(low[x], idx[y]);
		}
	}

	if (low[x] == idx[x]) {

		int val = 1123123123, cnt = 0;

		while (1) {
			int z = st.back();
			st.pop_back();
			inst[z] = false;

			if (cena[z] < val) {
				val = cena[z];
				cnt = 1;
			} else if (cena[z] == val) {
				cnt++;
			}

			if (z == x) {
				break;
			}
		}

		pare += val;
		ways = ways * 1ll * cnt % mod;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> cena[i];
	int m;
	cin >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
	}
	for (int i=1; i<=n; i++) {
		if (idx[i] == 0) {
			dfs(i);
		}
	}
	cout << pare << ' ' << ways << '\n';
}