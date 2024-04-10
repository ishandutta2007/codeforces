#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s;
int z[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();
	s = string(" ") + s;
	for (int i=1; i<=n; i++)
		z[i] = z[i-1] + (isupper(s[i]) ? 1 : 0);
	int sol = n + 1;
	for (int i=0; i<=n; i++) {
		sol = min(sol, (i-z[i]) + (z[n]-z[i]));
	}
	cout << sol << '\n';
}