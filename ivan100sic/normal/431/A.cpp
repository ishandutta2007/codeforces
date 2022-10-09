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

	int a[4], y=0;
	for (int& x : a)
		cin >> x;
	string s;
	cin >> s;
	for (char x : s)
		y += a[x-'1'];
	cout << y << '\n';
}