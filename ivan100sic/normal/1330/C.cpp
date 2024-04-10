// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[100005];
ll z[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++)
		cin >> a[i];
	for (int i=m; i>=1; i--)
		z[i] = z[i+1] + a[i];

	if (z[1] < n)
		return cout << "-1\n", 0; 
	for (int i=1; i<=m; i++)
		if (i-1+a[i] > n)
			return cout << "-1\n", 0; 

	int p = 0;
	for (int i=1; i<=m; i++) {
		p++;
		if (n-p+1 > z[i]) {
			p = n+1-z[i];
		}
		cout << p << " \n"[i == m];
	}
}

// I will still practice daily...