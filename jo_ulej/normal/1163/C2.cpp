#include <bits/stdc++.h>
 
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
#define gcd __gcd

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const ll mod = 1e9 + 7;
const ld eps = 1e-5;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

struct Line
{
	ll A, B, C;

	Line(ll _A, ll _B, ll _C): A(_A), B(_B), C(_C)
	{
	}

	bool operator<(const Line& other) const
	{
		return tie(A, B, C) < tie(other.A, other.B, other.C);
	}

	/*bool operator==(const Line& other) const
	{
		ll a1 = A, a2 = other.A;
		ll b1 = B, b2 = other.B;
		ll c1 = C, c2 = other.C;

		bool cond1 = (a2 * b1 == a1 * b2);
		bool cond2 = (b2 * c1 == b1 * c2);
		bool cond3 = (a2 * c1 == c2 * a1);

		return cond1 && cond2 && cond3;
	}*/

	bool operator==(const Line& other) const
	{
		return (A == other.A && B == other.B && C == other.C);
	}
};

Line getline(ll x1, ll y1, ll x2, ll y2)
{
	ll a = y1 - y2;
	ll b = x1 - x2;
	b = -b;

	ll g = gcd(a, b);
	a /= g, b /= g;

	if(a < 0)
		a = -a, b = -b;

	ll c = a * x1 + b * y1;

	return Line(a, b, c);
}

inline bool intr(Line& line1, Line& line2)
{
	return (line1.A * line2.B - line1.B * line2.A) != 0;
}

void solve()
{
	vector<pll> pts;
	int n;

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		ll x, y;
		cin >> x >> y;

		pts.emplace_back(x, y);
	}

	vector<Line> lines;

	for(auto pt1: pts)
		for(auto pt2: pts)
			if(pt1 != pt2)
				lines.push_back(getline(pt1.first, pt1.second, pt2.first, pt2.second));

	sort(lines.begin(), lines.end());
	lines.erase(unique(lines.begin(), lines.end()), lines.end());

	vector<pll> prs;

	for(auto L: lines)
		prs.emplace_back(L.A, L.B);

#ifdef __LOCAL
	for(auto L1: lines)
	{
		for(auto L2: lines)
		{
			if(!intr(L1, L2))
			{
				cout << "L1: " << L1.A << " " << L1.B << " " << L1.C << endl;
				cout << "L2: " << L2.A << " " << L2.B << " " << L2.C << endl;
			}
		}
	}
#endif

	for(auto& pr: prs)
	{
		if(pr.first == 0)
		{
			pr.second = 1;
		}
		else if(pr.second == 0)
		{
			pr.first = 1;
		}
		else
		{
			ll g = gcd(pr.first, pr.second);
			pr.first /= g, pr.second /= g;
		}

		if(pr.first < 0)
			pr.first = -pr.first, pr.second = -pr.second;

#ifdef __LOCAL
		cout << "pr: " << pr.first << " " << pr.second << endl;
#endif
	}

	ll answ = (ll)prs.size();
	answ *= answ;
	DBG(answ);

	sort(prs.begin(), prs.end());

	for(int i = 0; i < (int)prs.size();)
	{
		int j = i;

		while(j + 1 < (int)prs.size() && prs[j + 1] == prs[j])
			++j;

		ll len = j - i + 1;
		answ -= len * len;

		DBG(len);
		DBG(len * (len - 1));

		i = j + 1;
	}

	cout << answ / 2 << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}