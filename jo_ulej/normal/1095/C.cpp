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
	ll n, k;
	cin >> n >> k;

	ll temp = n;
	int ans[100];
	int pw   = 0;
	int cnt = 0;

	while(temp > 0)
	{
		ans[pw] = temp % 2;

		if(ans[pw])
			++cnt;

		temp /= 2;
		++pw;
	}

	if(k < cnt)
	{
		cout << "NO" << endl;

		return;
	}

	int j = pw - 1;

	while(k > cnt && j > 0)
	{
		if(ans[j] > 0)
		{
			--ans[j];
			ans[j - 1] += 2;
			++cnt;
		}
		else
		{
			--j;
		}
	}

	if(k == cnt)
	{
		cout << "YES" << endl;

		for(int i = 0; i < pw; ++i)
		{
			ll power = 1LL << (ll)i;

			for(int step = 0; step < ans[i]; ++step)
				cout << power << " ";
		}

		cout << endl;
	}
	else
	{
		cout << "NO" << endl;

		return;
	}
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}