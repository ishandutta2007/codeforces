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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

int askcnt = 0;

ll ask1(int idx)
{
	cout << "? " << idx + 1 << endl;
	ll ret; cin >> ret;
	++askcnt;

	return ret;
}

bool ask2(ll val)
{
	cout << "> " << val << endl;
	int ret; cin >> ret;
	++askcnt;

	return ret;
}

ll findmx()
{
	ll L = 0, R = 1e9;

	if(!ask2(L))
		return L;

	while(R - L > 1)
	{
		ll M = (L + R) / 2;

		if(ask2(M))
			L = M;
		else
			R = M;
	}

	return R;
}

#define gcd __gcd

void solve()
{
	int n; cin >> n;

	ll mx = findmx();

	vector<ll> vals;
	mt19937 mt_rand(time(nullptr));

	while(askcnt < 60)
	{
		int i = (mt_rand()) % n;

		vals.push_back(ask1(i));
	}

	vector<ll> dlt(vals.size() - 1);

	for(int i = 0; i < vals.size() - 1; ++i)
	{
		ll dt = vals[i + 1] - vals[i];

		if(dt == 0)
			continue;

		if(dt < 0)
			dt = -dt;

		dlt.push_back(dt);
	}

	ll d = dlt[0];

	for(int i = 1; i < dlt.size(); ++i)
		d = gcd(d, dlt[i]);

	cout << "! " << mx - (ll)(n - 1) * d << " " << d << endl;
}

int main(int argc, char** argv)
{
	solve();

	return 0;
}