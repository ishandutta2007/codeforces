#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int x[1005];

bool ins(int l, int x, int r) {
	if (l > r)
		swap(l, r);
	return l < x && x < r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> x[i];

	bool ok = 1;
	for (int i=0; i<n-1; i++)
		for (int j=0; j<n-1; j++) {
			if (abs(j-i) <= 1)
				continue;
			if (ins(x[i], x[j], x[i+1]) != ins(x[i], x[j+1], x[i+1]))
				ok = 0;
		}

	cout << (ok ? "no\n" : "yes\n");
}