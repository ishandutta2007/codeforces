#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[333];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	for (char x : s)
		a[x-'a'] ^= 1;
	int x = accumulate(a, a+26, 0);
	if (x <= 1 || x % 2 == 1)
		cout << "First\n";
	else
		cout << "Second\n";
}