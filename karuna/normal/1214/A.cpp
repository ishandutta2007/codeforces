#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, d, e;
int main() {
	cin >> n >> d >> e;
	e *= 5;

	int mn = n;
	for (int i=0; i<=e; i++) {
		if (n<d*i) continue;
		mn = min(mn, (n-d*i)%e);
	}

	cout << mn;
}