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

const ll mod = 1e9 + 7;

void solve()
{
	string str, best;
	int n, best_cost = INT_INF;

	cin >> n >> str;

	for(int idx_r = 0; idx_r < 3; ++idx_r)
	{
		for(int idx_g = 0; idx_g < 3; ++idx_g)
		{
			if(idx_g == idx_r)
				continue;

			for(int idx_b = 0; idx_b < 3; ++idx_b)
			{
				if(idx_b == idx_r || idx_b == idx_g)
					continue;

				string nstr;
				int lcost = 0;

				for(int i = 0; i < n; ++i)
				{
					/*switch(i % 3)
					{
						case idx_r: nstr += 'R'; break;
						case idx_g: nstr += 'G'; break;
						default: idx_b += 'B'; break;
					}*/

					if(i % 3 == idx_r)
						nstr += 'R';
					else if(i % 3 == idx_g)
						nstr += 'G'; 
					else if(i % 3 == idx_b)
						nstr += 'B';


					if(nstr[i] != str[i])
						++lcost;
				}

				if(lcost < best_cost)
				{
					best_cost = lcost;
					best = nstr;
				}
			}
		}
	}

	cout << best_cost << endl;
	cout << best << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}