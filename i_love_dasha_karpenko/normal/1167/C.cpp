#include <bits/stdc++.h>

using namespace std;
#define DIM 500007
#define INF 10E16
#define MAXN 10000007
#define MODULO 998244353 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];

ll n, m,all = 1,res = 0;
graph A, X;
arr V, D,C;

void dfs(ll x) {
	V[x] = all;
	res++;
	for (int i = 0; i < A[x].size(); i++) {
		ll k = A[x][i];
		if (C[k] == 0) {
			C[k] = 1;
			for (int j = 0; j < X[k].size(); j++) {
				ll v = X[k][j];
				if (V[v] == 0)dfs(v);
			}

		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		ll x,l;
		cin >> x;
		for (int j = 1; j <= x; j++) {
			cin >> l;
			A[l].push_back(i);
			X[i].push_back(l);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (V[i] == 0) {
			res = 0;
			dfs(i);
			D[all] = res;
			all++;
		}
		
		cout << D[V[i]] << ' ';
		
	}
}