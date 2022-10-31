#include <bits/stdc++.h>

using namespace std;
#define DIM 300007
#define INF 10E16
#define MAXN 64
#define MODULO 1000000007 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];
typedef vector<ll> vec;
struct pp { ll a, b; };
ll n;
arr C,V,R;
graph A;
vec T;
void topsort(ll x) {
	V[x] = 1;
	for (int i : A[x]) {
		if (V[i] == 0)topsort(i);
	}
	T.push_back(x);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> C[i];
	for (int i = 2; i <= n; i++) {
		ll x; cin >> x;
		A[x].push_back(i);
	}
	topsort(1);
	memset(V, 0, sizeof(V));
	ll num = 0;
	for (int i : T) {
		if (A[i].size() == 0)num++;
	}
	for (int i : T) {
		if (A[i].size() == 0) {
			R[i] = 1;
		}
		else {
			ll val = INF;
			if (C[i] == 0) {
				for (int j : A[i]) 
					R[i] += R[j];
			}
			else {
				val = INF;
				for (int j : A[i])val = min(val, R[j]);
				R[i] = val;
			}
		}
	}
	cout << num - R[1]+1 << endl;
}