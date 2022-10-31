#include <bits/stdc++.h>

using namespace std;
#define DIM 300007
#define DIM2 200007
#define DIM3 200007
#define INF 10E16
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

typedef  int ll;
typedef long double ld;
const ld eps = 0.00000001;
const ll MASK(1 << 10);
const ll MC = 5007;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef ll msk[MASK + 7];
typedef vector<ll> vec;
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)
struct node {
	ll num, x, y;
};
ll n;
vector<node> V1, V2;
vector<node> ans1, ans2;
bool mc(node x, node y) {
	return x.y > y.y;
}
bool mc1(node x, node y) {
	return x.x < y.x;
}
int main()
{
	schnell;
	cin >> n;
	forn(i, n) {
		ll x, y;
		cin >> x >> y;
		if (x > y)V2.pb({ i,x,y });
		else V1.pb({ i,x,y });
	}
	sort(V1.begin(), V1.end(), mc);
	sort(V2.begin(), V2.end(),mc1);
	for (ll i = 0; i < V1.size(); i++) {
		node to = V1[i];
		if (ans1.size() == 0) {
			ans1.pb(to);
			continue;
		}
		 node last = ans1[ans1.size() - 1];
		
		if (last.y > to.x) {
			ans1.pb(to);
		}
	}
	for (ll i = V2.size() - 1; i >= 0; i--) {
		node to = V2[i];
		if (ans2.size() == 0) {
			ans2.pb(to);
			continue;
		}
		 node last = ans2[ans2.size() - 1];
		
		if (last.x > to.y) {
			ans2.pb(to);
		}
	}
	if (ans1.size() > ans2.size()) {
		cout << ans1.size() << endl;
		for (node to : ans1) {
			cout << to.num << ' ';
		}
	}
	else {
		cout << ans2.size() << endl;
		for (ll i = ans2.size() - 1; i >= 0;i--) {
			node to = ans2[i];
			cout << to.num << ' ';
		}
	}
	cout << endl;
	return 0;
}
// (a+k)%(b+k)
// a-b*x;