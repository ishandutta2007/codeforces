#include <bits/stdc++.h>
using namespace std;

int n;
string s, p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	p = s;
	int x = (n-1) / 2;
	int dir = n % 2 ? -1 : 1;

	for (int i=0; i<n; i++) {
		p[x] = s[i];
		x += dir * (i+1);
		dir *= -1;
	}

	cout << p;
}