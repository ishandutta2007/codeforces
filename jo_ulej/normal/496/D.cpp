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

const int MAX_N = (int)1e5;
int a[MAX_N], prefsum[MAX_N], n;

inline int getsum(int l, int r)
{
	return (l == 0 ? prefsum[r] : prefsum[r] - prefsum[l - 1]);
}

inline bool check(int l, int r, int t)
{
	int sm = getsum(l, r);
	int len = r - l  + 1;

	return (sm >= t || len - sm >= t);
}

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	{
		int winner = a[n - 1];

		for(int i = 0; i < n; ++i)
			a[i] = (a[i] == winner ? 1 : 0);

		prefsum[0] = a[0];

		for(int i = 1; i < n; ++i)
			prefsum[i] = a[i] + prefsum[i - 1];
	}

	vector<pii> ans;

	for(int t = 1; t <= n; ++t)
	{
		int w1 = 0, w2 = 0;
		int i = 0;

		while(i < n)
		{
			int L = i, R = n - 1;
			int j;

			if(check(i, L, t))
			{
				j = L;
			}
			else if(!check(i, R, t))
			{
				break;
			}
			else
			{
				while(R - L > 1)
				{
					int M = (L + R) / 2;

					if(check(i, M, t))
						R = M;
					else
						L = M;
				}

				if(check(i, L, t))
					j = L;
				else
					j = R;
			}

			if(getsum(i, j) >= t)
				++w1;
			else
				++w2;

			DBG(t);
			DBG(i); DBG(j);

			i = j + 1;
		}

		DBG(w1);
		DBG(w2);
		DBG(i);

		if(i == n && w1 > w2)
			ans.emplace_back(w1, t);
	}

	sort(ans.begin(), ans.end());

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