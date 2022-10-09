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

	int n, k;
	cin >> n >> k;

	if (n <= 2*k+1) {
		cout << "1\n" << (1+n) / 2 << '\n';
		return 0;
	}

	int aa = -1, bb = -1, low_zona = 123123123;

	for (int a=1; a<=k+1; a++) {
		for (int b=n-k; b<=n; b++) {
			int zona = b-a-1-k-k;
			if (zona >= 0 && zona % (2*k+1) == 0 && zona < low_zona) {
				low_zona = zona;
				aa = a;
				bb = b;
			}
		}
	}

	vector<int> sol = {aa};
	int x = aa + 2*k + 1;
	for (int i=0; i<low_zona/(2*k+1); i++) {
		sol.push_back(x);
		x += 2*k+1;
	}
	sol.push_back(bb);

	cout << sol.size() << '\n';
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';

}