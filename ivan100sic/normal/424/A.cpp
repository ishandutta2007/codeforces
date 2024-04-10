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

	int n, z = 0;
	cin >> n;
	string s;
	cin >> s;
	int raz = count(s.begin(), s.end(), 'X');
	raz = raz - (n - raz);
	for (int i=0; i<n; i++) {
		if (s[i] == 'X' && raz > 0) {
			raz -= 2;
			s[i] = 'x';
			z++;
		} else if (s[i] == 'x' && raz < 0) {
			raz += 2;
			s[i] = 'X';
			z++;
		}
	}
	cout << z << '\n' << s << '\n';
}