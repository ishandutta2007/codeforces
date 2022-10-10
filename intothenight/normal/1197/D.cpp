#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T, class BO>
class SegmentTree{
public:
	int n;
	vector<T> arr, tree;
	BO bin_op;
	T id;
	SegmentTree(const vector<T> &_arr, BO _bin_op, const T &_id): arr(_arr), n(_arr.size()), bin_op(_bin_op), id(_id){
		tree.resize(n << 1, id);
		for(int i = 0; i < n; i ++){
			tree[i + n] = arr[i];
		}
		build();
	}
	void build(){
		for(int i = n - 1; i > 0; i --){
			tree[i] = bin_op(tree[i << 1], tree[i << 1 | 1]);
		}
	}
	// Change the value at p to val.
	void update(int p, T val){
		for(int tree[p + n] = val; p > 1; p >>= 1){
			tree[p >> 1] = bin_op(tree[p], tree[p ^ 1]);
		}
	}
	T query(int l, int r){
		T resl = id, resr = id;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) resl = bin_op(resl, tree[l ++]);
			if(r & 1) resr = bin_op(tree[-- r], resr);
		}
		return bin_op(resl, resr);
	}
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	for(auto &x: a){
		cin >> x;
	}
	ll res = 0;
	for(int rem = 0; rem < m; rem ++){
		for(int i = rem; i < n; i += m){
			a[i] -= k;
		}
		vector<ll> sum(n + 1);
		partial_sum(a.begin(), a.end(), sum.begin() + 1);
		auto op = [&](const ll &a, const ll &b){
			return max(a, b);
		};
		SegmentTree<ll, function<ll(ll, ll)>> tr(sum, op, -1e18);
		for(int i = rem; i < n; i += m){
			ll temp = tr.query(i + 1, n + 1) - sum[i];
			res = max(res, temp);
		}
		for(int i = rem; i < n; i += m){
			a[i] += k;
		}
	}
	cout << res;
	return 0;
}