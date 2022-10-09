#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string a[200005];
basic_string<int> e[65536];
int indeg[65536], outdeg[65536];

int enc(char x, char y) {
	return (int)x * 256 + (int)y;
}

void no() {
	cout << "NO\n";
	exit(0);
}

list<int> roam(int x) {
	// prosetaj se malo
	list<int> a;
	a.push_back(x);

	while (e[x].size()) {
		int y = e[x].back();
		e[x].pop_back();
		a.push_back(y);
		x = y;
	}

	if (a.size() == 1)
		return a;

	for (auto it = a.begin(); it != a.end(); ++it) {
		auto w = roam(*it);
		w.pop_back();
		a.splice(it, w);
	}

	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		string t;
		cin >> t;
		a[i] = t;
		int u = enc(t[0], t[1]);
		int v = enc(t[1], t[2]);
		e[u] += v;
		indeg[v]++;
		outdeg[u]++;
	}

	int poc = -1, kraj = -1, za = 0;

	for (int i=0; i<65536; i++) {
		za += abs(indeg[i] - outdeg[i]);
		if (indeg[i] - outdeg[i] == 1)
			kraj = i;
		else if (indeg[i] - outdeg[i] == -1)
			poc = i;
	}

	if (za > 2)
		no();
	if (za == 0) {
		// nadji neki cvor
		for (int i=0; i<65536; i++) {
			if (indeg[i] > 0) {
				poc = kraj = i;
				break;
			}
		}
	}

	auto sol = roam(poc);
	if ((int)sol.size() != n+1)
		no();
	string w;
	w += (char)(*sol.begin() / 256);

	// for (int x : sol) {
	// 	cerr << x << ' ';
	// 	cerr << (char)(x / 256);
	// 	cerr << (char)(x % 256);
	// 	cerr << '\n';
	// }

	for (int x : sol)
		w += (char)(x % 256);
	cout << "YES\n" << w << '\n';
}