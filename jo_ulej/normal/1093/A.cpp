#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;

int main(int argc, char** argv)
{
	int t;
	cin >> t;

	for(int i = 0; i < t; ++i)
	{
		int x;
		cin >> x;

		if(x % 2 == 0)
		{
			cout << x / 2 << endl;
		}
		else
		{
			cout << (x - 3) / 2 + 1 << endl;
		}
	}

    return 0;
}