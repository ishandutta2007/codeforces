#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T, class BO>
class segment{
public:
	int n;
	vector<T> tree;
	BO bin_op;
	T id;
	segment(const vector<T> &arr, BO _bin_op, const T &_id): n(arr.size()), bin_op(_bin_op), id(_id){
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
	void update(int p, T val){
		for(tree[p += n] = val; p > 1; p >>= 1){
			tree[p >> 1] = bin_op(tree[p], tree[p ^ 1]);
		}
	}
	T query(int l, int r){
		if(l >= r){
			return id;
		}
		T resl = id, resr = id;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) resl = bin_op(resl, tree[l ++]);
			if(r & 1) resr = bin_op(tree[-- r], resr);
		}
		return bin_op(resl, resr);
	}
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	int q;
	cin >> q;
	vi gq(q), lq(n, -1);
	for(int i = 0; i < q; i ++){
		int type;
		cin >> type;
		if(type == 1){
			int ind, x;
			cin >> ind >> x, ind --;
			lq[ind] = i;
			a[ind] = x;
		}
		else{
			int x;
			cin >> x;
			gq[i] = x;
		}
	}
	segment tr(gq, [](int x, int y){return max(x, y);}, 0);
	for(int i = 0; i < n; i ++){
		cout << max(a[i], tr.query(lq[i] + 1, q)) << " ";
	}
	return 0;
}