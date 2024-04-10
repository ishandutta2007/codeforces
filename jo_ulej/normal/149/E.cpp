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

vector<int> buildz(const string& s)
{
	int n = s.size();
	vector<int> z(n, 0);
	int l = -1, r = -1;

	for(int i = 1; i < n; ++i)
	{
		if(i <= r)
			z[i] = min(z[i - l], r - i + 1);

		while(i + z[i] < n && s[i + z[i]] == s[z[i]])
			++z[i];

		if(i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}

	return z;
}

string t;

string rev(string s)
{
	reverse(s.begin(), s.end());

	return s;
}

bool check(const string& s)
{
	if(s.size() < 2)
		return false;

	string prefcheck = s + "#" + t;
	string suffcheck = rev(s) + "#" + rev(t);

	auto z1 = buildz(prefcheck);
	auto z2 = buildz(suffcheck);
	DBG(z1);

	int n = t.size();
	vector<int> longestpref_temp(n, 0), longestsuff_temp(n, 0);

	for(int i = 0; i < n; ++i)
	{
		longestpref_temp[i] = z1[i + s.size() + 1];
		longestsuff_temp[n - i - 1] = z2[i + s.size() + 1];
	}

	vector<int> longestpref(n, 0), longestsuff(n, 0);

	for(int i = 0; i < n; ++i)
	{
		if(longestpref_temp[i])
		{
			int j = i + longestpref_temp[i] - 1;

			longestpref[j] = max(longestpref[j], longestpref_temp[i]);
		}

		if(longestsuff_temp[i])
		{
			int j = i - longestsuff_temp[i] + 1;

			longestsuff[j] = max(longestsuff[j], longestsuff_temp[i]);
		}
	}

	for(int i = n - 1; i > 0; --i)
		longestpref[i - 1] = max(longestpref[i - 1], longestpref[i] - 1);

	for(int i = 0; i < n - 1; ++i)
		longestsuff[i + 1] = max(longestsuff[i + 1], longestsuff[i] - 1);

	DBG(longestpref); DBG(longestsuff);

	vector<int> prefmax(n, -1), suffmax(n, -1);
	prefmax[0] = longestpref[0];
	suffmax[n - 1] = longestsuff[n - 1];

	for(int i = 1; i < n; ++i)
		prefmax[i] = max(prefmax[i - 1], longestpref[i]);

	for(int i = n - 2; i >= 0; --i)
		suffmax[i] = max(suffmax[i + 1], longestsuff[i]);

	for(int i = 0; i + 1 < n; ++i)
	{
		if(prefmax[i] == 0 || suffmax[i + 1] == 0)
			continue;

		int sm = prefmax[i] + suffmax[i + 1];

		if(sm >= s.size())
			return true;
	}

	return false;
}

void solve()
{
	int m, ans = 0;

	cin >> t >> m;

	for(; m > 0; --m)
	{
		string s;
		cin >> s;

		ans += check(s);
	}

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}