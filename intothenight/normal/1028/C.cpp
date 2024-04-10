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
	vector<T> arr, tree;
	BO bin_op;
	T id;
	segment(const vector<T> &_arr, BO _bin_op, const T &_id): arr(_arr), n(_arr.size()), bin_op(_bin_op), id(_id){
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
	vi lx(n), ly(n), ux(n), uy(n);
	for(int i = 0; i < n; i ++){
		cin >> lx[i] >> ly[i] >> ux[i] >> uy[i];
	}
	auto MIN = [](int x, int y){
		return min(x, y);
	};
	auto MAX = [](int x, int y){
		return max(x, y);
	};
	const int MINVAL = -2e9, MAXVAL = 2e9;
	segment t1(lx, MAX, MINVAL), t2(ly, MAX, MINVAL);
	segment t3(ux, MIN, MAXVAL), t4(uy, MIN, MAXVAL);
	for(int i = 0; i < n; i ++){
		int Lx = max(t1.query(0, i), t1.query(i + 1, n)), Ly = max(t2.query(0, i), t2.query(i + 1, n));
		int Ux = min(t3.query(0, i), t3.query(i + 1, n)), Uy = min(t4.query(0, i), t4.query(i + 1, n));
		if(Lx <= Ux && Ly <= Uy){
			cout << Lx << " " << Ly;
			return 0;
		}
	}
	return 0;
}