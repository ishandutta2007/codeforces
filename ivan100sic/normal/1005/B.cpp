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

	string s, t;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());

	int z = 0;

	while (s.size() > t.size()) {
		s.pop_back();
		z++;
	}

	while (t.size() > s.size()) {
		t.pop_back();
		z++;
	}

	for (int i=0; i<(int)s.size(); i++) {
		if (s[i] != t[i]) {
			z += 2 * ((int)s.size() - i);
			break;
		}
	}

	cout << z << '\n';

}