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

	int k;
	cin >> k;
	int z[10] = {0};
	for (int i=0; i<4; i++) {
		string s;
		cin >> s;
		for (char x : s) {
			if (x != '.')
				z[x - '0']++;
		}
	}
	for (int i=0; i<10; i++)
		if (z[i] > 2*k)
			return cout << "NO\n", 0;
	cout << "YES\n";
}