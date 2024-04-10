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

	int n;
	string s;
	cin >> n >> s;
	int z = 0;
	for (int i=0; i<n; i++) {
		if (s[i] == '(') {
			cout << z%2;
			z++;
		} else {
			z--;
			cout << z%2;
		}
	}
}