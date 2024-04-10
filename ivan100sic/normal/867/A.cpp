#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	cout << ((s[0] == 'S' && s[n-1] == 'F') ? "YES" : "NO");
}