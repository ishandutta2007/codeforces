#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	bool besk = false;
	for (int i=1; i<n; i++)
		besk |= a[i] + a[i-1] == 5;

	if (besk)
		cout << "Infinite\n";
	else {
		int sol = 0;
		for (int i=1; i<n; i++)
			if (a[i] + a[i-1] == 3) {
				sol += 3;
				if (a[i] == 2 && a[i-1] == 1 && i >= 2 && a[i-2] == 3)
					sol--;
			} else {
				sol += 4;
			}
		cout << "Finite\n" << sol << '\n';
	}
}