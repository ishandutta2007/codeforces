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

	vector<int> a(n), b(n);

	for(auto& el: a)
		cin >> el;

	for(auto& el: b)
		cin >> el;

	vector<pii> arr;

	int dlt = 0;

	for(int i = 0; i < n; ++i)
	{
		if(a[i] == 0 && b[i] == 0)
		{
			++dlt;
			continue;
		}

		if(a[i] == 0 && b[i] != 0)
			continue;

		if(b[i] < 0)
			a[i] = -a[i], b[i] = -b[i];

		int g = __gcd(a[i], b[i]);

		if(g == 0)
			arr.push_back(make_pair(a[i], b[i]));
		else
			arr.push_back(make_pair(a[i] / g, b[i] / g));
	}

	sort(arr.begin(), arr.end());

	int ans = 0;

	for(int i = 0; i < arr.size();)
	{
		int j = i;

		while(j + 1 < n && arr[j + 1] == arr[i])
			++j;

		ans = max(ans, j - i + 1);

		i = j + 1;
	}

	cout << ans + dlt << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}