#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];
bool u[200005];
int c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		int z = 0;
		while (!u[x]) {
			++c;
			++z;
			u[a[c]] = 1;
		}
		cout << z << ' ';
	}
	cout << '\n';
}