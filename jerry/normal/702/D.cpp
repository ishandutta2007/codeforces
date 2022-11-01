#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll d, k, a, b, t;

int main()
{
	cin >> d >> k >> a >> b >> t;
	if (d <= k) cout << a*d << endl;
	else if (t+k*a > k*b) cout << k*a+(d-k)*b << endl;
	else if (t+(d%k)*a > (d%k)*b) cout << (d/k)*(k*a+t)-t+(d%k)*b << endl;
	else cout << (d/k)*(k*a+t)+(d%k)*a << endl;
	return 0;
}