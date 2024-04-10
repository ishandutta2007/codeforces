#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int z[100005];
int k;

int resi(string s) {
	int n = s.size();
	s = string(" ") + s;
	for (int i=1; i<=n; i++)
		z[i] = z[i-1] + (s[i] == 'b');
	int r = 0, sol = 0;
	for (int i=1; i<=n; i++) {
		while (r + 1 <= n && z[r+1] - z[i-1] <= k)
			r++;
		sol = max(sol, r-i+1);
	}
	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	string s;
	cin >> n >> k >> s;
	int w = resi(s);
	for (char& x : s)
		x = 'a' ^ 'b' ^ x;
	w = max(w, resi(s));
	cout << w << '\n';
}