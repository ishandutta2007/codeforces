#include <bits/stdc++.h>

using namespace std;
#define DIM 100007
#define DIM2 57
#define DIM3 200007
#define INF 10E10
#define MAXN 2750137
#define LG 18
#define MODULO 998244353
#define fi first
#define sc second
#define pb push_back
#define pu push
#define sz size()
#define po(power) ( 1<<power)
#define schnell ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

typedef long long ll;
typedef long double ld;

const ld eps = 0.00000001;
const ll MASK(1 << 10);

typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef ll arr[DIM];
typedef ll msk[MASK + 7];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef pair<pll, pll> pllll;
//typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)

ll s, b,ans[DIM];
pll B[DIM],A[DIM];
int main()
{
	schnell;
	cin >> s >> b;
	forn(i, s) {
		cin >> A[i].fi;
		A[i].sc = i;
	}
	forn(i, b) {
		cin >> B[i].fi >> B[i].sc;
	}
	sort(A + 1, A + 1 + s);
	sort(B + 1, B + 1 + b);
	ll p1 = 1,p2 = 1;
	ll res = 0;
	while (p1 <= s) {
		while (p1<=s && p2<=s && A[p1].fi < B[p2].fi) {
			ans[A[p1].sc] = res;
			p1++;
		}
		while (p2<=b && B[p2].first <= A[p1].fi) {
			res += B[p2].sc;
			p2++;
		}
		ans[A[p1].sc] = res;
		p1++;
	}
	forn(i, s)cout << ans[i] << ' ';
	cout << endl;
	return 0;
}