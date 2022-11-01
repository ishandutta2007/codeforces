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
#include <queue>

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

const ll mod = 1e9 + 7;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

inline int get(const string& str)
{
	int n = len(str), answ = 0;
	vector<int> dp(n, 1);

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			if(str[j] <= str[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}

		answ = max(answ, dp[i]);
	}

	return answ;
}

inline bool valid(const string& s, const string& t)
{
	DBG("checking");

	if(len(s) != len(t))
		return false;

	for(auto& ch: s)
	{
		if(ch != '0' && ch != '1')
			return false;		
	}

	for(auto& ch: t)
	{
		if(ch != '0' && ch != '1')
			return false;		
	}

	for(int l = 0; l < len(s); ++l)
	{
		for(int r = l; r < len(s); ++r)
		{
			string a = s.substr(l, r - l + 1);
			string b = t.substr(l, r - l + 1);

			if(get(a) != get(b))
			{
				DBG(a);
				DBG(get(a));

				DBG(b);
				DBG(get(b));

				return false;
			}
		}
	}

	return true;	
}

void solve()
{
	string str;
	cin >> str;

	int n = len(str);
	string answ = str;

	vector<int> stack;

	for(int i = 0; i < n; ++i)
	{
		if(!stack.empty() && str[i] < str[stack.back()])
		{
			stack.pop_back();
		}
		else
		{
			stack.push_back(i);
		}
	}

	for(auto& ind: stack)
	{
		if(answ[ind] == '1')
			answ[ind] = '0';
	}

	cout << answ << endl;

#ifdef __LOCAL
	assert(valid(str, answ));
#endif
}

int main()
{
	fast_io();
	solve();

	return 0;
}