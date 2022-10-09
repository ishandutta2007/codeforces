// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int u[30];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	string s;
	cin >> n >> s;
	memset(u, 128, sizeof u);
	vector<int> b;
	u[29] = 0;
	for (char c : s) {
		int z = -341;
		for (int i=0; i<30; i++) {
			if (c-'a' < i) {
				z = max(z, u[i]);
			}
		}
		u[c-'a'] = ++z;
		b.push_back(z);
	}

	cout << *max_element(begin(b), end(b)) << '\n';
	for (int x : b)
		cout << x << ' ';
	cout << '\n';

}