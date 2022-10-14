#include <bits/stdc++.h>
#include <parallel/numeric>
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
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//  freopen("input.txt", "r", stdin);
#endif
}
typedef long long ll;
typedef int _INT;
typedef double ld;
typedef pair<_INT, _INT> pi;
typedef pair<ld, ld> pd;
typedef map<_INT, _INT> mii;
typedef __V <_INT> vi;
typedef __V <pi> vpi;
typedef __V <__V<_INT>> vvi;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, h, lo, hi, mid;
vi a, b;

bool can(int k) {
	b = vi(a.begin(), a.begin() + k);
	sort(rall(b));
	ll mx = 0, c;
	for(int i = 0; i < b.size(); i+=2) {
		mx += b[i];
	}
	return mx <= h;
}

int main() {
//	doin();
	cin >> n >> h;
	a.resize(n);
	for(auto& i : a) cin >> i;
	for(int i = n; i >= 0; i--)
		if(can(i))
			return cout << i, 0;
	return 0;
}