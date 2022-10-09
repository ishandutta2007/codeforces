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

	int n, z=0;
	string s;
	cin >> n >> s;
	for (int i=0; i<n; i+=2) {
		if (s[i] == s[i+1]) {
			s[i] = s[i] == 'a' ? 'b' : 'a';
			z++;
		}
	}
	cout << z << '\n' << s << '\n';
}