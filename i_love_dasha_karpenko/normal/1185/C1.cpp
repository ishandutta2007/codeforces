#include <bits/stdc++.h>

using namespace std;
#define DIM  107
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

ll n, m;
arr A;
priority_queue<ll> Q,Q1;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		
		ll t = m - A[i];
		ll r = sum - t;
		if (r <= 0) {
			cout << 0 << ' ';
			sum += A[i];
			Q.push(A[i]);
			continue;
		}
		ll s = 0;
		Q1 = Q;
		ll e = 0;
		while (s < r) {
			s += Q1.top();
			Q1.pop();
			e++;
		}
		cout << e << ' ';
		sum += A[i];
		Q.push(A[i]);
	}
}