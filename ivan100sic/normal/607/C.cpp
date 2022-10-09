#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

char sup(char x) {
	if (x == 'N' || x == 'S')
		return x ^ 'N' ^ 'S';
	return x ^ 'E' ^ 'W';
}

int n;
string a, b;

vector<int> zalgo(string s) {
	int n = s.size();
	vector<int> z(n);
	for (int i=1, l=0, r=0; i<n; i++) {
		if (i < r)
			z[i] = min(z[i-l], r-i);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> b;
	n--;

	for (char& x : a)
		x = sup(x);

	string ar = a;
	reverse(ar.begin(), ar.end());

	auto z = zalgo(ar + b);
	for (int i=n; i<2*n; i++)
		if (z[i] == 2*n-i)
			return cout << "NO\n", 0;
	cout << "YES\n";
}