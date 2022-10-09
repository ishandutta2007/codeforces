#include <bits/stdc++.h>
using namespace std;

int z[200005], n;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		cin >> s;
		int sol = 0;
		n = s.size();
		for (int i=0; i<n; i++)
			z[i+1] = z[i] + (s[i] == '1');
		for (int r=1; r<=n; r++) {
			int val = 0;
			for (int l=r-1; l>=r-20 && l>=0; l--) {
				val += (s[l] == '1' ? 1 : 0) << (r-l-1);
				if (val == r-l) {
					sol++;
				}
			}
			if (r >= val && val > 20 && z[r-20] == z[r-val])
				sol++;
		}
		cout << sol << '\n';
	}
}