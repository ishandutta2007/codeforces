#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s[55];
bool vis1[55][55], vis2[55][55];
int r1, c1, r2, c2;

template<class T>
void bfs(int x, int y, T v) {
	queue<pair<int, int>> q;
	q.push({x, y});
	v[x][y] = 1;
	
	auto go = [&](int p, int r) {
		if (p < 0 || r < 0 || p >= n || r >= n)
			return;
		if (s[p][r] == '1' || v[p][r])
			return;
		q.push({p, r});
		v[p][r] = 1;
	};

	while (q.size()) {
		auto [p, r] = q.front(); q.pop();
		go(p+1, r);
		go(p, r+1);
		go(p-1, r);
		go(p, r-1);
	}
}

int kv(int x) {
	return x*x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;
	for (int i=0; i<n; i++)
		cin >> s[i];

	r1--, c1--, r2--, c2--;

	bfs(r1, c1, vis1);
	bfs(r2, c2, vis2);

	int sol = 123123123;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) if (vis1[i][j])
			for (int k=0; k<n; k++)
				for (int l=0; l<n; l++) if (vis2[k][l])
					sol = min(sol, kv(i-k) + kv(j-l));

	cout << sol << '\n';
}