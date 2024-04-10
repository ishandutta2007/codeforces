#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string l[3] = {"FILIPINO", "JAPANESE", "KOREAN"};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		char c = s.back();
		int x;
		if (c == 'o')
			x = 0;
		else if (c == 'u')
			x = 1;
		else
			x = 2;
		cout << l[x] << '\n';
	}
}