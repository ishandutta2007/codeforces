#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
signed main() {//check k > n n =1 ai >= 0 etc
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for(auto &i : a) cin >> i;
	sort(all(a));
	if(!k) {
		ll ans = 0;
		for(int i = 0; i < n; i++) {
			ans += i*a[i];
		}
		cout << ans << '\n';
		return 0;
	}
	vector<ll> b;
	while(a.size() && a.back() >= 0) {
		b.push_back(a.back());
		a.pop_back();
	}
	reverse(all(b));
	
	ll bs = 0, bari = 0;
	for(int i = 0; i < b.size(); i++) {
		bs += b[i];
		bari += b[i]*i;
	}
	n = a.size();
	if(!n) {
		cout << bari << '\n';
		return 0;
	}
	
	++k;
	vector<ll> ak;
	ll cur = 0;
	for(int i = 0; i <= n; i++) {
		if(i && i%k == 0) {
			ak.push_back(cur);
		}
		if(i != n) cur += (i/k)*a[i];
	}
	vector<ll> ps = a, ari = a;
	for(int i = 0; i < n; i++)
		ari[i] *= i;
	for(int i = 1; i < n; i++) {
		ps[i] += ps[i-1];
		ari[i] += ari[i-1];
	}
	auto get_ps = [&](int l, int r) {
		if(l > r) return 0ll;
		return ps[r] - (l?ps[l-1]:0);
	};
	auto get_ari = [&](int l, int r, int s) {
		if(l > r) return 0ll;
		ll t = ari[r] - (l?ari[l-1]:0ll);
		t += (-l + s)*get_ps(l, r);
		return t;
	};
	ll ans = -(1ll<<60);
	for(int ml = 1; ml <= n; ml++) {
		int left = n - ml;
		if((left+k-2)/(k-1) > ml) continue;
		int block = left/(k-1);
		ll t = 0;
		if(block > 0) t += ak[block-1];
		ll big = left%(k-1), pos = block*k;
		//cout << ml << " : " << block << " " << t << " " << big << " " << pos << endl;
		t += get_ps(pos, pos+big-1)*block;
		//cout << ml << " : " << block << " " << t << " " << big << " " << pos << endl;
		pos += big;
		t += get_ari(pos, n-1, block);
		t += bari + bs*ml;
		ans = max(ans, t);
		//cout << ml << " " << t << endl;
	}
	cout << ans << '\n';
}