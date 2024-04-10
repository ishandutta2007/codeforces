#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 10E16
#define MAXN 10000007
#define MODULO 998244353 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];

ll n;
arr A, B;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		A[i] *= (n - i + 1) * i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> B[i];
	}
	sort(A + 1, A + 1 + n);
	sort(B + 1, B + 1 + n);
	ll res = 0;
	ll x = n;
	for (int i = 1; i <= n; i++) {
		A[x] %= MODULO;
		B[i] %= MODULO;
		res += (A[x] * B[i]);
		res %= MODULO;
		x--;
	}
	cout << res << endl;
}