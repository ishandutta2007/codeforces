// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
bool b[500005];
int f[500005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	fill(b+1, b+n+1, 1);
	int c = n;
	for (int i=n; i>=2; i--) {
		for (int j=2*i; j<=n; j+=i) {
			if (b[j]) {
				b[j] = 0;
				c--;
			}
		}
		f[c] = max(f[c], i-1);
	}
	f[n] = n/2;
	for (int i=n-1; i>=1; i--)
		if (f[i] == 0)
			f[i] = f[i+1];
	for (int i=2; i<=n; i++) {
		cout << f[i] << " \n"[i == n];
	}
}

// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 3 4 4 4 5 6 6 6 6 7 8 8 9 10 10 11 12 12 13 14 14 15 16 17 18 19 20 21 22 23 24 25

// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 3 3 4 5 5 5 6 7 7 7 7 8 9 9 10 11 11 12 13 13 14 15 15 16 17 18 19 20 21 22 23 24 25
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 3 3 4 5 5 5 6 7 7 7 7 8 9 9 10 11 11 12 13 13 14 15 15 16 17 18 19 20 21 22 23 24 25