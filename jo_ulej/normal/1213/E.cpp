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

int n;
int bad[3][3];

bool check(const string& str)
{
	if(len(str) != 3 * n)
		return false;

	int cnt_a = 0, cnt_b = 0, cnt_c = 0;

	for(auto& ch: str)
	{
		switch(ch)
		{
			case 'a': ++cnt_a; break;
			case 'b': ++cnt_b; break;
			case 'c': ++cnt_c; break;
			default: return false;
		}
	}

	if(cnt_a != cnt_b || cnt_b != cnt_c)
		return false;

	for(int i = 0; i + 1 < 3 * n; ++i)
	{
		if(bad[str[i] - 'a'][str[i + 1] - 'a'])
			return false;
	}

	return true;
}

void solve()
{
	cin >> n;

	for(int t = 0; t < 2; ++t)
	{
		string forb;
		cin >> forb;

		++bad[forb.front() - 'a'][forb.back() - 'a'];
	}

	string ord = "abc";
	vector<string> ords;

	do
	{
		string answ;

		for(int i = 0; i < n; ++i)
			answ += ord;

		if(check(answ))
		{
			cout << "YES" << endl;
			cout << answ << endl;

			return;
		}

		answ.clear();

		for(auto& ch: ord)
		{
			for(int i = 0; i < n; ++i)
				answ.push_back(ch);
		}

		if(check(answ))
		{
			cout << "YES" << endl;
			cout << answ << endl;

			return;
		}

		ords.push_back(ord);
	}
	while(next_permutation(ord.begin(), ord.end()));

	for(int i = 0; i < len(ords); ++i)
	{
		for(int j = 0; j < len(ords); ++j)
		{
			string answ;

			for(int pos = 0; pos < n; ++pos)
				answ += (pos & 1 ? ords[i] : ords[j]);

			if(check(answ))
			{
				cout << answ << endl;
				return;
			}
		}
	}

	cout << "NO" << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}