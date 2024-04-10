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

void solve()
{
	int n, k;
	cin >> n >> k;

	vector<int> a(n);

	for(auto& el: a)
		cin >> el;

	int ans = INT_INF;
	vector<pii> ops;

	for(; k > 0; --k)
	{
		int minidx = 0, maxidx = 0;

		for(int i = 1; i < n; ++i)
		{
			if(a[i] > a[maxidx])
				maxidx = i;

			if(a[i] < a[minidx])
				minidx = i;
		}

		if(a[maxidx] - a[minidx] <= 1)
			break;

		--a[maxidx];
		++a[minidx];

		ops.emplace_back(maxidx + 1, minidx + 1);
		
	}

	ans = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());

	cout << ans << " " << ops.size() << endl;

	for(auto el: ops)
		cout << el.first << " " << el.second << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}