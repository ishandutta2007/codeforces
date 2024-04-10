#include <iostream>

long long x;

using namespace std;
void solve()
{
	long long a, b, c, d, e;
	cin >> a >> b >> c >> d;
	e = max(max(a, b), max(c, d));
	if (a != e && b != e) cout << "No\n";
	else if (c != e && d != e) cout << "No\n"; else
	if (a * b + c * d == e * e) cout << "Yes\n";
	else cout << "No\n";
}
int main()
{
	int t;
	cin >> t;
	while (t--) solve();
}