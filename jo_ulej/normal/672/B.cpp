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
	string s;
	int answ = 0;
	int cnt[26];
	int used[26];

	memset(cnt, 0, sizeof(cnt));
	memset(used, 0, sizeof(cnt));

	int _;
	cin >> _ >> s;

	for(auto c: s)
		used[c - 'a'] = true;

	for(auto c: s)
	{
		c -= 'a';

		if(cnt[c])
		{
			for(int d = 0; d < 26; ++d)
			{
				if(!used[d])
				{
					c = d;
					used[c] = true;
					++answ;
					break;
				}
			}

			if(cnt[c])
			{
				cout << "-1" << endl;
				return;
			}
			else
			{
				++cnt[c];
			}
		}
		else
		{
			++cnt[c];
		}
	}

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}