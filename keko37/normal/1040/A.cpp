#include<iostream>

using namespace std;

const int MAXN = 25;

int n, a, b, sol, ok = 1;
int c[MAXN];

int main () {
	cin >> n >> a >> b;
	for (int i=1; i<=n; i++) {
		cin >> c[i];
	}
	for (int i=1; i<=n/2; i++) {
		n++;
		if (c[i] < 2 && c[n-i] < 2) {
			if (c[i] != c[n-i]) ok = 0;
		} else if (c[i] == 2 && c[n-i] == 2) {
			sol += 2*min(a, b);
		} else {
			if (c[i] == 2) {
				if (c[n-i] == 0) sol += a; else sol += b;
			} else {
				if (c[i] == 0) sol += a; else sol += b;
			}
		}
		n--;
	}
	if (n & 1) if (c[n/2+1] == 2) sol += min(a, b);
	if (ok) cout << sol; else cout << -1;
	return 0;
}