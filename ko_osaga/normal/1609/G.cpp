#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<lint, lint>;
const int MAXN = 105000;

lint idonghagi(vector<lint> a, vector<lint> b);

struct bit{
	lint tree[MAXN];
	void add(int x, lint v){
		for(int i = x + 3; i < MAXN; i+=i&-i) tree[i] += v;
	}
	int first_higher(lint q){
		int pos = 0;
		for(int i = 16; i >= 0; i--){
			if(pos + (1<<i) < MAXN && tree[pos + (1<<i)] <= q){
				pos += (1<<i);
				q -= tree[pos];
			}
		}
		return pos + 1 - 3;
	}
	lint query(int x){
		lint ret = 0;
		for(int i = x + 3; i; i -= i & -i) ret += tree[i];
		return ret;
	}
}bit, bit2, bit3;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<lint> a(n), b(m);
	vector<lint> delta(m);
	for(auto &i : a) cin >> i;
	for(auto &i : b) cin >> i;
	for(int i = m-1; i > 0; i--) delta[i] = b[i] - b[i-1];
	for(int i = 1; i <= m-1; i++){
		bit.add(i, delta[i] - delta[i - 1]);
		bit2.add(i, delta[i]);
	}
	bit2.add(0, b[0]);
	lint sum = accumulate(all(a), 0ll) + accumulate(all(b), 0ll);
	while(q--){
		int t; lint k, d; cin >> t >> k >> d;
		sum += 1ll * k * (k + 1) / 2 * d;
		if(t == 1){
			k = n - k;
			for(int i = k; i < n; i++) a[i] += (i - k + 1) * d;
		}
		if(t == 2){
			k = m - k;
			bit2.add(k, -d * (k - 1));
			bit3.add(k, d);
			bit.add(k, d);
		}
		int y = 0;
		lint ret = 0;
		for(int i = 0; i < n-1; i++){
			int nxt = bit.first_higher(a[i + 1] - a[i]);
			lint d = min(nxt - 1, sz(b) - 1) - y;
			if(d >= 0){
				ret += d * a[i];
				y += d;
			}
			ret += y * bit3.query(y) + bit2.query(y);
		}
		ret += a[n - 1] * (sz(b) - 1 - y);
		cout << sum + ret << '\n';
	}
}