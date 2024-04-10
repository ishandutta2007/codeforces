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

const int MAX_N = (int)1e5 + 77;

int a[MAX_N], counter[MAX_N], counter2[MAX_N];
int n;

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	int nonzero = 0;
	int answ = 1;

	for(int i = 0; i < n; ++i)
	{
		if(counter[a[i]])
			--counter2[counter[a[i]]];

		++counter[a[i]];

		if(counter[a[i]] == 1)
			++nonzero;

		++counter2[counter[a[i]]];
		DBG(counter2[counter[a[i]]]);

		if(nonzero < 1)
			continue;

		DBG(i); DBG(nonzero);

		if(nonzero > 0 && i % nonzero == 0)
		{
			int l = i / nonzero;

			if(l < 0)
				continue;

			bool good = true;

			good &= counter2[l] == nonzero - 1;
			good &= counter2[l + 1] == 1;

			if(good)
				answ = max(answ, i + 1);
		}

		if(nonzero > 1 && i % (nonzero - 1) == 0)
		{
			int l = i / (nonzero - 1);

			if(l < 0)
				continue;

			bool good = true;

			good &= counter2[l] == nonzero - 1;
			good &= counter2[1] == 1;

			if(good)
				answ = max(answ, i + 1);
		}

		if(nonzero > 1 && i == nonzero - 1)
		{
			if(counter2[1] == nonzero)
				answ = max(answ, i + 1);
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