#include <bits/stdc++.h>
using namespace std;
 
#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define speed_up ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz() (int)x.size()
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
		freopen("d.in", "r", stdin);
		freopen("d.out", "w", stdout);
	#endif
}

int n;

int main() {
	data();
	scanf("A%d", &n);
	printf("%d", n % 2);
}

/*
	Timus: 288481RF
	CodeForces: fractal
*/