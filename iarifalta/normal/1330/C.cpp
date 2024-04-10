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
#define treap_pair pair<treap*, treap*>
 
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
 
const int N = 2e5 + 2;
const int M = 1e5 + 2;
const int mod = 998244353;
const int inf = 1e9;
const ll INF = 1e16;

void data() {
	#ifdef PC
		freopen("c.in", "r", stdin);
		freopen("c.out", "w", stdout);
	#endif
}

int n, m, l[N], mx, push = 0, ans[N];

int main() {
	data();
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &l[i]);
		ans[i] = i;
		if (i + l[i] - 1 > n) {
			printf("-1");
			return 0;
		}
		mx = max(mx, i + l[i] - 1);
	}
	if (mx < n) {
		for (int i = 2; i <= m; ++i) {
			int nmx = mx + min(n - mx, ans[i - 1] + l[i - 1] - 1 - ans[i] + 1);
			push += nmx - mx;
			mx = nmx;
			ans[i] += push;
		}
	}
	if (mx == n) {
		for (int i = 1; i <= m; ++i) {
			printf("%d ", ans[i]);
		}
	}	
	else {
		printf("-1");
	}
}