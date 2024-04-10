#include <bits/stdc++.h>

using namespace std;
#define DIM  400007
#define DIM2 107
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 1000000007
#define MODULO2 MODULO*2
typedef long long  ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
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
ll n;
arr A,M;
ll V[MAXN];
vector<ll> simple;
map< ll, queue<ll> > m;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (ll i = 2; i < MAXN; i++) {
		if (V[i] == 0) {
			for (ll j = i * i; j < MAXN; j += i)V[j] = 1;
			simple.push_back(i);

		}
	}
	cin >> n;
	n *= 2;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	sort(A + 1, A + 1 + n);
	for (int i = 1; i <= n; i++) {
		m[A[i]].push(i);
	}

	for (int i = n; i >= 1; i--) {
		if (M[i] == -1)continue;
		auto bounds = equal_range(simple.begin(), simple.end(), A[i]);
		ll r;
		if (bounds.first == bounds.second) {
			for (ll j = 2; j <= sqrt(A[i]); j++) {
				if (A[i] % j == 0) {
					r = A[i] / j; break;
				}
			}
			M[m[r].front()] = -1;
			m[r].pop();
			cout << A[i] << ' ';
			M[i] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (M[i] == -1)continue;
		//cout << m[simple[A[i] - 1]].front() << endl;
		M[m[simple[A[i] -1]].front()] = -1;
	
		m[simple[A[i] - 1]].pop();
		cout << A[i] << ' ';
	}
	cout << endl;
}