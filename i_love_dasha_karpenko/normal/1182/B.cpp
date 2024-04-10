#include <bits/stdc++.h>

using namespace std;
#define DIM  507
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
ll n, m, V[DIM][DIM];
char A[DIM][DIM];
void paint(ll i, ll j) {
	ll ii=i, jj=j;
	while (A[ii][jj] == '*' && jj<=m) {
		V[ii][jj] = 1;
		jj++;
	}
	ii = i, jj = j;
	while (A[ii][jj] == '*' && jj>=1) {
		V[ii][jj] = 1;
		jj--;
	}
	ii = i, jj = j;
	while (A[ii][jj] == '*' && ii<=n) {
		V[ii][jj] = 1;
		ii++;
	}
	ii = i, jj = j;
	while (A[ii][jj] == '*' && ii>=1) {
		V[ii][jj] = 1;
		ii--;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)cin >> A[i][j];
	ll flag = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (flag==0 && A[i][j] == '*') {
				if (A[i][j - 1] == '*' && A[i - 1][j] == '*' && A[i][j + 1] == '*' && A[i + 1][j] == '*') {
					paint(i, j);
					flag = 1;
				}
			}
		}
	}
	if (flag == 0) {
		cout << "NO" << endl;
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (A[i][j] == '*' && V[i][j] == 0) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
		cout << "YES" << endl;
	}
}