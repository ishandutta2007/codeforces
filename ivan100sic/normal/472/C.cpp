#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string a[100005], b[100005], last;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i] >> b[i];
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		string u = min(a[x], b[x]);
		string v = max(a[x], b[x]);
		if (last < u)
			last = u;
		else if (last < v)
			last = v;
		else
			return cout << "NO\n", 0;
	}
	cout << "YES\n";
}