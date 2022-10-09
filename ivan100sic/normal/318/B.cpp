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

	string s;
	cin >> s;
	ll h=0, z=0;
	for (int i=0; i<=(int)s.size()-5; i++) {
		string p = s.substr(i, 5);
		if (p == "heavy") {
			h++;
		} else if (p == "metal") {
			z += h;
		}
	}
	cout << z;
}