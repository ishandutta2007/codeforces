#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;

int main(int argc, char** argv)
{
	ll n;
	cin >> n;

	if(n % 2 == 0)
	{
		cout << n / 2 << endl;
	}
	else
	{
		ll d = 2;

		while(n % d != 0 && d * d <= n)
			++d;

		if(n % d != 0)
			d = n;

		//cout << "d=" << d << endl;

		cout << 1 + (n - d) / 2 << endl;
	}

    return 0;
}