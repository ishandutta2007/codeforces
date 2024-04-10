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

int x, p[6] = {1, 6, 4, 5, 3}, num[10];

int main() {
	data();
	scanf("%d", &x);
	for (int i = 6; i >= 1; --i) {
		int bit = (x & (1 << (i - 1)));
		if (i == 6) {
			num[6] = (bit != 0);
		}
		if (i == 5) {
			num[1] = (bit != 0);
		}
		if (i == 4) {
			num[3] = (bit != 0);
		}
		if (i == 3) {
			num[4] = (bit != 0);
		}
		if (i == 2) {
			num[2] = (bit != 0);
		}
		if (i == 1) {
			num[5] = (bit != 0);
		}
	}
	int ans = 0;
	int pw = 1;
	for (int i = 1; i <= 6; ++i) {
		ans += num[i] * pw;
		pw *= 2;
	}
	printf("%d", ans);
}

/*
	Timus: 288481RF
	CodeForces: fractal
*/