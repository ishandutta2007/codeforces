#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	int x, y;
};

int n, m, p;
int speed[10];
string a[1005];
basic_string<pt> front[10];

char& A(pt b) {
	return a[b.x][b.y];
}

bool in(pt b) {
	return b.x >= 0 && b.x < n && b.y >= 0 && b.y < m;
}

basic_string<pt> expand_once(basic_string<pt> f) {
	basic_string<pt> q;
	for (auto p : f) {
		pt sus[4] = {{p.x+1, p.y}, {p.x-1, p.y}, {p.x, p.y+1}, {p.x, p.y-1}};
		for (pt b : sus) {
			if (in(b) && A(b) == '.') {
				A(b) = A(p);
				q += b;
			}
		}
	}
	return q;
}

basic_string<pt> expand_many(basic_string<pt> f, int k) {
	while (k--) {
		if (f.size() == 0)
			return {};
		f = expand_once(f);
	}
	return f;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> p;
	for (int i=1; i<=p; i++)
		cin >> speed[i];
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (isdigit(a[i][j]))
				front[a[i][j] - '0'] += {i, j};
	while (1) {
		int cnt = 0;
		for (int i=1; i<=p; i++) {
			front[i] = expand_many(front[i], speed[i]);
			if (front[i].size())
				cnt++;
		}
		if (!cnt)
			break;
	}
	vector<int> sol(p, 0);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (isdigit(a[i][j]))
				sol[a[i][j] - '1']++;
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}