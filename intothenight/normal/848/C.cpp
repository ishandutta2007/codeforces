#include <bits/stdc++.h>
using namespace std;

template<class Q>
struct fenwick_tree{
	fenwick_tree(): n(0){}
	fenwick_tree(int n): n(n), val(n){}
	fenwick_tree(const vector<Q> &v): n((int)v.size()), val(v){
		for(int i = 1; i <= n; ++ i) if(i + (i & -i) <= n) val[i + (i & -i) - 1] += val[i - 1];
	}
	void update(int p, Q x){
		assert(0 <= p && p < n);
		for(++ p; p <= n; p += p & -p) val[p - 1] += x;
	}
	Q query(int r){
		Q s{};
		for(; r > 0; r -= r & -r) s += val[r - 1];
		return s;
	}
	Q query(int l, int r){
		assert(0 <= l && l <= r && r <= n);
		return query(r) - query(l);
	}
	int n;
	vector<Q> val;
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> a(n);
	vector<set<int>> pos(n);
	vector<int> prev(n, -1), next(n, n); // prev, next position of the shape at position i
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
		pos[a[i]].insert(i);
	}
	for(auto i = 0; i < n; ++ i){
		auto it = pos[a[i]].upper_bound(i);
		if(it != pos[a[i]].end()){
			next[i] = *it;
		}
		-- it;
		if(it != pos[a[i]].begin()){
			prev[i] = *-- it;
		}
	}
	const int sz = sqrt(n * max(log(n), 1.0)), cnt = (n + sz - 1) / sz;
	// sum of prev where i <= prev
	// sum of next where next <= i
	vector<fenwick_tree<long long>> psum, nsum;
	for(auto b = 0; b < cnt; ++ b){
		vector<long long> ge(n), le(n + 1);
		for(auto i = b * sz; i < min(b * sz + sz, n); ++ i){
			if(~prev[i]){
				ge[prev[i]] += prev[i];
			}
			le[next[i]] += next[i];
		}
		psum.push_back(fenwick_tree<long long>(ge));
		nsum.push_back(fenwick_tree<long long>(le));
	}
	auto fix_prev = [&](int i, int x){
		if(~prev[i]){
			psum[i / sz].update(prev[i], -prev[i]);
		}
		prev[i] = x;
		if(~prev[i]){
			psum[i / sz].update(prev[i], prev[i]);
		}
	};
	auto fix_next = [&](int i, int x){
		nsum[i / sz].update(next[i], -next[i]);
		next[i] = x;
		nsum[i / sz].update(next[i], next[i]);
	};
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 1){
			int p, x;
			cin >> p >> x, -- p, -- x;
			if(x != a[p]){
				auto it = pos[a[p]].lower_bound(p);
				if(std::next(it) != pos[a[p]].end()){
					fix_prev(*std::next(it), it == pos[a[p]].begin() ? -1 : *std::prev(it));
				}
				if(it != pos[a[p]].begin()){
					fix_next(*std::prev(it), std::next(it) == pos[a[p]].end() ? n : *std::next(it));
				}
				pos[a[p]].erase(p);
				it = pos[a[p] = x].insert(p).first;
				if(std::next(it) != pos[x].end()){
					fix_prev(*std::next(it), p);
					fix_next(p, *std::next(it));
				}
				else{
					fix_next(p, n);
				}
				if(it != pos[a[p]].begin()){
					fix_next(*std::prev(it), p);
					fix_prev(p, *std::prev(it));
				}
				else{
					fix_prev(p, -1);
				}
			}
		}
		else{
			int l, r;
			cin >> l >> r, -- l, -- r;
			long long res = 0;
			if(l / sz == r / sz){
				for(auto i = l; i <= r; ++ i){
					if(prev[i] >= l){
						res -= prev[i];
					}
					if(next[i] <= r){
						res += next[i];
					}
				}
			}
			else{
				for(auto i = l; i < l / sz * sz + sz; ++ i){
					if(prev[i] >= l){
						res -= prev[i];
					}
					if(next[i] <= r){
						res += next[i];
					}
				}
				for(auto b = l / sz + 1; b < r / sz; ++ b){
					res += nsum[b].query(r + 1) - psum[b].query(l, n);
				}
				for(auto i = r / sz * sz; i <= r; ++ i){
					if(prev[i] >= l){
						res -= prev[i];
					}
					if(next[i] <= r){
						res += next[i];
					}
				}
			}
			cout << res << "\n";
		}
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////