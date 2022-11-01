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

const int MAX_N = 256 * 256 + 256 + 7;
vector<int> g[MAX_N];

int d[MAX_N];

vector<int> eulertour;

int getvertidx(char c1, char c2)
{
	return 256 * c1 + c2;
}

string getvertstr(int v)
{
	string ret;

	ret.push_back(v / 256);
	ret.push_back(v % 256);

	return ret;
}

void add_edge(int v, int u)
{
	g[v].push_back(u);

	--d[v];
	++d[u];
}

void euler(int v)
{
#ifdef __LOCAL
	shuffle(g[v].begin(), g[v].end(), _g);
#endif

	while(!g[v].empty())
	{
		int u = g[v].back();
		g[v].pop_back();

		euler(u);
	}

	eulertour.push_back(v);
}

bool check()
{
	for(int v = 0; v < MAX_N; ++v)
		if(!g[v].empty())
			return false;

	return true;
}

void solve()
{
	int n, fst = -1;
	string str;

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		int v = getvertidx(str[0], str[1]);
		int u = getvertidx(str[1], str[2]);
		fst = (fst == -1 ? v : fst);

		add_edge(v, u);
	}

	int cntnonzero = 0, ignore = 0;

	for(int v = 0; v < MAX_N; ++v)
		if(d[v])
			++cntnonzero;

	if(cntnonzero == 0)
	{
		euler(fst);

		if(!check())
		{
			cout << "NO" << endl;
			return;
		}
	
		reverse(eulertour.begin(), eulertour.end());

		for(auto el: eulertour)
			DBG(getvertstr(el));

		string ans;

		for(int i = 0; i < eulertour.size(); ++i)
		{
			if(!ans.empty())
				ans.pop_back();

			ans += getvertstr(eulertour[i]);
		}

		cout << "YES" << endl;
		cout << ans << endl;
	}
	else if(cntnonzero == 2)
	{
		int pos = -1, neg = -1;

		for(int v = 0; v < MAX_N; ++v)
		{
			if(!d[v])
				continue;

			if(d[v] == 1)
			{
				if(pos != -1)
				{
					cout << "NO" << endl;
					return;
				}

				pos = v;
			}
			else if(d[v] == -1)
			{
				if(neg != -1)
				{
					cout << "NO" << endl;
					return;
				}

				neg = v;
			}
			else
			{
				cout << "NO" << endl;
				return;
			}
		}

		if(pos == -1 || neg == -1)
		{
			cout << "NO" << endl;
			return;
		}

		DBG(getvertstr(pos));
		DBG(getvertstr(neg));

		add_edge(pos, neg);

		euler(fst);

		if(!check())
		{
			cout << "NO" << endl;
			return;
		}

		reverse(eulertour.begin(), eulertour.end());
		eulertour.pop_back();

		for(auto el: eulertour)
			DBG(getvertstr(el));

		string ans;

		for(int i = 0; i < eulertour.size(); ++i)
		{
			int j = (i + 1) % eulertour.size();

			if(eulertour[i] == pos && eulertour[j] == neg)
			{
				for(int step = 0; step < n + 1; ++step, j = (j + 1) % eulertour.size())
				{
					if(!ans.empty())
						ans.pop_back();

					ans += getvertstr(eulertour[j]);			
				}

				break;
			}
		}

		cout << "YES" << endl;
		cout << ans << endl;
	}
	else
	{
		cout << "NO" << endl;
		return;
	}

}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}