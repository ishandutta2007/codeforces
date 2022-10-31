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
const ld eps = 0.000001;
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
ll r = 0, p = 0,res = 0;
string a, b;
// 2 5 4 3 
int main()
{
	
	schnell;
	cin >> a >> b;
	fore( 0,i, b.length() - 1) {
		if (a[i] == a[i + 1])r++;
	}
	fore(0,i, b.length() - 1) {
		if (a[i] != b[i])p++;
	}
	if (p % 2 == 0)res++;
	ll l = b.length();
	fore(l, i, a.length() - 1) {
		ll t = l - p + r;
		if (a[i - l] == a[i - l + 1])r--;
		if (i + 1 < a.length()) {
			if (a[i] == a[i + 1])r++;
		}
		if (t % 2 == 0)res++;
		p = t;
	}
	cout << res << endl;
}