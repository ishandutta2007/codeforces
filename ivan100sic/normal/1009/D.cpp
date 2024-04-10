#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void ne() {
	cout << "Impossible\n";
	exit(0);
}

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

vector<pair<int, int>> sol;
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	if (m < n-1)
		ne();
	
	for (int i=2; i<=n; i++)
		sol.push_back({1, i});
	m -= n-1;

	for (int i=2; i<=n; i++)
		for (int j=i+1; j<=n; j++) {
			if (!m)
				break;
			if (gcd(i, j) == 1) {
				sol.push_back({i, j});
				m--;
			}
		}

	if (m)
		ne();
	
	cout << "Possible\n";
	for (auto p : sol)
		cout << p.first << ' ' << p.second << '\n';
}