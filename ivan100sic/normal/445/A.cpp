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

	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		for (int j=0; j<m; j++) {
			if (s[j] == '.') {
				s[j] = (i+j)%2 ? 'B' : 'W';
			}
		}
		cout << s << '\n';
	}	
}