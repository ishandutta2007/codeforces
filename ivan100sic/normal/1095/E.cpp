#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s;
int z[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	if (n % 2)
		return cout << "0\n", 0;
	for (int i=0; i<n; i++)
		z[i+1] = z[i] + (s[i] == '(' ? 1 : -1);
	// ako je na kraju 2, moramo otv -> zatv, tako da suma ne padne ispod 0
	if (z[n] == 2) {
		for (int i=1; i<=n; i++)
			if (z[i] < 0)
				return cout << "0\n", 0;
		// mora bude posle svih 0, 1
		int p = 0;
		for (int i=1; i<=n; i++)
			if (z[i] == 0 || z[i] == 1)
				p = i;
		int z = 0;
		for (int i=p; i<=n; i++)
			if (s[i] == '(')
				z++;
		cout << z << '\n';
		return 0;
	}

	// ako je na kraju -2, moramo da nadjemo zatv koja ce da otvori
	if (z[n] == -2) {
		for (int i=1; i<=n; i++)
			if (z[i] < -2)
				return cout << "0\n", 0;
		// mora pre svih -2, -1
		int p = 0;
		for (int i=1; i<=n; i++)
			if (z[i] == -1 || z[i] == -2) {
				p = i;
				break;
			}
		int z = 0;
		for (int i=0; i<p; i++)
			if (s[i] == ')')
				z++;
		cout << z << '\n';
		return 0;
	}

	cout << "0\n";
}