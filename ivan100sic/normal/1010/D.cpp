#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 1000005; // ja sam

int n;
string tip[N];
int rez[N], lc[N], rc[N];
bool lf[N], rf[N], f[N];
 
// racunaj i postavi grane
void dfs1(int x) {
	if (tip[x] == "IN")
		return;
	else if (tip[x] == "NOT") {
		dfs1(lc[x]);
		rez[x] = 1 ^ rez[lc[x]];
		lf[x] = 1;
	} else {
		int u = lc[x];
		int v = rc[x];
		dfs1(u);
		dfs1(v);
		if (tip[x] == "AND") {
			rez[x] = rez[u] & rez[v];
			if (rez[u] == 0 && rez[v] == 1)
				lf[x] = 1;
			else if (rez[u] == 1 && rez[v] == 0)
				rf[x] = 1;
			else if (rez[x] == 1)
				lf[x] = rf[x] = 1;
		} else if (tip[x] == "OR") {
			rez[x] = rez[u] | rez[v];
			if (rez[x] == 0)
				lf[x] = rf[x] = 1;
			else if (rez[u] == 0 && rez[v] == 1)
				rf[x] = 1;
			else if (rez[u] == 1 && rez[v] == 0)
				lf[x] = 1;
		} else if (tip[x] == "XOR") {
			rez[x] = rez[u] ^ rez[v];
			lf[x] = rf[x] = 1;
		}
	}
}
 
void dfs2(int x) {
	f[x] = 1;
	if (lf[x])
		dfs2(lc[x]);
	if (rf[x])
		dfs2(rc[x]);
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
 
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> tip[i];
		if (tip[i] == "AND") {
			cin >> lc[i] >> rc[i];
		} else if (tip[i] == "OR") {
			cin >> lc[i] >> rc[i];
		} else if (tip[i] == "XOR") {
			cin >> lc[i] >> rc[i];
		} else if (tip[i] == "NOT") {
			cin >> lc[i];
		} else {
			cin >> rez[i];
		}
	}
 
	dfs1(1);
	dfs2(1);
	for (int i=1; i<=n; i++)
		if (tip[i] == "IN")
			cout << ((int)f[i] ^ rez[1]);
	cout << '\n';
 
}