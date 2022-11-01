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

bool stupid(vector<int> a)
{
	int n = len(a);

	for(int i = 0; i < n; ++i)
	{
		if(a[i] > 0)
		{
			auto b = a;
			--b[i];
			
			bool ok = true;

			for(int i = 0; i < n; ++i)
				for(int j = 0; j < i; ++j)
					ok &= (b[i] != b[j]);

			if(!ok)
				continue;

			if(!stupid(b))
				return true;
		}
	}

	return false;
}

bool smart(vector<int> a)
{
	sort(a.begin(), a.end());
	int sum = 0, n = len(a), pointer = 0;
	int cnt2 = 0;

	for(int i = 0; i < n;)
	{
		int j = i;

		while(j + 1 < n && a[j + 1] == a[i])
			++j;

		int len = j - i + 1;

		if(len >= 3)
			return false;

		if(len == 2 && i > 0 && a[i - 1] == a[i] - 1)
			return false;

		if(len == 2 && a[i] == 0)
			return false;

		if(len == 2)
			++cnt2;

		if(cnt2 >= 2)
			return false;

		i = j + 1;
	}

	for(int i = 0; i < n; ++i)
	{
		if(pointer < a[i])
		{
			sum = (sum + a[i] - pointer) & 1;
			//DBG(a[i] - pointer);
			++pointer;
		}
		else
		{
			pointer = a[i] + 1;
		}
	}

	//DBG(pointer);
	//DBG(a);

	return sum;
}

void stress(int n, int maxc, int runs)
{
	vector<int> a(n);

	while(runs--)
	{
		for(auto& x: a)
			x = randint(0, maxc);

		bool stupid_answ = stupid(a);
		bool smart_answ = smart(a);

		if(stupid_answ != smart_answ)
		{
			cout << "WA!!" << endl;

			DBG(a);
			DBG(stupid_answ);
			DBG(smart_answ);

			exit(-1);
		}

		if(runs % 100 == 0)
			cout << "remaining: " << runs << endl;
	}

	cout << "stress passed" << endl;
}

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);

	for(auto& x: a)
		cin >> x;

	int answ = smart(a);

	cout << (answ ? "sjfnb" : "cslnb") << endl;
}

int main()
{
	fast_io();

#ifdef __LOCAL
	stress(22, 22, 1000);
#endif

	solve();

	return 0;
}