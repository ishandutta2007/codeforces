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

	int n; string s;
	cin >> n >> s;
	for (int i=0, j=1; i<n; i+=j, j++)
		cout << s[i];
}