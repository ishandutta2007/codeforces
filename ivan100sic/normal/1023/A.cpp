#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;

	string a, b;
	cin >> a >> b;

	bool ok = false;

	auto it = find(a.begin(), a.end(), '*');
	if (it == a.end())
		ok = a == b;
	else {
		int k = it - a.begin();

		if ((int)b.size() + 1 >= (int)a.size()) {
			string al = a.substr(0, k);
			string bl = b.substr(0, k);

			string ar = a.substr(k+1);
			string br = b.substr(b.size() - ar.size());

			ok = al == bl && ar == br;
		}

	}

	cout << (ok ? "YES" : "NO");
}