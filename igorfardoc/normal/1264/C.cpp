#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, q;
vi p;
const int mod = 998244353;

int bin_pow(int a, int b) {
	if(b == 0) return 1;
	int res = bin_pow(a, b >> 1);
	res = ((ll)res * res) % mod;
	if(b & 1) {
		res = ((ll)res * a) % mod;
	}
	return res;
}

int obr(int a) {
	return bin_pow(a, mod - 2);
}
int t1[maxn * 4 + 7], t2[maxn * 4 + 7];

void build_tree(int now, int l, int r) {
	if(l == r) {
		t1[now] = t2[now] = (ll)p[l] * obr(100) % mod;
		return;
	}
	int mid = (l + r) / 2;
	build_tree(now * 2, l, mid);
	build_tree(now * 2 + 1, mid + 1, r);
	t1[now] = (ll)t1[now * 2] * t1[now * 2 + 1] % mod;
	t2[now] = (t2[now * 2] + (ll)t2[now * 2 + 1] * t1[now * 2]) % mod;
}

pair<int, int> query(int now, int l, int r, int l1, int r1) {
	if(l1 > r || l > r1) {
		return {1, 0};
	}
	if(l1 <= l && r <= r1) {
		return {t1[now], t2[now]};
	}
	int mid = (l + r) / 2;
	auto p1 = query(now * 2, l, mid, l1, r1);
	auto p2 = query(now * 2 + 1, mid + 1, r, l1, r1);
	return {(ll)p1.first * p2.first % mod, (p1.second + (ll)p2.second * p1.first) % mod};
}

int get_ans(int l, int r) {
	auto p = query(1, 0, n - 1, l, r - 1);
	p.second = (p.second - p.first + 1 + mod) % mod;
	//cout << (ll)p.second * obr(p.first) % mod << endl;
	return (ll)p.second * obr(p.first) % mod;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> q;
    p.resize(n);
    for(int i = 0; i < n; i++) {
    	cin >> p[i];
    }
    build_tree(1, 0, n - 1);
    int ans = get_ans(0, n);
    set<int> all;
    all.insert(0);
    all.insert(n);
    for(int i = 0; i < q; i++) {
    	int v;
    	cin >> v;
    	--v;
    	auto it = all.find(v);
    	if(it == all.end()) {
    		it = all.lower_bound(v);
    		int big = *it;
    		--it;
    		int small = *it;
    		ans = (ans - get_ans(small, big) + mod) % mod;
    		ans = (ans + get_ans(small, v)) % mod;
    		ans = (ans + get_ans(v, big)) % mod;
    		all.insert(v);
    	} else {
    		--it;
    		int small = *it;
    		++it;
    		++it;
    		int big = *it;
    		--it;
    		ans = (ans - get_ans(small, v) + mod) % mod;
    		ans = (ans - get_ans(v, big) + mod) % mod;
    		ans = (ans + get_ans(small, big)) % mod;
    		all.erase(it);
    	}
    	cout << ans << '\n';
    }
}