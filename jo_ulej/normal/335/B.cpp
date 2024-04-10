#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }

const int MAX_N = 3000;

string str, output;
int cnt[26], dp[MAX_N][MAX_N];

void build(int l, int r)
{
	if(l == r)
	{
		output.push_back(str[l]);
	}
	else if(l + 1 == r)
	{
		output.push_back(str[l]);

		if(str[l] == str[r])
			output.push_back(str[r]);
	}
	else
	{
		if(str[l] == str[r] && dp[l + 1][r - 1] + 2 > max(dp[l + 1][r], dp[l][r - 1]))
		{
			output.push_back(str[l]);
			build(l + 1, r - 1);
			output.push_back(str[r]);

			return;
		}

		if(dp[l + 1][r] > dp[l][r - 1])
			build(l + 1, r);
		else
			build(l, r - 1);
	}
}

void solve()
{
	cin >> str;
	int n = str.size();
	
	//int n = 4e5;
	//str.resize(n, 'w');
	
	if(n > MAX_N)
	{
		for(int i = 0; i < n; ++i)
			++cnt[str[i] - 'a'];

		for(int i = 0; i < 26; ++i)
		{
			if(cnt[i] >= 100)
			{
				for(int j = 0; j < 100; ++j)
					cout << (char)('a' + i);

				cout << endl;
				return;
			}
		}
	}

	for(int l = n - 1; l >= 0; --l)
	{
		dp[l][l] = 1;

		if(l == n - 1)
			continue;

		dp[l][l + 1] = 1 + (str[l] == str[l + 1]);

		for(int r = l + 2; r < n; ++r)
		{
			dp[l][r] = max(dp[l][r - 1], dp[l + 1][r]);

			if(str[l] == str[r])
				dp[l][r] = max(dp[l][r], 2 + dp[l + 1][r - 1]);
		}
	}

	int bestl = 0, bestr = 0;

	for(int l = 0; l < n; ++l)
		for(int r = l; r < n; ++r)
			if(dp[l][r] > dp[bestl][bestr])
				bestl = l, bestr = r;

	DBG(dp[bestl][bestr]);

	build(bestl, bestr);

	while(output.size() > 100)
	{
		if(output.size() % 2 != 0)
		{
			int k = output.size() / 2;

			string a = output.substr(0, k);
			string b = output.substr(k + 1, k);

			output = a + b;
		}
		else
		{
			output = output.substr(1, output.size() - 2);
		}
	}

	cout << output << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}