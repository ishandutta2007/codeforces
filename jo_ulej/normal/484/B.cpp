#include <bits/stdc++.h>
 
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const ll mod = 1e9 + 7;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)1e6 + 5;

void solve()
{
	int n;
	cin >> n;

	vector<int> arr(n);

	for(auto& el: arr)
		cin >> el;

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	int ans = 0;

	for(int i: arr)
	{
		for(int j = i; j < MAX_N; j += i)
		{
			//int val = get(0, 1, MAX_N - 1, j, min(j + i - 1, MAX_N - 1));
			int idx = lower_bound(arr.begin(), arr.end(), j + i - 1) - arr.begin();

			if(idx == arr.size() || arr[idx] > j + i - 1)
				--idx;

			if(arr[idx] >= j)
				ans = max(ans, arr[idx] - j);
		}
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}