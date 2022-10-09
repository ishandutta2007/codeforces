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

	string s;
	cin >> s;
	string p = "heidi.";
	int i = 0;
	for (char x : s)
		if (x == p[i])
			i++;
	cout << (i == 5 ? "YES\n" : "NO\n");
}