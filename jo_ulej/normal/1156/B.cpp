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

#define endl '\n'

bool check(string s)
{
	for(int i = 0; i + 1 < (int)s.size(); ++i)
		if(abs((int)s[i] - (int)s[i + 1]) == 1)
			return false;
	return true;
}

void solve()
{
	int t;
	cin >> t;

	for(; t > 0; --t)
	{
		string s;
		cin >> s;

		int cnt[26];
		memset(cnt, 0, sizeof(cnt));

		for(auto chr: s)
			++cnt[chr - 'a'];

		string answ1, answ2;

		for(int m = 1; m >= 0; --m)
		{
			for(int cd = 0; cd < 26; ++cd)
			{
				if(cd % 2 != m)
					continue;

				for(int i = 0; i < cnt[cd]; ++i)
					answ1.push_back(cd + 'a');
			}
		}

		for(int m = 0; m <= 1; ++m)
		{
			for(int cd = 0; cd < 26; ++cd)
			{
				if(cd % 2 != m)
					continue;

				for(int i = 0; i < cnt[cd]; ++i)
					answ2.push_back(cd + 'a');
			}
		}

		if(check(answ1))
		{
			cout << answ1 << endl;
			continue;
		}

		if(check(answ2))
		{
			cout << answ2 << endl;
			continue;
		}

		cout << "No answer" << endl;
	}
}

int main()
{
	fast_io();
	solve();

	return 0;
}