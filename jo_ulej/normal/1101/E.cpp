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
	//vector<pair<int, int>> rects;
	int n;
	int max_x = 0, max_y = 0;

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		char type;
		cin >> type;

		if(type == '+')
		{
			int x, y;
			cin >> x >> y;

			if(x > y)
				swap(x, y);

			max_x = max(max_x, x);
			max_y = max(max_y, y);
		}
		else
		{
			int w, h;
			cin >> w >> h;

			if(w > h)
				swap(w, h);

			if(max_x <= w && max_y <= h)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}