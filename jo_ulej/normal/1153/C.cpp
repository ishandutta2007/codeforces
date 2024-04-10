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

set<string> good;

void solve()
{
	int sz;
	string str, answ;
	cin >> sz >> str;

	if(sz == 2)
	{
		cout << (good.count(str) ? "()" : ":(") << endl;
		return;
	}

	vector<int> pref(sz, 0), prefmin(sz, 0);

	prefmin[0] = pref[0] = (str[0] == ')' ? -1 : 1);

	for(int i = 1; i < sz; ++i)
		pref[i] = pref[i - 1] + (str[i] == ')' ? -1 : 1);

	for(int i = 1; i < sz; ++i)
		prefmin[i] = min(pref[i], prefmin[i - 1]);

	vector<int> suff(sz, 0), suffmin(sz, 0);

	suffmin[sz - 1] = suff[sz - 1] = (str[sz - 1] == '(' ? 1 : -1);

	for(int i = sz - 2; i >= 0; --i)
	{
		suff[i] = suff[i + 1] + (str[i] == '(' ? 1 : -1);

		suffmin[i] = (str[i] == '(' ? 1 : -1) + min(0, suffmin[i + 1] * (i < sz - 2));
	}

	for(int split = 0; split + 1 < sz; ++split)
	{
		if(pref[split] + suff[split + 1] != 0)
			continue;

		if(prefmin[split] <= 0)
			continue;

		if(pref[split] + suffmin[split + 1] <= 0)
			continue;

		for(int i = 0; i < sz; ++i)
		{
			if(str[i] == '(' || str[i] == ')')
				answ.push_back(str[i]);
			else
				answ.push_back(i <= split ? '(' : ')');
		}

		break;
	}

	cout << (answ.empty() ? string(":(") : answ) << endl;
}

int main()
{
	good.insert(string("??"));
	good.insert(string("?)"));
	good.insert(string("()"));
	good.insert(string("(?"));

	fast_io();
	solve();

	return 0;
}