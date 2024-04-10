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

int cnt[3];

bool is_prime(int x)
{
	if(x == 1)
		return false;

	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0)
			return false;

	return true;
}

void solve()
{
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		++cnt[v];
	}

	vector<int> answ;
	int curpref = 0;

	while(cnt[1] > 0 && cnt[2] > 0)
	{
		if(is_prime(curpref + 1))
		{
			answ.push_back(1);
			++curpref;
			--cnt[1];
		}
		else
		{
			answ.push_back(2);
			curpref += 2;
			--cnt[2];
		}
	}

	for(int t = 1; t <= 2; ++t)
	{
		while(cnt[t] > 0)
		{
			answ.push_back(t);
			--cnt[t];
		}
	}

#ifdef __LOCAL
	{
		int pcnt = 0;
		int pref = 0;

		for(auto el: answ)
		{
			pref += el;
			pcnt += is_prime(pref);
		}

		DBG(pcnt);
	}
#endif

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}