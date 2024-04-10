#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
const int maxn = 100500;
typedef long long ll;
ll linf = 1e17;
typedef pair<int, int> pii;
#define se second
#define fi first
#define mp make_pair
#define top front

ll n;
ll k[maxn];
ll t[maxn];
ll c[maxn];
ll f[maxn];

queue<ll> kas[3], guy[3];

void scan();
void solve();

int main()
{
	//freopen("input.txt","r",stdin);
	ios :: sync_with_stdio(false);
	scan();
	solve();
};
void scan()
{
	forn(i, 3) cin >> k[i];
	forn(i, 3) cin >> t[i];
	cin >> n;
	forn(i, n) cin >> c[i];
	forn(i, 3) k[i] = min(k[i], n);
};
void solve()
{
	forn(i, 3) forn(j, k[i]) kas[i].push(0);
	forn(i, n) guy[0].push(i);
	forn(i, n) f[i] = c[i];
	
	ll cur = 0, mx = 0, cnt = 0;
	while (cnt != n)
	{
		//cout << endl;
		bool upd=0;
		ll mn = linf;
		forn(i, 3)
		{
			//cout << kas[i].top() << " ";
			if (!guy[i].empty() && f[guy[i].top()] <= cur && kas[i].top() <= cur)
			{
				upd = 1;
				kas[i].pop();
				kas[i].push(cur + t[i]);
				f[guy[i].top()] = cur+t[i];
				if (i == 2)
					cnt++;
				else
					guy[i+1].push(guy[i].top());
				guy[i].pop();
				upd = 1;
				break;
			}
			else if (!guy[i].empty())
				mn = min(mn, max(f[guy[i].top()], kas[i].top()));
		}
		if (!upd)
			cur = mn;
	}
	forn(i, n) mx = max(mx, f[i]-c[i]);
//	forn(i, n) cout << f[i] << " ";cout<<endl;
	cout << mx;
};