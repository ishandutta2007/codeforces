#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s[55];

void no() {
	cout << "NO\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> s[i];

	for (int i=0; i<n; i++) {
		for (int j=1; j<n-1; j++) {
			if (s[i][j] == '.') {
				if (s[i+1][j-1] != '.')
					no();
				if (s[i+1][j] != '.')
					no();
				if (s[i+1][j+1] != '.')
					no();
				if (s[i+2][j] != '.')
					no();

				s[i][j] = s[i+1][j-1] = s[i+1][j] = s[i+1][j+1] = s[i+2][j] = '#';
			}
		}
	}

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (s[i][j] == '.')
				no();
	cout << "YES\n";
}