#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];
multiset<int> b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	b = multiset<int>(a, a+n);
	int c = 0;
	for (int i=0; i<n; i++) {
		auto it = b.upper_bound(a[i]);
		if (it != b.end() && *it > a[i]) {
			b.erase(it);
			c++;
		}		
	}
	cout << c << '\n';
}