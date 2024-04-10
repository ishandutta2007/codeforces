#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int q[1000005], n, j, z;
bool u[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		q[x] = i;
	}

	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		x = q[x];
		u[x] = 1;
		while (u[j+1])
			j++;
		z += x > j;
	}

	cout << z << '\n';
}