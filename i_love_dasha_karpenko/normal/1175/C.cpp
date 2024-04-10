#include <bits/stdc++.h>

using namespace std;
#define DIM  200007
#define DIM2 507
#define INF 4294967296
#define MAXN 107
#define LG 18
#define MODULO 1000000007
typedef long long  ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
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
ll t,n,k;
arr A;
int main()

{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	//t *= 2;
	for (int h = 1; h <= t; h++) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)cin >> A[i];
		ll res=INF, x;
		for (int i = 1; i+k <= n; i++) {
			if (A[i + k] - A[i] < res * 2) {
				res = (A[i + k] - A[i]) / 2;
				if ((A[i + k] - A[i]) % 2 != 0)res++;
				x = A[i] + res;
			}
		}
		cout << x << endl;
	}
}
// 011 1