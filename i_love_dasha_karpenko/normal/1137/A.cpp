#include <bits/stdc++.h>

using namespace std;
#define DIM 1007
#define INF 100007
#define MAXN 107
#define LG 18
typedef int ll;
typedef long double ld;
typedef ll arr[DIM];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pair<ll, ll> pll;

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


ll n, m,A[DIM][DIM],GR[DIM][DIM],GC[DIM][DIM];
priority_queue<pll> Q;
arr R, C;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			cin >> A[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) 
			Q.push({ A[i][j],j });
		ll num = 0,last = INF;
		R[i] = 1;
		while (!Q.empty()) {
			GR[i][Q.top().second] = num;
			last = Q.top().first;
			Q.pop();
			if (!Q.empty() && Q.top().first != last) {
				num++; R[i]++;
			}
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++)
			Q.push({ A[i][j],i });
		ll num = 0,last = INF;
		C[j] = 1;
		while (!Q.empty()) {
			GC[Q.top().second][j] = num;
			last = Q.top().first;
			Q.pop();
			if (!Q.empty() && Q.top().first != last) {
				num++;
				C[j]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			GR[i][j] = R[i] - GR[i][j];
			GC[i][j] = C[j] - GC[i][j];
			if (GR[i][j] > GC[i][j]) {
				ll r = abs(GR[i][j] - GC[i][j]);
				cout << max(R[i], C[j] + r) << ' ';
			}
			else {
				ll r =abs( GR[i][j] - GC[i][j]);
				cout << max(R[i] + r, C[j])<<' ';
			}
		}
		cout << endl;
	}
}