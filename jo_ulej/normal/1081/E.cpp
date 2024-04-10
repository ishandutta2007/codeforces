#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
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
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }

void solve()
{
	int n;
	cin >> n;

	vector<ll> arr(n, 0);

	for(int i = 1; i < n; i += 2)
		cin >> arr[i];

	for(int i = 1; i < n; i += 2)
	{
		vector<ll> divs;

		for(ll d = 1; d * d < arr[i]; ++d)
			divs.push_back(d);

		reverse(divs.begin(), divs.end());

		for(ll d2: divs)
		{
			if(arr[i] % d2 == 0)
			{
				ll d1 = arr[i] / d2;

				if((d1 + d2) % 2 != 0)
					continue;

				ll v = (d1 + d2) / 2;
				ll u = (d1 - d2) / 2;
				v *= v;
				u *= u;
				DBG(u); DBG(v);

				if(arr[i - 1] + u <= 0)
					continue;

				//if(i + 1 < n && arr[i + 1] - v <= 0)
					//continue;

				arr[i - 1] += u;

				if(i + 1 < n)
					arr[i + 1] -= v;

				break;
			}
		}
	}

	for(auto el: arr)
	{
		if(el <= 0)
		{
			cout << "No" << endl;
			return;
		}
	}

	cout << "Yes" << endl;

	for(auto el: arr)
		cout << el << " ";

	cout << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}