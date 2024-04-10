// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[50005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	if (n % 7 == 0) {
		int j = -1;
		for (int i=0; i<n; i++) {
			if (i % 7 != 6) {
				if (j == -1 || a[i] < a[j]) j = i;
			}
		}
		cout << j+1 << '\n';
	} else {
		int m = *min_element(a, a+n);
		m = (m-1)/6*6;
		for (int i=0; i<n; i++) {
			a[i] -= m;
		}

		int i = 0, j = 0;
		while (1) {
			if (j % 7 != 6) {
				a[i]--;
				if (a[i] == 0) {
					cout << i+1 << '\n';
					return 0;
				}
			}
			j++;
			i = (i+1) % n;
		}
	}
}