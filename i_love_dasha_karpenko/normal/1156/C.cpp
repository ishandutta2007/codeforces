#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 10E16
#define MAXN 10000007
#define MODULO 1000000007 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];
struct pp { ll a, b; };

ll n, z;
arr A;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n>>z;
	for (int i = 1; i <= n; i++)cin >> A[i];
	sort(A + 1, A + 1 + n);
	ll p = n / 2;
	ll res = 0;
	for (int i = 1; i <= n / 2; i++) {
		while (A[p] - A[i] < z && p<=n)p++;
		if (p > n) break;
		res++;
		p++;
	}
	cout << res << endl;	
}