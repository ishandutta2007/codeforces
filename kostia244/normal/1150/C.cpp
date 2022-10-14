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
typedef int _I;
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
int n, t, cnt[3] = { 0 }, i = 0, diff = 2;
bitset<400001> p;
vi pr;
int main() {
	doin();
	for (ll i = 2; i <= 400000; i++) {
		if (p.test(i))
			continue;
		pr.pb(i);
		for (ll j = i * i; j <= 400000; j += i)
			p.set(j);
	}
	pr.pb(500000);
	cin >> n;
	while (n--) {
		cin >> t;
		cnt[t]++;
	}
	while (cnt[1] || cnt[2]) {
		if (diff <= 0) {
			diff = (pr[i + 1] - pr[i]) + diff;
			i++;
		}
		if (diff == 1 && cnt[1] > 0) {
			cout << "1 ";
			cnt[1]--;
			diff--;
		} else if (cnt[2] > 0)
			cout << "2 ", cnt[2]--, diff-=2;
		else if(cnt[1]) {
			cout << "1 ";
			diff--;
			cnt[1]--;
		}
	}

}