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

int cnt[(int)1e6];

void solve()
{
	int n;
	cin >> n;

	vector<int> vec(n), ans1, ans2;

	for(auto& el: vec)
		cin >> el;

	for(auto el: vec)
	{
		if(cnt[el] == 0)
		{
			ans1.push_back(el);
		}
		else if(cnt[el] == 1)
		{
			ans2.push_back(el);
		}
		else
		{
			cout << "NO" << endl;
			return;
		}

		++cnt[el];
	}

	cout << "YES" << endl;
	sort(ans1.begin(), ans1.end());
	sort(ans2.rbegin(), ans2.rend());

	cout << ans1.size() << endl;
	cout << ans1 << endl;

	cout << ans2.size() << endl;
	cout << ans2 << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}