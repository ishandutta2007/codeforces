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

	int n, k, z=0;
	cin >> n >> k;
	while (n--) {
		string s;
		cin >> s;
		int y = count(s.begin(), s.end(), '4');
		int c = count(s.begin(), s.end(), '7');
		if (y+c <= k)
			z++;
	}
	cout << z << '\n';
}