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
	sort(s, s+n);
	int z = 0;
	for (int i=0; i<n; i++)
		for (int j=i+2; j<n; j+=2)
			if (s[i][0] == s[j][0])
				z++;
	cout << z << '\n';
}