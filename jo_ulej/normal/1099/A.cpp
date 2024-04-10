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
	int w, h, u1, d1, u2, d2;
	cin >> w >> h >> u1 >> d1 >> u2 >> d2;

	while(h > 0)
	{
		w += h;

		if(h == d1)
			w -= u1;

		if(h == d2)
			w -= u2;

		w = max(w, 0);

		--h;
	}

	cout << w << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}