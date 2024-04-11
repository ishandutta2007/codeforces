#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
}
template<typename T, typename l>
void getv(T& a, int n, l f) {
	a.resize(n);
	for (auto& i : a)
		cin >> i, f(i);
}
template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef ll _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, d, x, y;
priority_queue<pi> tvis;
vpi pos;
vi a, dist ,dp;
vvpi g;

ll hypot(pi a, pi b) {
	return d*(abs(a.first-b.first) + abs(a.second-b.second));
}

void init() {
	cin >> n >> d;
	a.resize(n+1);
	g.resize(n+1);
	for(int i = 2; i < n; i++)
		cin >> a[i];
	a[1] = a[n] = 0;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		pos.eb(x, y);
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i != j)
				g[i+1].eb(hypot(pos[i], pos[j]), j+1);
}

bool can(ll mx) {
	dist.assign(n+1, -1);
	dist[1] = mx;
	tvis.push({dist[1], 1});
	ll c, v;
	while(!tvis.empty()) {
		tie(c, v) = tvis.top();
		tvis.pop();
		if(c < dist[v]) continue;
//		cout << v << " " << c << "\n";
		for(auto i : g[v]) {
			ll w = c-i.first+a[i.second];
//			cout << v << " -> " << i.second << " ( " << w << " )\n";
			if(c-i.first>=0 && w > dist[i.second]) {
				dist[i.second] = w;
				tvis.push({w, i.second});
			}
		}
	}
	return dist[n]>=0;
}

void binsearch() {
	ll lo = 0, hi = hypot(pos.front(), pos.back())*d, mid;
	while(lo < hi) {
		mid = (lo+hi)>>1;
		if(can(mid))
			hi = mid;
		else
			lo = mid+1;
	}
	cout << hi;
}

int main() {
	doin();
	init();
	binsearch();
}