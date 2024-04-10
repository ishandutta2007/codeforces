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

	int n, g=1, r=1;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == "UR" || s == "DL" || s.size() == 4)
			g++;
		if (s == "UL" || s == "DR" || s.size() == 4)
			r++;
	}
	cout << g*1ll*r << '\n';
}