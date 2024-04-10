#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, x;
int p[1231231], q;
bool ima[1231231];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x;
	for (int i=1; i<(1<<n); i++) {
		if (i != x && !ima[x^i]) {
			ima[i] = true;
			p[++q] = i;
		}
	}

	cout << q << '\n';
	for (int i=1; i<=q; i++)
		cout << (p[i]^p[i-1]) << ' ';
	cout << '\n';
}