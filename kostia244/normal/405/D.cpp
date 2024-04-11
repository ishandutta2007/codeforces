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
#ifdef LOCAL
//	freopen("in", "r", stdin);
#endif
}

template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}

typedef long long ll;
typedef ll _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, s = 0, t, nf = 1;
vi a, b;
bitset<1000003> hv;

void next_pair() {
	while(hv.test(nf) || hv.test(1000001-nf))
		nf++;
	hv.set(nf), hv.set(1000001-nf);
}

int main() {
	doin();
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> t, a.pb(t), s+=t, hv.set(t);
	for(auto& i : a) {
		if(hv.test(1000001-i) && i < (1000001-i)) continue;
		if(!hv.test(1000001-i))
			b.pb(1000001-i), hv.set(t);
		else {
			next_pair();
			b.pb(nf);
			b.pb(1000001-nf);
		}
	}
	cout << b.size() << "\n";
	for(auto& i : b)
		cout << i << " ";
}