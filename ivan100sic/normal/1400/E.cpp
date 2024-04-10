// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[5005];

template<class T>
void mn(T& x, T y) {
	x = min(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	vector<int> ol(5005, 1e9);
	ol[0] = 0;
	for (int i=0; i<n; i++) {
		int y = a[i];
		vector<int> nu(5005, 1e9);

		int l = 1e9;
		for (int j=0; j<=min(y, 5002); j++) {
			l = min(l+1, ol[j]);
			nu[j] = l;
		}

		l = 1e9;
		for (int j=5002; j>=0; j--) {
			l = min(l, ol[j]);
			if (j <= y) {
				mn(nu[j], l);
			}
		}

		for (int j=0; j<min(y, 5002); j++) {
			nu[j]++;
		}

		swap(ol, nu);
	}

	cout << *min_element(begin(ol), end(ol)) << "\n";
}