#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 6969701591;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
ll base = 4e9 + 7;
ll ans = 0;
vi p;
using pll = pair<ll, ll>;
struct gh {
	ll a, b, c;
	void add(gh x) {
		a*=37;
		b*=33;
		c*=51;
		a^=x.a;
		b^=x.b;
		c^=x.c;
	}
	void zero() {
		a = b = c = 0;
	}
	void gen() {
		a = rng();
		b = rng();
		c = rng();
	}
	bool eq(gh o) {
		return o.a==a&&o.b==b&&o.c==c;
	}
	bool operator<(const gh& o) const {
			return pair<ll, pll>(a, pll(b, c)) < pair<ll, pll>(o.a, pll(o.b, o.c));
		}
};

gh hsh[300300];
void rec(int l, int r) {
	if (r - l <= 0)
		return;
	if (r - l == 0) {
		ans += p[l] == p[r];
		return;
	}
	gh curhash;
	curhash.zero();
	map<gh, ll> cnt;
	int mid = (l+r)/2;
	stack<pair<int, gh>> st;
	for(int i = mid; i <= r; i++) {
		curhash.add(hsh[p[i]]);
		if(!st.empty()&&st.top().first==p[i])
			st.pop();
		else
			st.push({p[i], curhash});
		if(st.empty()) {
			curhash.zero();
			cnt[curhash]++;
		} else
			cnt[curhash = st.top().second]++;
//		cout << curhash << " ";
	}
//	cout << "\n";
	curhash.zero();
	ans += cnt[curhash];
	st = stack<pair<int, gh>>();
	for(int i = mid-1; i >= l; i--) {
		curhash.add(hsh[p[i]]);
		if(!st.empty()&&st.top().first==p[i])
			st.pop();
		else
			st.push({p[i], curhash});
		if(st.empty()) {
			curhash.zero();
			ans += cnt[curhash];
		} else
			ans += cnt[curhash = st.top().second];
//		cout << curhash << " ";
	}
//	cout << "\n";
//	cout << l << " " << mid << " " << r << " " << ans << "\n";
	rec(l, mid-1);
	rec(mid+1, r);
}
void solve() {
	cin >> n;
	p.assign(n, 0);
	for (auto &i : p)
		cin >> i;
	ans = 0;
	rec(0, n - 1);
	cout << ans << "\n";
}
//
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	for(int i = 0; i <= 300299; i++) hsh[i].gen();
	int q;
	cin >> q;
	while (q--)
		solve();
}