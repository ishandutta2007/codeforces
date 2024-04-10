#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> s[i];
	int z = 0;
	for (int i=0; i<n; i++) {
		int y = 0;
		for (int j=0; j<n; j++) 
			y += s[i][j] == 'C';
		z += y*(y-1)/2;
	}
	for (int i=0; i<n; i++) {
		int y = 0;
		for (int j=0; j<n; j++) 
			y += s[j][i] == 'C';
		z += y*(y-1)/2;
	}
	cout << z << '\n';
}