#include <bits/stdc++.h>
using namespace std;

template<class Q>
struct fenwick_tree{
	fenwick_tree(): n(0){}
	fenwick_tree(int n): n(n), tree(n){}
	fenwick_tree(const vector<Q> &v): n((int)v.size()), tree(v){
		for(int i = 1; i <= n; ++ i) if(i + (i & -i) <= n) tree[i + (i & -i) - 1] += tree[i - 1];
	}
	void update(int p, Q x){
		assert(0 <= p && p < n);
		for(++ p; p <= n; p += p & -p) tree[p - 1] += x;
	}
	Q query(int r){
		Q s{};
		for(; r > 0; r -= r & -r) s += tree[r - 1];
		return s;
	}
	Q query(int l, int r){
		assert(0 <= l && l <= r && r <= n);
		return query(r) - query(l);
	}
	template<class F> int max_pref(F f){
		int p = 0;
		Q pref{};
		for(int i = __lg(n + 1); i >= 0; -- i) if(p + (1 << i) <= n && f(pref + tree[p + (1 << i) - 1])){
			pref += tree[p + (1 << i) - 1];
			p += 1 << i;
		}
		return p;
	} // f(sum[0, r)) is T, T, ..., T, F, F, ..., F, returns max r with T
	int n;
	vector<Q> tree;
};
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }


int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string s;
	int x, y;
	cin >> s >> x >> y;
	int n = (int)s.size();
	vector<int> a(n);
	array<int, 2> numbers{};
	array<long long, 2> cnt{}; // 01, 10
	for(auto i = 0; i < n; ++ i){
		a[i] = s[i] == '1';
		cnt[!a[i]] += numbers[!a[i]];
		++ numbers[a[i]];
	}
	long long cur = cnt[0] * x + cnt[1] * y;
	long long res = cur;
	fenwick_tree tr(a);
	for(auto i = 0; i < n; ++ i){
		if(s[i] == '?'){
			tr.update(i, 1);
			int fo = tr.query(0, i);
			int fz = i - fo;
			int bo = tr.query(i + 1, n);
			int bz = n - i - 1 - bo;
			cur -= 1LL * fo * y + 1LL * bo * x;
			cur += 1LL * fz * x + 1LL * bz * y;
			ctmin(res, cur);
		}
	}
	for(auto i = 0; i < n; ++ i){
		if(s[i] == '?'){
			tr.update(i, -1);
			int fo = tr.query(0, i);
			int fz = i - fo;
			int bo = tr.query(i + 1, n);
			int bz = n - i - 1 - bo;
			cur -= 1LL * fz * x + 1LL * bz * y;
			cur += 1LL * fo * y + 1LL * bo * x;
			ctmin(res, cur);
		}
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////