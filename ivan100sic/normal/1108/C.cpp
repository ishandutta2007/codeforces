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
	string rgb = "RGB";

	string best;
	int sol = 1123123123;


	for (int i=0; i<6; i++) {
		string kand;
		int d = 0;
		for (int j=0; j<n; j++) {
			kand += rgb[j % 3];
			if (rgb[j % 3] != s[j])
				d++;
		}

		if (d < sol) {
			sol = d;
			best = kand;
		}

		next_permutation(rgb.begin(), rgb.end());
	}

	cout << sol << '\n' << best << '\n';
}