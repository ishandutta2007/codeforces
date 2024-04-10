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

struct Line
{
	ll k, b;

	Line(): k(0), b(LL_INF)
	{
	}

	Line(ll _k, ll _b): k(_k), b(_b)
	{
	}

	ll apply(ll i)
	{
		return k * i + b;
	}
};

struct Node
{
	Line line;

	Node *left = nullptr, *right = nullptr;

	Node(Line _l): line(_l)
	{
	}
};

using pNode = Node*;

void lichao_ch(pNode& root, ll tl, ll tr, Line nl)
{
	if(root == nullptr)
	{
		root = new Node(nl);
	}
	else
	{
		ll tm = (tl + tr) / 2;

		bool left   = root->line.apply(tl) > nl.apply(tl);
		bool middle = root->line.apply(tm) > nl.apply(tm);

		if(middle)
			swap(nl, root->line);

		if(tl == tr)
			return;

		if(left != middle)
			lichao_ch(root->left, tl, tm, nl);
		else
			lichao_ch(root->right, tm + 1, tr, nl);
	}
}

ll lichao_get(pNode root, ll tl, ll tr, ll x)
{
	if(root == nullptr)
		return LL_INF;

	if(tl == tr)
		return root->line.apply(x);

	ll tm = (tl + tr) / 2;

	if(x <= tm)
		return min(root->line.apply(x), lichao_get(root->left, tl, tm, x));

	return min(root->line.apply(x), lichao_get(root->right, tm + 1, tr, x));
}

void stress()
{
	for(int epoche = 0;; ++epoche)
	{
		pNode root = nullptr;
		vector<Line> lines;

		for(int i = 0; i < (int)1e4; ++i)
		{
			Line nl(randint(-100, 100), randint(-100, 100));
			lines.push_back(nl);

			lichao_ch(root, 0, INT_INF, nl);

			ll x = randint(0, 1000);

			ll val1 = LL_INF;

			for(auto l: lines)
				val1 = min(val1, l.apply(x));

			ll val2 = lichao_get(root, 0, INT_INF, x);

			if(val1 != val2)
			{
				cout << "WA!!!" << endl;
				DBG(val1);
				DBG(val2);
				DBG(i);
				DBG(epoche);

				return;
			}
		}
	}
}

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n), b(n), dp(n, 0);

	for(auto& el: a)
		cin >> el;

	for(auto& el: b)
		cin >> el;

	pNode root = nullptr;
	
	for(int i = 0; i < n; ++i)
	{
		if(i > 0)
			dp[i] = lichao_get(root, 0, INT_INF, a[i]);

		lichao_ch(root, 0, INT_INF, Line(b[i], dp[i]));
	}

	cout << dp[n - 1] << endl;
}

int main(int argc, char** argv)
{
	/*stress();
	return 0;*/

	fast_io();
	solve();

	return 0;
}