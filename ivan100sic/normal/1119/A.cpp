#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	int w = 0;
	for (int i=1; i<n; i++)
		if (a[i] != a[0])
			w = max(w, i);
	for (int i=0; i<n-1; i++)
		if (a[i] != a[n-1])
			w = max(w, n-1-i);
	cout << w << '\n';
}