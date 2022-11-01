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
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

void solve()
{
	string str;
	cin >> str;
	int n = str.size();

	vector<int> prefsum(n + 1, 0);

	for(int i = 1; i <= n; ++i)
		prefsum[i] = prefsum[i - 1] + (str[i - 1] == ')' ? -1 : 1);

	vector<int> nxtls(n + 1, n + 1);
	stack<int> st;

	for(int i = 0; i <= n; ++i)
	{
		while(!st.empty() && prefsum[st.top()] >= prefsum[i])
		{
			nxtls[st.top()] = i;
			st.pop();
		}

		st.push(i);
	}

	int bestlen = 0, bestlencnt = 0;
	vector<bool> met(n + 1, false);

	for(int i = 0; i <= n; ++i)
	{
		if(met[i])
			continue;

		met[i] = true;

		int j = i;

		while(nxtls[j] <= n && prefsum[nxtls[j]] == prefsum[j])
		{
			j = nxtls[j];
			met[j] = true;
		}

		int len = j - i;

		if(len > bestlen)
		{
			bestlen = len;
			bestlencnt = 1;
		}
		else if(len == bestlen)
		{
			++bestlencnt;
		}
	}

	cout << bestlen << " " << (bestlen == 0 ? 1 : bestlencnt) << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}