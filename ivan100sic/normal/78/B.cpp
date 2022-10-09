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

	string s = "ROYGBIV";
	int n;
	cin >> n;
	cout << s;
	for (int i=0; i<n-7; i++)
		cout << s[i%4+3];
	cout << '\n';
}