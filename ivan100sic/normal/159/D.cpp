#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s;
bool p[2005][2005];
int c[2005];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();
	for (int l=n-1; l>=0; l--) {
		for (int r=l; r<n; r++) {
			if (l == r)
				p[l][r] = 1;
			else if (l == r-1)
				p[l][r] = s[l] == s[r];
			else {
				p[l][r] = s[l] == s[r] && p[l+1][r-1];
			}

			if (p[l][r])
				c[r]++;
		}
	}

	for (int i=1; i<n; i++)
		c[i] += c[i-1];

	ll z = 0;

	for (int i=0; i<n; i++)
		for (int j=i; j<n; j++)
			if (p[i][j])
				z += c[i-1];

	cout << z << '\n';
}