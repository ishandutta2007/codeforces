#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
int a[100005], b[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	set<int> s;
	for (int i=n; i>=1; i--) {
		s.insert(a[i]);
		b[i] = s.size();
	}	
	while (q--) {
		int x;
		cin >> x;
		cout << b[x] << '\n';
	}
}