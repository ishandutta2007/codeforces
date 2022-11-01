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

const ll mod = 1e9 + 7;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

inline int check(const string& s)
{
	int minbal = 0, maxbal = 0;
	int bal = 0;

	for(auto& ch: s)
	{
		bal += (ch == '+' ? +1 : -1);

		minbal = (bal < minbal ? bal : minbal);
		maxbal = (bal > maxbal ? bal : maxbal);
	}

	return maxbal - minbal + 1;	
}

inline ll best(const string& s, bool left, bool right)
{
	int answ = check(s);

	int minbal = 0, maxbal = 0;
	int bal = 0;

	for(auto& ch: s)
	{
		bal += (ch == '+' ? +1 : -1);

		minbal = (bal < minbal ? bal : minbal);
		maxbal = (bal > maxbal ? bal : maxbal);
	}

	string t;
	bal = 0;

	for(auto& ch: s)
	{
		bal += (ch == '+' ? +1 : -1);

		if(bal == maxbal && left)
		{
			t.push_back('-');
			left = false;
		}

		if(bal == minbal && right)
		{
			t.push_back('+');
			right = false;
		}

		t.push_back(ch);
	}

	return min(answ, check(t));
}

void solve()
{
	string s;
	cin >> s;

	string hor, vert;

	for(auto& ch: s)
	{
		if(ch == 'W')
			vert.push_back('+');
		
		if(ch == 'S')
			vert.push_back('-');

		if(ch == 'D')
			hor.push_back('+');

		if(ch == 'A')
			hor.push_back('-');
	}

	ll answ = LL_INF;

	answ = min(answ, best(hor, true, false) * best(vert, false, false));
	answ = min(answ, best(hor, false, true) * best(vert, false, false));

	answ = min(answ, best(hor, false, false) * best(vert, true, false));
	answ = min(answ, best(hor, false, false) * best(vert, false, true));

	cout << answ << endl;	
}

int main()
{
	fast_io();

	int T;
	cin >> T;

	while(T--)
		solve();

	return 0;
}