#include <bits/stdc++.h>
using namespace std;
 
#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define speed_up ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef set <int> si;
typedef set <ll> sll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
typedef map <int, int> mi;
typedef map <ll, int> mll;
 
const int N = 2e5 + 20;
const int M = 1e5 + 2;
const ll mod = 998244353;
const int inf = 1e9;
const ll INF = 1e16;
 
void data() {
    #ifdef PC
        freopen("main.in", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
}
 
template <typename T>
void scerr(T nums) {
	for (auto it : nums)
		cerr << it << " | ";
	cerr << "\n";
}

int n, k;

ll p[N], ans, ans1 = 1LL;
pii p1[N];
vi vec;

int main() {
	data();
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &p[i]);
		p1[i] = {p[i], i};
	}
	sort(p1 + 1, p1 + n + 1);
	for (int i = n; i >= n - k + 1; --i) {
		ans	+= p1[i].F;
		vec.pb(p1[i].S);
	}
	sort(all(vec));
	for (int i = 0; i < sz(vec) - 1; ++i) {
		ans1 = (ans1 * (vec[i + 1] - vec[i])) % mod;
	}
	printf("%lld %lld", ans, ans1); 
}
 
/*
	Timus: 288481RF
	CodeForces: __fractal
*/