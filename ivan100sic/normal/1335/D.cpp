// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

string s[9];

void u(char& x) {
	if (x++ == '9')
		x = '1';
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		for (int i=0; i<9; i++)
			cin >> s[i];
		for (int i=0; i<3; i++)
			for (int j=0; j<3; j++)
				u(s[3*i+j][3*j+i]);
		for (int i=0; i<9; i++)
			cout << s[i] << '\n';
	}
}