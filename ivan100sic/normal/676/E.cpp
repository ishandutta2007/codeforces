#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[100005], n, k, movs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<=n; i++) {
		string s;
		cin >> s;
		if (s == "?") {
			a[i] = 123123123;
		} else {
			a[i] = stoi(s);
			movs++;
		}
	}

	if (k == 0) {
		// pobednik je covek ako je na potezu (ako nije stavljena nula)
		// ili ako je vec stavljena nula
		if (movs % 2 == 1 && movs != n+1 && a[0] == 123123123) {
			cout << "Yes\n";
		} else if (a[0] == 0) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
		return 0;
	}

	// ako postoji potez, onda je pobednik onaj ciji je poslednji potez
	if (movs != n+1) {
		if (n % 2 == 0) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	} else {
		// proveri da li je deljivo sa k
		const int MOD = 397621387193;
		ll z = 0;
		for (int i=n; i>=0; i--) {
			z = (z * k + a[i]) % MOD;
		}
		if (z == 0) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}