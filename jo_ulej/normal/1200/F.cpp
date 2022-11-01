#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
	#define DBG(X) cout << #X << "=" << (X) << endl;
#else
	#define DBG(X)
	#define endl '\n'
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MOD = 2520;

inline int norm(int x)
{
	int r = x % MOD;

	return (r < 0 ? r + MOD : r);
}

inline int add(int x, int y)
{
	int r = x + y;

	return (r >= MOD ? r - MOD : r);
}

const int MAX_N = 1007;
const int MAX_M = 20;
using state = pii; // {vertex, counter}

int go[MAX_N][MAX_M];
int k[MAX_N], n, m[MAX_N];

state next(const state& st)
{
	int v = st.first;
	int c = st.second;
	c = add(c, k[v]);

	return {go[v][c % m[v]], c};
}

const int MAX_STATES = MOD * MAX_N + 13;

state pool[MAX_STATES];
int nxt[MAX_STATES];
int n_states = 0;

bool met[MAX_STATES];

int ord[MAX_STATES];
int ord_sz = 0;

int sz[MAX_STATES], dp[MAX_STATES];

vector<int> prv[MAX_STATES];

int stack1[MAX_STATES], stack2[MAX_STATES], stack3[MAX_STATES];
int ptr1 = 0, ptr2 = 0, ptr3 = 0;

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> k[i];
		k[i] = norm(k[i]);
	}	

	for(int i = 0; i < n; ++i)
	{
		cin >> m[i];

		for(int j = 0; j < m[i]; ++j)
		{
			cin >> go[i][j];
			--go[i][j];
		}	
	}

	for(int v = 0; v < n; ++v)
	{
		for(int c = 0; c < MOD; ++c)
			pool[n_states++] = {v, c};
	}

	for(int i = 0; i < n_states; ++i)
	{
		state s2 = next(pool[i]);

		nxt[i] = lower_bound(pool, pool + n_states, s2) - pool;
		prv[nxt[i]].push_back(i);

		//cout << i << " -> " << nxt[i] << endl;
	}

	for(int i = 0; i < n_states; ++i)
	{
		//vector<int> st;
		ptr1 = 0;

		for(int j = i; !met[j]; j = nxt[j])
		{
			//st.push_back(j);
			stack1[ptr1++] = j;

			met[j] = true;
		}

		//reverse(st.begin(), st.end());

		//for(auto& v: st)
		while(ptr1 > 0)
			ord[ord_sz++] = stack1[--ptr1];
	}

	memset(met, 0, sizeof(met));

	for(int i = ord_sz - 1; i >= 0; --i)
	{
		if(met[ord[i]])
			continue;

		set<int> setik;

		//vector<int> all, st = {ord[i]};
		ptr1 = 0;
		ptr2 = 0;
		ptr3 = 0;

		stack1[ptr1++] = ord[i];

		//vector<int> diff;

		//while(!st.empty())
		while(ptr1 > 0)
		{
			int v = stack1[--ptr1]; //st.back();
			//st.pop_back();

			met[v] = true;
			//all.push_back(v);
			stack2[ptr2++] = v;
			//diff.push_back(pool[v].first);
			//stack3[ptr3++] = pool[v].first;
			setik.insert(pool[v].first);

			for(auto& u: prv[v])
			{
				if(!met[u])
					//st.push_back(u);		
					stack1[ptr1++] = u;
			}
		}

		//sort(diff.begin(), diff.end());
		//sort(stack3, stack3 + ptr3);
		//int cnt = 0;

		/*for(int i = 0; i < ptr3; ++i)
			cnt += (i == 0 || stack3[i] != stack3[i - 1]);*/

		//for(auto& v: all)
		while(ptr2 > 0)
			sz[stack2[--ptr2]] = len(setik);
	}

	for(int i = 0; i < ord_sz; ++i)
	{
		int v = ord[i];
		int u = nxt[v];
	
		dp[v] = sz[u];
		
		if(dp[v] == 1)
			dp[v] = max(dp[v], dp[u]);
	}

	int q;
	cin >> q;

	while(q--)
	{
		int v, c;
		cin >> v >> c;

		--v;
		c = norm(c);

		state st = {v, c};
		int i = lower_bound(pool, pool + n_states, st) - pool;

		cout << dp[i] << endl;
	}
}

int main()
{
	fast_io();
	solve();

	return 0;
}