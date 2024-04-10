#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int p[100005][6];
int n;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	memset(p, 255, sizeof(p));
	for (int i=1; i<=5; i++)
		p[1][i] = 0;

	for (int i=1; i<n; i++) {
		for (int j=1; j<=5; j++) {

			if (p[i][j] == -1)
				continue;

			basic_string<int> moze;
			if (a[i] < a[i+1]) {
				for (int k=j+1; k<=5; k++)
					moze += k;
			} else if (a[i] > a[i+1]) {
				for (int k=1; k<j; k++)
					moze += k;
			} else {
				for (int k=1; k<=5; k++)
					if (k != j)
						moze += k;
			}

			for (int k : moze)
				p[i+1][k] = j;
		}
	}

	basic_string<int> sol(n, 0);

	int ok = 0;
	for (int i=1; i<=5; i++)
		if (p[n][i] != -1)
			ok = i;
	if (!ok) {
		cout << "-1\n";
		return 0;
	}
	for (int i=n, j=ok; i>0; j=p[i][j], i--)
		sol[i-1] = j;
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}