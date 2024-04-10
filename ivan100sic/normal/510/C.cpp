#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> e[1005];
int g[1005];
int n;
string a[1005];

void no() {
	cout << "Impossible\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		a[i] += '.';
	}
	for (int i=1; i<n; i++) {
		int j = 0;
		while (a[i-1][j] == a[i][j]) {
			j++;
		}
		int x = a[i-1][j];
		int y = a[i][j];

		if (y == '.') {
			no();
		}

		if (x != '.') {
			e[x] += y;
			g[y]++;
		}
	}

	queue<int> q;
	string s;

	for (int i='a'; i<='z'; i++)
		if (g[i] == 0)
			q.push(i);

	while (q.size()) {
		int x = q.front(); q.pop();
		s += (char)x;
		for (int y : e[x]) {
			g[y]--;
			if (g[y] == 0)
				q.push(y);
		}
	}

	if (s.size() < 26)
		no();

	cout << s << '\n';
}