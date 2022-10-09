#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> z;
string s;
int n;

void op(int i) {
	z += i;
	s[i] = 'B' + 'W' - s[i];
	s[i+1] = 'B' + 'W' - s[i+1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	for (int i=n-1; i>=1; i--)
		if (s[i] == 'B')
			op(i-1);
	if (s[0] == 'B' && n % 2)
		for (int i=1; i<n; i+=2)
			op(i);

	if (set<char>(s.begin(), s.end()).size() == 1) {
		cout << z.size() << '\n';
		for (int x : z)
			cout << x + 1 << ' ';
		cout << '\n';
	} else {
		cout << "-1\n";
	}
}