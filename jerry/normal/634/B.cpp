#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll s, x, f, a;

int main()
{
	cin >> s >> x;
	f = s - x; a = 1;
	if (f < 0 || f&1ll) a = 0;
	f >>= 1;
	for (ll i = 1;i <= s;i<<=1)
	{
		if ((f&i) && (x&i)) a = 0;
		if (!(f&i) && (x&i)) a *= 2ll;
	}
	if (a && !f) a -= 2;
	cout << a << endl;
	return 0;
}