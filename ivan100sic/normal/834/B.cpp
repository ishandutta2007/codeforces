#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
string s;
int z[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> s;
	for (char x='A'; x<='Z'; x++) {
		int l = -1, r = -1;
		for (int i=0; i<n; i++)
			if (s[i] == x) {
				l = l == -1 ? i : l;
				r = i;
			}
		if (l != -1) {
			z[l+1]++;
			z[r+2]--;
		}
	}
	for (int i=1; i<=n; i++) {
		if ((z[i] += z[i-1]) > k)
			return cout << "YES\n", 0;
	}
	cout << "NO\n";
}