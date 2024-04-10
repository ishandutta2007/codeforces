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

const int MAX_N = 106;
const int MAX_VAL = 61;
const int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
const int NPRIMES = sizeof(primes) / sizeof(int);

int a[MAX_N];

int dp[MAX_N][1 << NPRIMES], helper[MAX_N][1 << NPRIMES];
int getmsk[MAX_VAL + 1];

vector<int> good[1 << NPRIMES];

void solve()
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	for(int len = 1; len <= n; ++len)
	{
		for(int msk = 0; msk < (1 << NPRIMES); ++msk)
		{
			dp[len][msk] = INT_INF;

			for(int last : good[msk])
			{
				int msk2 = getmsk[last];

				if((msk2 & msk) != msk2)
					continue;

				//dp[len][msk] = min(dp[len][msk], dp[len - 1][msk ^ msk2] + abs(a[len - 1] - last));

				int nval = dp[len - 1][msk ^ msk2] + abs(a[len - 1] - last);

				if(nval < dp[len][msk])
				{
					dp[len][msk] = nval;
					helper[len][msk] = last;
				}
			}
		}
	}

#ifdef __LOCAL
	{
		int ans = dp[n][(1 << NPRIMES) - 1];

		DBG(ans);
	}
#endif

	vector<int> ans;

	int i = n;
	int bestmsk = (1 << NPRIMES) - 1;

	while(i != 0)
	{
		int last = helper[i][bestmsk];
		ans.push_back(last);

		bestmsk ^= getmsk[last];
		--i;
	}

	reverse(ans.begin(), ans.end());

	for(auto el: ans)
		cout << el << " ";

	cout << endl;
}

int main(int argc, char** argv)
{
	for(int i = 1; i <= MAX_VAL; ++i)
		for(int j = 0; j < NPRIMES; ++j)
			if(i % primes[j] == 0)
				getmsk[i] |= (1 << j);

	for(int msk = 0; msk < (1 << NPRIMES); ++msk)
		for(int val = 1; val <= MAX_VAL; ++val)
			if((getmsk[val] & msk) == getmsk[val])
				good[msk].push_back(val);

	DBG(NPRIMES);

	fast_io();
	solve();

	return 0;
}