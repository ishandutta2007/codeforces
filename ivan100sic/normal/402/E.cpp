#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[2005][2005];

int idx[2005], low[2005], t;
basic_string<int> st;
bool inst[2005];

void scc(int x) {
	idx[x] = low[x] = ++t;
	inst[x] = 1;
	st += x;
	for (int y=0; y<n; y++) {
		if (!a[x][y])
			continue;
		if (idx[y] == 0) {
			scc(y);
			low[x] = min(low[x], low[y]);
		} else if (inst[y]) {
			low[x] = min(low[x], idx[y]);
		}
	}
	if (idx[x] == low[x]) {
		cout << ((int)st.size() == n && st[0] == x ? "YES\n" : "NO\n");
		exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> a[i][j];
	scc(0);
}