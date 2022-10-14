#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
#define mod 1000000007ll
using namespace std;
ll ans;
int n;
vi a, fp, fs;
map<int, int> last;

template<typename ... T>
void resize(uint32_t n, T&... a) {
	(a.resize(n), ...);
}

template <int... Args> struct BIT {
	ll val = 0;
	void update(int i) {
		val += i;
	}
	int query() {
		return val;
	}
};
template <int N, int... Ns> struct BIT<N, Ns...> {
	BIT<Ns...> bit[N+1];
	template <typename... T>
	void update(int i, T... args) {
		for(; i <= n; bit[i].update(args...), i+=(i & -i));
	}
	template <typename... T>
	ll query(int l, int r, T... args) {
		ll ans = 0;
		for(; r>0; ans += bit[r].query(args...), r-=(r & -r));
		for(l--; l>0; ans -= bit[l].query(args...), l-=(l & -l));
		return ans;
	}
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	resize(n, a, fp, fs);
	for (auto& i : a)
		cin >> i;
	for (int i = 0; i < n; i++) {
		int &t = last[a[i]];
		if (t == 0)
			fp[i] = 1;
		else
			fp[i] = fp[t - 1] + 1;
		t = i + 1;
	}
	last.clear();
	BIT<1000001> s;
	for (int i = n-1; i >= 0; i--) {
		int &t = last[a[i]];
		if (t == 0)
			fs[i] = 1;
		else
			fs[i] = fs[t - 1] + 1;
		t = i + 1;
		s.update(fs[i], 1);
	}
	for (int i = 0; i < n; i++)
		s.update(fs[i], -1), ans += s.query(1, fp[i]-1);
	cout << fixed << ans;

}