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

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)1e6 + 777;

ll a[MAX_N];
int n, w;

const int ADD = 1000;
const int DEL = -1000;

struct Event
{
	int type;
	int coord;
	ll change;

	Event(): type(NIL), coord(NIL), change(NIL)
	{
	}

	Event(int _type, int _coord, ll _change): type(_type), coord(_coord), change(_change)
	{
	}

	inline bool operator<(const Event& other) const
	{
		return make_pair(coord, type) < make_pair(other.coord, other.type);	
	}
};

Event events[2 * MAX_N];
int cnt = 0;

inline void register_event(int l, int r, ll change)
{
	events[cnt++] = Event(ADD, l, change);
	events[cnt++] = Event(DEL, r + 1, change);
}

void solve()
{
	cin >> n >> w;

	for(int i = 0; i < n; ++i)
	{
		cnt = 0;

		int sz;
		cin >> sz;

		for(int j = 0; j < sz; ++j)
		{
			ll change;
			cin >> change;

			register_event(j, w + j - sz, change);
		}

		if(sz < w)
		{
			register_event(0, w - sz - 1, 0);
			register_event(sz, w - 1, 0);
		}

		sort(events, events + cnt);
		multiset<ll> setik;

		for(int i = 0; i < cnt;)
		{
			int j = i;

			for(; j < cnt && events[j].coord == events[i].coord; ++j)
			{
				if(events[j].type == ADD)
				{
					setik.insert(events[j].change);
				}
				else
				{
					auto iter = setik.find(events[j].change);
					setik.erase(iter);
				}
			}	

			if(!setik.empty())
			{
				int l = events[i].coord;
				int r = events[j].coord - 1;

				ll max = *(prev(setik.end()));

				a[l] += max;
				a[r + 1] -= max;
			}

			i = j;
		}
	}

	ll answ = 0;

	for(int i = 0; i < w; ++i)
	{
		answ += a[i];
		cout << answ << " ";
	}

	cout << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}