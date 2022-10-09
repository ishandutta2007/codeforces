#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a)
		cin >> x;
	int sns = a[0], szs = 0;
	basic_string<int> sol = {1};
	for (int i=1; i<n; i++)
		if (a[i]*2 <= a[0]) {
			sol += i+1;
			sns += a[i];
		} else {
			szs += a[i];
		}
	if (sns > szs) {
		cout << sol.size() << '\n';
		for (int x : sol)
			cout << x << ' ';
		cout << '\n';
	} else {
		cout << "0\n";
	}
}