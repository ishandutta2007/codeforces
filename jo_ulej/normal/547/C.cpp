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

const int MAX_N = (int)5e5 + 7;

int vals[MAX_N], cnt[MAX_N], has[MAX_N];
int n, m;
ll curnum = 0, ans = 0;

vector<int> factor(int x)
{
	vector<int> ret;

	while(x > 1)
	{
		int i = 2;

		while(i * i <= x)
		{
			if(x % i != 0)
				++i;
			else
				break;
		}

		if(x % i != 0)
			i = x;

		ret.push_back(i);

		while(x % i == 0)
			x /= i;
	}

	return ret;
}

vector<int> divs(int x)
{
	vector<int> ret;

	for(int i = 1; i * i <= x; ++i)
	{
		if(x % i == 0)
		{
			ret.push_back(i);

			if(i != x / i)
				ret.push_back(x / i);
		}
	}

	return ret;
}

ll get(int x)
{
	ll ret = 0;
	auto fct = factor(x);
	int sz = fct.size();

	for(int msk = 1; msk < (1 << sz); ++msk)
	{
		int num = 1, temp = 0;

		for(int i = 0; i < sz; ++i)
			if(msk & (1 << i))
				num *= fct[i], ++temp;

		ret += ((temp & 1) ? cnt[num] : -cnt[num]);
	}

	DBG(x); DBG(ret);
	return ret;
}

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
		cin >> vals[i];

	string output;

	for(; m > 0; --m)
	{
		int idx;
		cin >> idx;
		--idx;

		int x = vals[idx];
		int d = (has[idx] ? -1 : 1);

		ans += d * get(x) + (d < 0 && x != 1);
		curnum += d;

		for(auto i: divs(x))
			cnt[i] += d;

		has[idx] ^= 1;

		output += to_string((curnum * (curnum - 1)) / 2 - ans) + "\n";
	}

	cout << output;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}