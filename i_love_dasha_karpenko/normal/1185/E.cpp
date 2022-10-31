#include <bits/stdc++.h>

using namespace std;
#define DIM  2007
#define DIM2 107
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 1000000007
#define MODULO2 MODULO*2
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
struct pp {
	ll a, b;
	bool operator <(const pp& V)const {
		if (a == V.a)return b < V.b;
		return a < V.a;
	}
	bool operator ==(const pp& V)const {
		if (a == V.a && b == V.b)return 1;
		return 0;
	}
};

ll t,n,m;
ll A[DIM][DIM];
vector<pll> V[27];
queue<pll> ans,Q;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	for (int u = 1; u <= t; u++) {
		cin >> n >> m;
		while (!ans.empty())ans.pop();
		for (int i = 1; i <= 26; i++)V[i].resize(0);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				char x;
				cin >> x;
				if (x == '.')A[i][j] = 0;
				else {
					A[i][j] = x-96;
				}
				if (A[i][j] != 0) {
					V[A[i][j]].push_back({ i,j });
				}
			}
		ll F = 0;
		ll st = 0; pll p1, p2;
		for (int i = 1; i <= 26; i++) {
			if (V[i].size() == 0)st++;
			else {
				pll x = V[i][0];
				for (int j = 0; j < st; j++) {
					ans.push(x);
					ans.push(x);
				}
				st = 0;
			}
			if (V[i].size() == 1) {
				pll x = V[i][0];
				ans.push(x);
				ans.push(x);
			}
			if (V[i].size() > 1) {
				ll x = V[i][0].first, y = V[i][0].second, x2 = V[i][1].first, y2 = V[i][1].second,r=  1;
				ans.push(V[i][0]); ans.push(V[i][V[i].size()-1]);
				if (x == x2) {
					for (int j = y+1; j <= m; j++) {
						if (A[x][j] == i)r++;
						if (A[x][j] < i)break;
					}
					
				}
				else if (y == y2) {
					for (int j = x+1; j <= n; j++) {
						if (A[j][y] == i)r++;
						if (A[j][y] < i)break;
					}
					
				}
				if (r != V[i].size())F = 1;
			}
			if (F == 1) {
				cout << "NO" << endl;
				break;
			}
		}
		if (F == 1)continue;
		else {
			cout << "YES" << endl;
			cout << ans.size() / 2 << endl;
			while (!ans.empty()) {
				pll a = ans.front();
				cout << a.first << ' ' << a.second<<' ';
				ans.pop();
				a = ans.front();
				cout << a.first << ' ' << a.second << endl;
				ans.pop();
			}
		}
	}
}