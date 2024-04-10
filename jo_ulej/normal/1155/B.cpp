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
	int n;
	string s;
	cin >> n >> s;

	int steps = n - 11;
	int petya = steps / 2;
	int vasya = steps - petya;

	int cnt8 = 0;

	for(auto chr: s)
		cnt8 += (chr == '8');

	DBG(cnt8); DBG(petya);

	if(cnt8 <= petya)
	{
		cout << "NO" << endl;
		return;
	}

	int lst = -1, temp = 0;

	for(int i = 0; i < n; ++i)
	{
		temp += (s[i] == '8');

		if(temp == petya + 1)
		{
			lst = i;
			break;
		}
	}

	DBG(lst);

	if(vasya + petya < lst)
	{
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}