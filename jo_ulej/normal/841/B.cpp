#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e7 + 9;

void solve()
{
	int n;
	int sum_modulo_two = 0;
	bool has_uneven_numbers = false;

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;

		sum_modulo_two = (sum_modulo_two + x) % 2;

		if(x % 2 != 0)
			has_uneven_numbers = true;
	}

	if(sum_modulo_two != 0)
		cout << "First" << endl;
	else if(has_uneven_numbers)
		cout << "First" << endl;
	else
		cout << "Second" << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}