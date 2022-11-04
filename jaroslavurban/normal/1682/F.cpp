#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;

struct ST {
	int N;
	vector<int> sum;
	vector<int> cnt;
	ST(int n) : N(1 << int(log2(2 * n - 1))), sum(2 * N), cnt(2 * N) {}
	void update(int i, int s, int c) {
		i += N;
		sum[i] = (ll)s * c % mod;
		cnt[i] = c;
		while (i /= 2) {
			sum[i] = (sum[2 * i] + sum[2 * i + 1]) % mod;
			cnt[i] = cnt[2 * i] + cnt[2 * i + 1];
		}
	}
	tuple<int, int> query(int l, int r) {
		int rsum = 0;
		int rcnt = 0;
		for (l += N, r += N; l < r; l /= 2, r /= 2) {
			if (l & 1) rsum = (rsum + sum[l]) % mod, rcnt += cnt[l], ++l;
			if (r & 1) --r, rsum = (rsum + sum[r]) % mod, rcnt += cnt[r];
		}
		return {rsum, rcnt};
	}
};

void ProGamerMove() {
	int n, q; cin >> n >> q;
	vector<int> a(n), b(n);
	for (int& v : a) cin >> v;
	for (int& v : b) cin >> v;
	
	struct Item {
		ll sm;
		int cnt, i;
	};
	vector<Item> pref(n - 1);
	ll sm = 0;
	for (int i = 0; i < n - 1; ++i) {
		sm += b[i];
		pref[i] = {sm, a[i + 1] - a[i], i};
	}
	struct Q {
		int l, r, i, res = 0;
		ll sm;
	};
	vector<Q> qs(q);
	int tmp = 0;
	for (auto& [l, r, i, res, sm] : qs) {
		cin >> l >> r, --l, --r;
		sm = l ? pref[l - 1].sm : 0;
		i = tmp++;
	}
	sort(pref.begin(), pref.end(), [&] (Item& a, Item& b) {
		return a.sm < b.sm;
	});
	sort(qs.begin(), qs.end(), [&] (Q& a, Q& b) {
		return a.sm < b.sm;
	});


	for (int it = 0; it < 2; ++it) {
		ST st(n - 1);
		int j = 0;
		for (int i = 0; i < q; ++i) {
			for (; j < n - 1 && (it ? pref[j].sm > qs[i].sm : pref[j].sm < qs[i].sm); ++j)
				st.update(pref[j].i, pref[j].sm % mod, pref[j].cnt);
			auto [sm, cnt] = st.query(qs[i].l, qs[i].r);
			qs[i].res += (it ? -1 : 1) * (qs[i].sm % mod * cnt % mod - sm) % mod;
		}
		reverse(pref.begin(), pref.end());
		reverse(qs.begin(), qs.end());
	}

	sort(qs.begin(), qs.end(), [&] (Q& a, Q& b) {
		return a.i < b.i;
	});
	for (auto& qr : qs) cout << ((qr.res % mod) + mod) % mod << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}