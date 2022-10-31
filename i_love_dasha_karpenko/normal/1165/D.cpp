#include <bits/stdc++.h>

using namespace std;
#define DIM 307
#define INF 10E16
#define MAXN 10000007
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pairll;
typedef ll arr[DIM];
typedef pairll parr[DIM];
typedef vector<ll> graph[DIM];

ll n, t, num = 1, gcd;
vector<ll> V;
set<ll> S;
arr R;
ll __gcd(ll x, ll y) {
	while (x > 0 && y > 0) {
		if (x > y)x %= y;
		else y %= x;
	}
	return x + y;
}

int Check(ll x) {

	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			if (S.count(i) == 0) {
				return 1;
			}
			if (x % (x / i) == 0) {
				if (S.count(x / i) == 0)return 1;
			}
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	for (int h = 0; h < t; h++) {
		cin >> n;
		num = 1;
		V.clear();
		V.resize(n + 7);
		S.clear();
		S.insert(1);
		for (int i = 1; i <= n; i++) {
			cin >> V[i];
		}
		sort(V.begin() + 1, V.begin() + n+1);
		for (int i = 1; i <= n; i++) {
			gcd = __gcd(num, V[i]);
			S.insert(V[i]);
			num = num / gcd * V[i];
			if (num < 0) {
				cout << -1 << endl;
				goto link;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (Check(V[i])) {
				cout << -1 << endl;
				goto link;
			}
		}
		if (num == V[n]) {
			for (int i = 1; i <= n; i++) {
				ll flag = 0;
				for (int j = 1; j <= n; j++) {
					if (V[i] * V[j] >= num*V[i])break;
					if (S.count(V[i] * V[j]) == 0 && V[i]*V[j]<num*V[i]) {
						flag = 1; break;
					}
				}
				if (flag == 0) {
					num *= V[i];
					break;
				}
			}
		}
		if (num == V[n]) {
			cout << -1 << endl;
			goto link;	
		}
		for (ll i = 2; i <= sqrt(num); i++) {
			if (num % i == 0) {
				if (S.count(i) == 0) {
					cout << -1 << endl;
					goto link;
				}
				if (num % (num / i) == 0) {
					if (S.count(num / i) == 0) {
						cout << -1 << endl;
						goto link;
					}
				}
			}

		}
		cout << num << endl;
		link:
		num++;
	}
}