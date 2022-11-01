#include<bits/stdc++.h>

using namespace std;

int main() {
	string s[100], t[100];
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i - 1];
	for (int i = 1; i <= m; i++)
		cin >> t[i - 1];
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << s[(x - 1) % n] << t[(x - 1) % m] << endl;
	}
}