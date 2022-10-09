#include <bits/stdc++.h>
using namespace std;

int n;
string a[70005];

unordered_map<string, int> lo, hi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		
		a[i] = string(" ") + a[i];

		for (int l=1; l<=9; l++) {
			for (int r=l; r<=9; r++) {
				string sub = a[i].substr(l, r-l+1);
				hi[sub] = i;
				if (lo[sub] == 0) {
					lo[sub] = i;
				}
			}
		}
	}

	for (int i=1; i<=n; i++) {
		string shortest = a[i].substr(1, 9);

		for (int l=1; l<=9; l++) {
			for (int r=l; r<=9; r++) {
				string sub = a[i].substr(l, r-l+1);
				
				if (lo[sub] == hi[sub]) {
					if (sub.size() < shortest.size()) {
						shortest = sub;
					}
				}
			}
		}

		cout << shortest << '\n';
	}
}