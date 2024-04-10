
/*
    Im not gonna run away, I never go back on my word! Thats my nindo: my ninja way. Naruto
























































*/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define speed_up ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define szc(x) (int)strlen(x)
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound 
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef set <int> si;
typedef set <ll> sll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
typedef map <int, int> mi;
typedef map <ll, int> mll;
 
const int N = 3e5 + 2;
const int M = 2e6 + 2;
const int mod = 998244353;
const int inf = 2e9 + 3;
const ll INF = 1e18;

/*
	BIN POISK EBANA V ROT
	DP EBANA V ROT
	DO EBANA V ROT
*/

int T;
ll n, k, l1, r1, l2, r2, al1[N], ar1[N], al2[N], ar2[N];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%lld  %lld %lld %lld %lld %lld", &n, &k, &l1, &r1, &l2, &r2);
		if (l1 > l2)
			swap(l1, l2), swap(r1, r2);
		if (l1 == l2 && r1 > r2)
			swap(l1, l2), swap(r1, r2);
		ll ans = INF;
		ll r = max(r2, r1);
		ll dr = r - min(r1, r2);		
		ll l = min(l1, l2);
		ll dl = max(l1, l2) - l;
		ll mx = r - l;
		ll mem = 0;
		ll sum = 0;		
		for (int i = 1; i <= n; ++i) {
			al1[i] = l1;
			al2[i] = l2;
			ar1[i] = r1;
			ar2[i] = r2;
			if (min(r1, r2) - max(l1, l2) >= 0) {
				k -= min(r1, r2) - max(l1, l2);
			}
		}		
		if (min(r1, r2) - max(l1, l2) >= 0)
			mx -= min(r1, r2) - max(l1, l2);
		if (k <= 0)
			ans = 0;
		for (int  i = 1; i <= n; ++i) {
			mem += mx;
			sum += dl + dr;
			if (mem < k) {
				sum += (k - mem) * 2LL;
				ans = min(sum, ans);
				sum -= (k - mem) * 2LL;
			}
			else {
				sum -= mem - k;
				ans = min(ans, sum);
				sum += mem - k;
			}
		}
		printf("%lld\n", max(0LL, ans));
	}
}

/*
	Timus: 288481RF
	CodeForces: fractal
*/