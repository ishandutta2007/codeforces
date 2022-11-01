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

void solve()
{
	int n;
	deque<int> a;
	string answ;
	vector<int> temp = {-INT_INF};

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int value;
		cin >> value;
		a.push_back(value);
	}

	while(!a.empty())
	{
		int left = a.front(), right = a.back();

		if(left <= temp.back())
		{
			if(right <= temp.back())
			{
				break;
			}
			else
			{
				a.pop_back();
				answ.push_back('R');
				temp.push_back(right);
			}
		}
		else if(right <= temp.back())
		{
			if(left <= temp.back())
			{
				break;
			}
			else
			{
				a.pop_front();
				answ.push_back('L');
				temp.push_back(left);
			}
		}
		else
		{
			if(left <= right)
			{
				a.pop_front();
				answ.push_back('L');
				temp.push_back(left);
			}
			else
			{
				a.pop_back();
				answ.push_back('R');
				temp.push_back(right);
			}
		}
	}

	cout << answ.size() << endl;
	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}