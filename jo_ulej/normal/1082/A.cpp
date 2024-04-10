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

	for(; t > 0; --t)
	{
		int n, x, y, d, ans = INT_INF;
		cin >> n >> x >> y >> d;

		if(abs(x - y) % d == 0)
		{
			ans = min(ans,  abs(x - y) / d);
		}
		
		if(y % d == 1)
		{
			int dist_to_begin_x = x == 1 ? 0 : (x - 2) / d + 1;
			int dist_to_begin_y = (y - 1) / d;

			ans = min(ans, dist_to_begin_x + dist_to_begin_y);
		}

		if(y % d == n % d)
		{
			int dist_to_end_x = x == n ? 0 : (n - x - 1) / d + 1;
			int dist_to_end_y = (n - y) / d;

			ans = min(ans, dist_to_end_x + dist_to_end_y);
		}

		if(ans == INT_INF)
			cout << "-1" << endl;
		else
			cout << ans << endl;
	}

    return 0;
}