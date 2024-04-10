#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

struct Dish
{
	ll cost, cnt;
	int idx;

	bool operator<(const Dish& other)
	{
		if(cost != other.cost)
			return cost < other.cost;

		if(idx != other.idx)
			return idx < other.idx;

		return cnt < other.cnt;
	}
};

vector<Dish> dishes;
vector<int> f;
int n, m;

void solve()
{
	cin >> n >> m;

	vector<ll> a(n), c(n);

	for(auto& el: a)
		cin >> el;

	for(auto& el: c)
		cin >> el;

	for(int i = 0; i < n; ++i)
	{
		Dish d;

		d.cost = c[i];
		d.cnt  = a[i];
		d.idx  = i;

		dishes.push_back(d);
	}

	sort(dishes.begin(), dishes.end());

	f.resize(n);

	for(int i = 0; i < n; ++i)
		f[dishes[i].idx] = i;

	int w = 0;

	string answer;

	for(int j = 0; j < m; ++j)
	{
		ll tot = 0;
		int t, d;

		cin >> t >> d;
		--t;

		int i = f[t];

		if(dishes[i].cnt > 0)
		{
			if(dishes[i].cnt >= d)
			{
				dishes[i].cnt -= d;

				tot += dishes[i].cost * d;
				d = 0;
			}
			else
			{
				tot += dishes[i].cost * dishes[i].cnt;
				d -= dishes[i].cnt;
				dishes[i].cnt = 0;
			}
		}

		while(d > 0)
		{
			while(w < n && dishes[w].cnt == 0)
				++w;

			if(w >= n)
				break;

			if(dishes[w].cnt > 0)
			{
				if(dishes[w].cnt >= d)
				{
					dishes[w].cnt -= d;

					tot += dishes[w].cost * d;
					d = 0;
				}
				else
				{
					tot += dishes[w].cost * dishes[w].cnt;
					d -= dishes[w].cnt;
					dishes[w].cnt = 0;
				}
			}
		}

		if(d > 0)
			tot = 0;

		answer += to_string(tot) + "\n";
	}

	cout << answer;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}