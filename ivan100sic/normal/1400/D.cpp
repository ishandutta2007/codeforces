#include <bits/stdc++.h>
using namespace std;
typedef long long L;
int main() {
	L t;
	cin >> t;
	while (t--) {
		L n, sol = 0;
		cin >> n;
		vector<L> a(n+1), b(n+1), z(n+1);
		for (L r=1; r<=n; r++) {
			cin >> a[r];
			for (L l=1; l<=r-2; l++)
				if (a[l] == a[r])
					sol += z[l], b[l+1]++, b[r]--;
			for (L i=1; i<=n; i++)
				z[i] = z[i-1] + b[i];
		}
		cout << sol << '\n';
	}
}