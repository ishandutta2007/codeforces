#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, allowed;
string s, oks;
int req[1505];
int lcp[1505][1505];

int bad(char x) {
	return 1 - (oks[x - 'a'] - '0');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s >> oks >> allowed;
	n = s.size();
	for (int i=n-1; i>=0; i--) {
		for (int j=n-1; j>=0; j--) {
			lcp[i][j] = lcp[i+1][j+1] + 1;
			if (s[i] != s[j])
				lcp[i][j] = 0;
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<i; j++) {
			req[i] = max(req[i], lcp[i][j] + 1);			
		}
	}

	int z = 0;
	for (int i=0; i<n; i++) {
		int bc = 0;
		for (int j=i+1; j<=n; j++) {
			bc += bad(s[j-1]);
			if (bc > allowed)
				break;
			if (j-i >= req[i])
				z++;
		}
	}
	cout << z << '\n';
}