#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, q;
int a[205][205], b[50005], c[50005];

int cycmask[50005], vis[50005], stackidx[50005], stk[50005], ss;
int p[1000005], last[10], k;

void dfs(int x) {
	int y = b[x];
	stk[ss] = x;
	stackidx[x] = ss++;
	vis[x] = 1;
	
	if (stackidx[y] != -1) {
		int mask = 0;
		for (int i=stackidx[y]; i<ss; i++)
			mask |= 1 << c[stk[i]];
		for (int i=stackidx[y]; i<ss; i++)
			cycmask[stk[i]] = mask;
	} else if (!vis[y]) {
		dfs(y);
	}

	stackidx[x] = -1;
	ss--;
}

int sol[50005];

void resi(int x) {
	if (cycmask[x]) {
		int h = -1;
		for (int i=0; i<10; i++)
			if (!(cycmask[x] & (1 << i)))
				h = max(h, last[i]);
		sol[x] = h+1;
	} else {
		int y = b[x];
		if (sol[y] == -1)
			resi(y);

		if (sol[y] == 0)
			sol[x] = 0;
		else {
			if (p[sol[y] - 1] == c[x]) {
				sol[x] = sol[y] - 1;
			} else {
				sol[x] = sol[y];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		for (int j=0; j<m; j++)
			a[i][j] = s[j] - '0';
	}

	{
		vector<int> b(10), c(10);
		for (int i=0; i<10; i++)
			cin >> b[i] >> c[i];
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				int x = i + b[a[i][j]];
				int y = j + c[a[i][j]];
				if (x < 0 || x >= n || y < 0 || y >= m) {
					x = i;
					y = j;
				}
				::b[i + n*j] = x + n*y;
				::c[i + n*j] = a[i][j];
			}
		}
	}

	// sredi graf
	fill(stackidx, stackidx+n*m, -1);
	for (int i=0; i<n*m; i++)
		if (!vis[i])
			dfs(i);

	while (q--) {
		string s;
		cin >> s;
		k = s.size();
		for (int i=0; i<k; i++)
			p[i] = s[i] - '0';
		fill(last, last+10, -1);
		for (int i=0; i<k; i++)
			last[p[i]] = i;

		fill(sol, sol+n*m, -1);
		for (int i=0; i<n*m; i++)
			if (sol[i] == -1)
				resi(i);
		cout << (count(sol, sol+n*m, 0) ? "YES\n" : "NO\n");
	}
}