#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a[6] = {4, 8, 15, 16, 23, 42};
	int p, q, r, s;

	cout << "? 1 2\n" << flush;
	cin >> p;

	cout << "? 1 3\n" << flush;
	cin >> q;

	cout << "? 4 5\n" << flush;
	cin >> r;

	cout << "? 4 6\n" << flush;
	cin >> s;

	do {
		if (a[0] * a[1] == p && a[0] * a[2] == q &&
			a[3] * a[4] == r && a[3] * a[5] == s)
		{
			cout << "!";
			for (int i=0; i<6; i++)
				cout << " " << a[i];
			cout << '\n' << flush;
		}
	} while (next_permutation(a, a+6));

}