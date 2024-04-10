#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;

int main(int argc, char** argv)
{
	int n;
	vector<ll> a, b;
	FAST_IO

	cin >> n;
	b.resize(n / 2);
	a.resize(n);

	for(int i = 0; i < n / 2; ++i)
		cin >> b[i];

	a[0] = 0;
	a[n - 1] = b[0];

	for(int i = 1; i < n / 2; ++i)
	{
		int prev = i - 1;
		a[i] = max(a[prev], b[i] - a[n - prev - 1]);
		a[n - i - 1] = b[i] - a[i];
	}

	for(auto x: a)
		cout << x << " ";

	cout << endl;

    return 0;
}