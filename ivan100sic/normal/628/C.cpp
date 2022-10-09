// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s, t;
	int n, k;
	cin >> n >> k >> s;
	for (char c : s) {
		int dir;
		if (c - 'a' <= 12)
			dir = 1;
		else
			dir = -1;
		int w = dir == 1 ? 25 - (c - 'a') : c - 'a';
		w = min(w, k);
		c += w*dir;
		t += c;
		k -= w;
	}

	if (k)
		t = "-1";
	cout << t << '\n';
}