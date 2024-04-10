#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, c, a, b;
int p[55], t[55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> c;
	for (int i=0; i<n; i++)
		cin >> p[i];
	for (int i=0; i<n; i++)
		cin >> t[i];
	int T = 0;
	for (int i=0; i<n; i++) {
		T += t[i];
		a += max(0, p[i] - c*T);
	}
	T = 0;
	for (int i=n-1; i>=0; i--) {
		T += t[i];
		b += max(0, p[i] - c*T);
	}
	if (a > b)
		cout << "Limak\n";
	else if (b > a)
		cout << "Radewoosh\n";
	else
		cout << "Tie\n";
}