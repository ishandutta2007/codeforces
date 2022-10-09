// Retired?
#include <bits/stdc++.h>
using namespace std;

// Doing problems from this contest one by one, starting from Div2A,
// I wondered whether they could get even worse. And sure enough they did!

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, k;
int a[2005], sol[2005];
bool moz[2005][14005];

int r[10] = {
	0b1110111,
	0b0010010,
	0b1011101,
	0b1011011,
	0b0111010,
	0b1101011,
	0b1101111,
	0b1010010,
	0b1111111,
	0b1111011
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		int x = 0;
		for (int j=0; j<7; j++) {
			if (s[j] == '1') {
				x += 1 << (6-j);
			}
		}
		a[i] = x;
	}

	moz[n][0] = true;
	for (int i=n-1; i>=0; i--) {
		for (int j=0; j<10; j++) {
			if ((a[i] & r[j]) == a[i]) {
				int dif = __builtin_popcount(r[j] - a[i]);
				for (int k=0; k<7*(n-i); k++) {
					moz[i][k+dif] |= moz[i+1][k];
				}
			}
		}
	}
	//
	// for (int i=0; i<=n; i++) {
	// 	for (int j=0; j<32; j++) {
	// 		cerr << moz[i][j];
	// 	}
	// 	cerr << '\n';
	// }

	if (!moz[0][k]) {
		cout << "-1\n";
		return 0;
	}

	int kr = k;
	for (int i=0; i<n; i++) {
		// stavi najvecu cifru
		for (int j=9; j>=0; j--) {
			if ((a[i] & r[j]) == a[i]) {
				int dif = __builtin_popcount(r[j] - a[i]);
				if (kr-dif >= 0 && moz[i+1][kr-dif]) {
					sol[i] = j;
					kr -= dif;
					break;
				}
			}
		}
	}

	for (int i=0; i<n; i++) {
		cout << sol[i];
	}
	cout << '\n';
}