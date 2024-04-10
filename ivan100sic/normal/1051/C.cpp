#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[105];
int c[105];
int z[105];
string s;

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}
	s = string(n, 'B');
	
	for (int i = 1; i <= 100; i++) {
		z[c[i]]++;
	}

	if (z[1] % 2 == 1 && accumulate(z + 3, z + 101, 0) == 0) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	// stavi naizmenicno ove sto se javljaju 1
	int parnost = 0;
	for (int i = 0; i < n; i++) {
		if (c[a[i]] == 1) {
			if (parnost == 1) {
				s[i] = 'A';
			}
			parnost ^= 1;
		}
	}

	// ako ne valja parnost, uzmi nekog ko se javlja 3+ puta
	for (int i = 0; i < n; i++) {
		if (parnost && c[a[i]] >= 3) {
			parnost = 0;
			s[i] = 'A';
		}
	}

	cout << s << '\n';

}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}