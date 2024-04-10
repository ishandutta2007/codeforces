#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct FTree {
	vector<ll> nums;
	int size = 1;
	void init(int n) {
		while(size < n) size *= 2;
		nums.resize(size+1);
	}
	void set(int n, ll x) {
		while(n <= size) {
			nums[n] = max(nums[n], x);
			n += (n & (-n));
		}
	}
	ll get(int n) {
		ll ans = 0;
		while(n) {
			ans = max(ans, nums[n]);
			n -= (n & (-n));
		}
		return ans;
	}
};

ll BIG = (ll)99999999999;

struct segTreeMin {
	int size;
	vector<ll> sums;
	void init(int n) {
		size = 1;
		while(size < n) size *= 2;
		for(int i = 0; i < 2*size; i++) sums.push_back(BIG);
	}
	void set(int i, ll x, int n, int l, int r) {
		if(r - l == 1) {
			sums[n] = x;
			return;
		}
		int mid = (l+r)/2;
 		if(i < mid) {
			set(i, x, 2*n+1, l, mid);
  		}
 		else {
 			set(i, x, 2*n+2, mid, r);
  		}
  		sums[n] = min(sums[2*n+1], sums[2*n+2]);
  	}
  	void set(int i, ll x) {
		set(i, x, 0, 0, size);
  	}
 	ll get(int l, int r, int x, int lx, int rx) {
  		if(rx <= l || r <= lx) {
  			return BIG;
  		}
  		if(l <= lx && rx <= r) {
  			return sums[x];
   		}
   		int mid = (lx+rx)/2;
   		ll s1 = get(l, r, 2*x+1, lx, mid);
   		ll s2 = get(l, r, 2*x+2, mid, rx);
   		return min(s1, s2);
   	}
   	ll get(int l, int r) {
   		return get(l, r, 0, 0, size);
   	}
};

struct segTree {
	int size = 1;
	vector<ll> nums;
	void init(int n) {
		while(size < n) size *= 2;
		nums.resize(2*size, BIG);
	}
	void set(int i, ll v, int n, int lx, int rx) {
		if(rx - lx == 1) {
			nums[n] = v;
			return;
		}
		int mid = (lx + rx)/2;
		if(i < mid) set(i, v, 2*n+1, lx, mid);
		else set(i, v, 2*n+2, mid, rx);
		nums[n] = min(nums[2*n+1], nums[2*n+2]);
	}
	void set(int i, ll v) {
		return set(i, v, 0, 0, size);
	}
	ll get(int l, int r, int n, int lx, int rx) {
		if(rx <= l || r <= lx) return BIG;
		if(l <= lx && rx <= r) return nums[n];
		int mid = (lx + rx)/2;
		ll m1 = get(l, r, 2*n+1, lx, mid), m2 = get(l, r, 2*n+2, mid, rx);
		return min(m1, m2);
	}
	ll get(int l, int r) {
		return get(l, r, 0, 0, size);
	}
};

vector<int> a, b;
vector<pair<int, int>> sted;
bool taken[200001];
int corr[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll ans = 0;
	cin >> n;
	a.resize(n);
	b.resize(n);
	FTree fta, ftb;
	segTree ftc, ftd;
	fta.init(2*n);
	ftb.init(2*n);
	ftc.init(2*n);
	ftd.init(2*n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sted.push_back({a[i], i+1});
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		ans += (ll)(abs(a[i]-b[i]));
		sted.push_back({b[i], -i-1});
	}
	sort(sted.begin(), sted.end());
	ll best = -1;
	for(int i = 0; i < 2*n; i++) {
		auto p = sted[i];
		bool sad = false;
		if(p.second < 0) {
			sad = true;
			p.second *= -1;
		}
		p.second--;
		if(taken[p.second]) {
			// cout << 2*n - corr[p.second] << ' ' << abs(a[p.second] - b[p.second]) << '\n';
			if(sad) {
				best = max(best, fta.get(2*n - corr[p.second]));
				ftb.set(2*n - corr[p.second], (ll)(abs(a[p.second] - b[p.second])));
				best = max(best, b[p.second] - ftc.get(corr[p.second], i));
				ftd.set(corr[p.second], BIG);
			}
			else {
				best = max(best, ftb.get(2*n - corr[p.second]));
				fta.set(2*n - corr[p.second], (ll)(abs(a[p.second] - b[p.second])));
				best = max(best, a[p.second] - ftd.get(corr[p.second], i));
				ftc.set(corr[p.second], BIG);
			}
		}
		else {
			taken[p.second] = true;
			corr[p.second] = i;
			if(sad) {
				ftc.set(i, b[p.second]);
			}
			else {
				ftd.set(i, a[p.second]);
			}
		}
	}
	ans -= 2*best;
	cout << ans << '\n';
	return 0;
}