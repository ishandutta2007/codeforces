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

	cin >> n;
	vector<int> a(n);

	for(auto& el: a)
		cin >> el;

	if(n == 1)
	{
		cout << "1" << endl;
		cout << "R" << endl;
		return;
	}

	if(a[0] == a[n - 1])
	{
		string answ1, answ2;

		for(int i = 0; i < n; ++i)
		{
			if(i > 0 && a[i] <= a[i - 1])
				break;

			answ1.push_back('L');
		}

		for(int j = n - 1; j >= 0; --j)
		{
			if(j < n - 1 && a[j] <= a[j + 1])
				break;

			answ2.push_back('R');
		}

		string answ = (answ1.size() > answ2.size() ? answ1 : answ2);

		cout << answ.size() << endl;
		cout << answ << endl;

		return;
	}

	int i = 0, j = n - 1;
	set<int> right;
	right.insert(a[j]);

	while(j - 1 > i && a[j - 1] > a[j] && a[j - 1] != a[i])
	{
		--j;
		right.insert(a[j]);
	}

	int besti = i, bestj = j, bestlen = (i + 1) + (n - j);

	for(;;)
	{
		++i;

		if(i >= n)
			break;

		if(a[i] <= a[i - 1])
			break;

		while(j < n && (right.count(a[i]) || j <= i))
		{
			right.erase(a[j]);
			++j;
		}

		assert(!right.count(a[i]));

		int len = (i + 1) + (n - j);

		if(len > bestlen)
			besti = i, bestj = j, bestlen = len;
	}

	deque<int> leftpart, rightpart;
	string answ;

	for(int i = 0; i <= besti; ++i)
		leftpart.push_back(a[i]);

	for(int j = n - 1; j >= bestj; --j)
		rightpart.push_back(a[j]);

	while(!leftpart.empty() && !rightpart.empty())
	{
		if(leftpart.front() <= rightpart.front())
		{
			answ.push_back('L');
			leftpart.pop_front();
		}
		else
		{
			answ.push_back('R');
			rightpart.pop_front();
		}
	}

	while(!leftpart.empty())
	{
		answ.push_back('L');
		leftpart.pop_front();
	}

	while(!rightpart.empty())
	{
		answ.push_back('R');
		rightpart.pop_front();
	}

	{
		string suffansw;

		for(int j = n - 1; j >= 0; --j)
		{
			if(j < n - 1 && a[j] <= a[j + 1])
				break;

			suffansw.push_back('R');
		}

		answ = (answ.size() > suffansw.size() ? answ : suffansw);
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