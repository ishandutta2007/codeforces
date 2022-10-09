#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[5005], u[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	copy(a, a+n, u);
	sort(u, u+n);
	
	vector<ll> ol(n);

	for (int i=0; i<n; i++) {
		vector<ll> nu(n);
		ll lo = 1e18;
		for (int j=0; j<n; j++) {
			lo = min(lo, ol[j]);
			nu[j] = lo + abs(a[i] - u[j]);
		}
		swap(ol, nu);
	}
	cout << *min_element(ol.begin(), ol.end()) << '\n';
}