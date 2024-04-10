#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class L, class R>
istream &operator>>(istream &in, pair<L, R> &arr){
    return in >> arr.first >> arr.second;
}
template<class ...Args, template<class...> class T>
istream &operator>>(enable_if_t<!is_same_v<T<Args...>, string>, istream> &in, T<Args...> &arr){
	for(auto &x: arr) in >> x; return in;
}
template<class L, class R>
ostream &operator<<(ostream &out, const pair<L, R> &arr){
    return out << "(" << arr.first << ", " << arr.second << ") ";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;

template<class T, class BO1, class BO2, class BO3>
struct ldseg{
	ldseg *l = 0, *r = 0;
	int low, high;
	BO1 lop;			// Lazy op(L, L -> L)
	BO2 qop;			// Query op(Q, Q -> Q)
	BO3 aop;			// Apply op(Q, L, len -> Q)
	vector<T> &id;		// Lazy id(L), Query id(Q), Disable constant(Q)
	T lset, lazy, val;
	ldseg(int low, int high, BO1 lop, BO2 qop, BO3 aop, vector<T> &id)
	: low(low), high(high), lop(lop), qop(qop), aop(aop), id(id){
		lazy = id[0], val = id[1], lset = id[2];
	}
	ldseg(const vector<T> &arr, int low, int high, BO1 lop, BO2 qop, BO3 aop, vector<T> &id)
	: low(low), high(high), lop(lop), qop(qop), aop(aop), id(id){
		lazy = id[0], lset = id[2];
		if(high - low > 1){
			int mid = low + (high - low) / 2;
			l = new ldseg(arr, low, mid, lop, qop, aop, id);
			r = new ldseg(arr, mid, high, lop, qop, aop, id);
			val = qop(l->val, r->val);
		}
		else val = arr[low];
	}
	void push(){
		if(!l){
			int mid = low + (high - low) / 2;
			l = new ldseg(low, mid, lop, qop, aop, id);
			r = new ldseg(mid, high, lop, qop, aop, id);
		}
		if(lset != id[2]){
			l->set(low, high, lset);
			r->set(low, high, lset);
			lset = id[2];
		}
		else if(lazy != id[0]){
			l->update(low, high, lazy);
			r->update(low, high, lazy);
			lazy = id[0];
		}
	}
	void set(int ql, int qr, T x){
		if(qr <= low || high <= ql) return;
		if(ql <= low && high <= qr){
			lset = x;
			lazy = id[0];
			val = aop(id[1], x, high - low);
		}
		else{
			push();
			l->set(ql, qr, x);
			r->set(ql, qr, x);
			val = qop(l->val, r->val);
		}
	}
	void update(int ql, int qr, T x){
		if(qr <= low || high <= ql) return;
		if(ql <= low && high <= qr){
			if(lset != 	id[2]) lset = lop(lset, x);
			else lazy = lop(lazy, x);
			val = aop(val, x, high - low);
		}
		else{
			push(), l->update(ql, qr, x), r->update(ql, qr, x);
			val = qop(l->val, r->val);
		}
	}
	T query(int ql, int qr){
		if(qr <= low || high <= ql) return id[1];
		if(ql <= low && high <= qr) return val;
		push();
		return qop(l->query(ql, qr), r->query(ql, qr));
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vi a(n);
	cin >> a;
	int init;
	for(int i = 0; i < n; ++ i){
		a[i] --;
		if(!a[i]){
			init = i;
		}
	}
	rotate(a.begin(), a.begin() + init, a.end());
	a.push_back(0);
	vi pos(n);
	for(int i = 1; i < n; ++ i){
		pos[a[i]] = i;
	}
	set<int> occur;
	occur.insert(0), occur.insert(n);
	vi lpar(n), rpar(n);
	vector<vi> ladj(n + 1), radj(n + 1);
	for(int i = 1; i < n; ++ i){
		auto it = occur.lower_bound(pos[i]);
		rpar[pos[i]] = *it;
		radj[*it].push_back(pos[i]);
		it --;
		lpar[pos[i]] = *it;
		ladj[*it].push_back(pos[i]);
		occur.insert(pos[i]);
	}
	vi ldepth(n + 1), rdepth(n + 1);
	function<void(int)> ldfs = [&](int u){
		for(auto v: ladj[u]){
			ldepth[v] = ldepth[u] + 1;
			ldfs(v);
		}
	};
	ldfs(0);
	function<void(int)> rdfs = [&](int u){
		for(auto v: radj[u]){
			rdepth[v] = rdepth[u] + 1;
			rdfs(v);
		}
	};
	rdfs(n);
	vi arr(n + 1);
	for(int i = 1; i < n; ++ i){
		arr[i] = ldepth[i] + rdepth[i] - 1;
	}
	vi id{0, 0, -1};
	auto aop = [&](int x, int y, int z){
		return x + y;
	};
	ldseg tr(arr, 0, n + 1, plus<int>{}, [&](int x, int y){return max(x, y);}, aop, id);
	int step, res = 2e9;
	for(int i = 1; i <= n; ++ i){
		int cur = tr.query(1, n);
		if(cur < res){
			res = cur;
			step = i;
		}
		if(i < n){
			tr.set(i, i + 1, ldepth[i]);
			tr.update(i + 1, rpar[i], -1);
			tr.update(lpar[i] + 1, i, 1);
		}
	}
	cout << res + 1 << " " << (init + step) % n;
	return 0;
}

/*
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////