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

	string a, b;
	cin >> a >> b;
	string s = to_string(stoll(a) + stoll(b));	
	string aa, bb, ss;
	for (char x : a)
		if (x != '0')
			aa += x;
	for (char x : b)
		if (x != '0')
			bb += x;
	for (char x : s)
		if (x != '0')
			ss += x;
	cout << (stoll(ss) == stoll(aa) + stoll(bb) ? "YES\n" : "NO\n");
}