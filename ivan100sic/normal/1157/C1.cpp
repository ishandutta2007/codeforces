#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005], u[200005], v[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];


	u[0] = 1;
	for (int i=1; i<n; i++)
		u[i] = a[i-1] > a[i] ? u[i-1] + 1 : 1;

	v[n-1] = 1;
	for (int i=n-2; i>=0; i--)
		v[i] = a[i] < a[i+1] ? v[i+1] + 1 : 1;


	string sol;
	int l = 0, r = n-1;
	int last = -1;
	while (l != r) {
		if (a[l] < a[r]) {
			if (a[l] > last) {
				last = a[l++];
				sol += 'L';
			} else if (a[r] > last) {
				last = a[r--];
				sol += 'R';
			} else {
				break;
			}
		} else if (a[l] > a[r]) {
			if (a[r] > last) {
				last = a[r--];
				sol += 'R';
			} else if (a[l] > last) {
				last = a[l++];
				sol += 'L';
			} else {
				break;
			}
		} else {
			if (a[l] > last) {
				if (u[r] > v[l]) {
					last = a[r--];
					sol += 'R';
				} else {
					last = a[l++];
					sol += 'L';
				}
			} else {
				break;
			}
		}
	}

	if (l == r && a[l] > last) {
		last = a[l++];
		sol += 'L';
	}

	cout << sol.size() << '\n' << sol << '\n';
}