#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int p[4] = {1, 6, 8, 9};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	s.erase(find(s.begin(), s.end(), '1'));
	s.erase(find(s.begin(), s.end(), '6'));
	s.erase(find(s.begin(), s.end(), '8'));
	s.erase(find(s.begin(), s.end(), '9'));

	sort(s.begin(), s.end(), greater<char>());

	int flag = 0;

	if (s.size() && s[0] == '0') {
		flag = 1;
	}

	int r = 0;
	for (char x : s) {
		r = (10 * r + x - 48) % 7;
	}

	cerr << "rem " << r << '\n';

	for (int i=0; i<24; i++, next_permutation(p, p+4)) {
		int z = 0;
		for (int j=0; j<4; j++)
			z = 10*z + p[j];
		z %= 7;
		if ((10000*r + z) % 7 == 0) {
			if (flag)
				cout << p[0] << p[1] << p[2] << p[3] << s << '\n';
			else
				cout << s << p[0] << p[1] << p[2] << p[3] << '\n';
			return 0;
		}
	}
}