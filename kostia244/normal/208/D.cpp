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
//  freopen("input.txt", "r", stdin);
#endif
}
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pi;
typedef pair<ld, ld> pd;
typedef map<int, int> mii;
typedef __V <ll> vi;
typedef __V <pi> vpi;
typedef __V <__V<int>> vvi;
typedef __V <__V<pi>> vvpi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, k, s = 0, i, cs[5], ans[5];
vi p;
int main() {
	doin();
	cin >> n;
	p.resize(n);
	for(auto& i : p) cin >> i;
	for(int i = 0; i < 5; i++) cin >> cs[i];
	for(auto& c : p) {
		s += c;
		i = 5;
		while(i--)
			if((k = s/cs[i])>0)
				s -= k*cs[i], ans[i]+=k;
	}
	copy(ans, ans+5, oit<ll>(cout, " "));
	cout << "\n" << s;
	return 0;
}