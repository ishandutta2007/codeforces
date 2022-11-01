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
	string str;
	cin >> str;

	int n = str.size();
	vector<int> z(n, 0);

	// computing z function
	{
		z[0] = n;
		int l = -1, r = -1;

		for(int i = 1; i < n; ++i)
		{
			if(i <= r)
				z[i] = min(z[i - l], r - i + 1);

			while(i + z[i] < n && str[i + z[i]] == str[z[i]])
				++z[i];

			if(i + z[i] - 1 > r)
				l = i, r = i + z[i] - 1;
		}
	}

	auto zsorted = z;
	sort(zsorted.begin(), zsorted.end());

	vector<pii> ans;

	for(int len = 1; len <= n; ++len)
	{
		if(z[n - len] == len)
		{
			int j = lower_bound(zsorted.begin(), zsorted.end(), len) - zsorted.begin();
			int c = n - j;

			ans.emplace_back(len, c);
		}
	}

	cout << ans.size() << endl;

	for(auto el: ans)
		cout << el.first << " " << el.second << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}