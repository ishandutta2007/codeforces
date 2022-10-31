#include <bits/stdc++.h>

using namespace std;
#define DIM 200007
#define INF 10E16
#define MAXN 10000007
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];

ll n, x, y,res = 0;
string num;
arr A;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	sort(A + 1, A + 1 + n);
	ll res = 0;
	ll j=1;
	for (int i = 1; i <= n; i++) {
		while (A[j] < i && j<=n)j++;
		if (A[j] >= i) {
			res++; j++;
		}
		else break;
	}
	cout << res << endl;
}