#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s;
int a[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<10; i++)
		cin >> a[i];
	int me = *min_element(a+1, a+10);
	while (1) {
		int ostalo = -1, z = -1;
		for (int i=9; i>=1; i--) {
			int k = (n-a[i]) / me;
			if (k > ostalo && n-a[i] >= 0) {
				ostalo = k;
				z = i;
			}
		}
		if (ostalo == -1)
			break;
		s += (char)(z + 48);
		n -= a[z];
	}
	if (s == "")
		s = "-1";
	cout << s << '\n';
}