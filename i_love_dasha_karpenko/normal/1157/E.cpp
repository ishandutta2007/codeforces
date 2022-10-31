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
arr A;
map<ll,ll> M;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> A[i];
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		M[x]++;
	}
	for (int i = 1; i <= n; i++) {
		auto it = M.lower_bound(n - A[i]);
		if (it == M.end())it = M.begin();
		cout << (A[i] + (*it).first) % n << ' ';
		M[(*it).first]--;
		if ((*it).second == 0)
			M.erase((*it).first);
	}
}