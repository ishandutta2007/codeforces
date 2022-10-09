#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool pal(string s) {
	string p = s;
	reverse(p.begin(), p.end());
	return p == s;
}

void inc(string& s) {
	s[4]++;
	if (s[4] == '9'+1) {
		s[4] = '0';
		s[3]++;
		if (s[3] == '6') {
			s[3] = '0';
			s[1]++;
			if (s[1] == '9' + 1) {
				s[1] = '0';
				s[0]++;
			} else if (s[0] == '2' && s[1] == '4') {
				s[0] = s[1] = '0';
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int z = 0;
	while (!pal(s)) {
		inc(s);
		z++;
	}
	cout << z << '\n';
}