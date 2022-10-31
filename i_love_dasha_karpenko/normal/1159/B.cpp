#include <bits/stdc++.h>

using namespace std;
#define DIM 300007
#define INF 10000000000000007
#define MAXN 10000007
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
ll n;
parr A;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A + 1, A + 1 + n);
	ll maxk = INF;
	ll r;
	for (int i = 1; i <= n; i++) {
		r = max(abs(1 - A[i].second), abs(n - A[i].second));
		maxk = min(maxk, A[i].first / r);
	}
	cout << maxk << endl;
}