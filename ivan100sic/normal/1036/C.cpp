#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll val(const string& s) {
	ll z = 0;
	for (char x : s)
		z = 10*z + x - 48;
	return z;
}

ll good[6000000];
int g;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<18; i++)
	for (int j=0; j<18; j++)
	for (int k=0; k<18; k++)
	for (int a=0; a<10; a++)
	for (int b=0; b<10; b++)
	for (int c=0; c<10; c++)
	{
		string s = "000000000000000000";
		s[i] = a+48;
		s[j] = b+48;
		s[k] = c+48;

		good[g++] = val(s);
	}

	good[g++] = 1'000'000'000'000'000'000ll;

	sort(good, good+g);
	g = unique(good, good+g) - good;
	int t;
	cin >> t;
	while (t--) {
		ll x, y;
		cin >> x >> y;
		cout << upper_bound(good, good+g, y) - lower_bound(good, good+g, x) << '\n';
	}
}