#include <bits/stdc++.h>

using namespace std;
#define DIM  200007
#define DIM2 107
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 1000000007

typedef long long ll;
const ll MASK(1 << 10);
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef ll msk[MASK + 7];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)
#define fi first
#define sc second
#define pb push_back
#define pu push
#define sz size()
#define po(power) ( 1<<power)
#define schnell ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
ll n, m;

int main()
{
	schnell;
	cin >> n >> m;
	ll res = 0, p1 = 1, p2 = m, r1 = 1, r2 = n, turn = 1, way = 1;
	while (r1 <= r2) {
		while (((way == 1 && (p1 <= m || p2 >= 1)) || (way == 2 && (p2 <= m || p1 >= 1))) && res < n * m) {
			if (turn == 1) {
				res++;
				cout << r1 << ' ' << p1 << endl;
				if (way == 1) {
					p1++;
				}
				else p1--;
			}
			else {
				res++;
				cout << r2 << ' ' << p2 << endl;
				if (way == 1) {
					p2--;
				}
				else p2++;
			}
			turn = 3 - turn;

		}
		

		r1++;
		r2--;
		p1 = 1;
		p2 = m;
	}

}