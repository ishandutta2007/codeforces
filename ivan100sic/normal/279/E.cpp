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

	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	s += "0000";
	int z = 0;
	for (int i=0; i<(int)s.size()-1; i++) {
		if (s[i] == '1' && s[i+1] == '1') {
			z++;
			int k = 0;
			for (int j=i; s[j] == '1'; j++)
				s[j] = '0', k = j;
			s[k+1] = '1';
		} else if (s[i] == '1') {
			s[i] = '0';
			z++;
		}
	}
	cout << z << '\n';
}