#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
    return out << "(" << arr.first << ", " << arr.second << ")";
}
template<class ...Args, template<class...> class T>
ostream &operator<<(enable_if_t<!is_same_v<T<Args...>, string>, ostream> &out, const T<Args...> &arr){
	for(auto &x: arr) out << x << " "; return out << "\n";
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<double> vd; typedef vector<string> vs;
typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<int, ll> pil; typedef pair<ll, int> pli;
typedef vector<pii> vpii; typedef vector<pil> vpil; typedef vector<pli> vpli; typedef vector<pll> vpll;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl; typedef vector<tpl> vtpl;

template<class T, class BO = function<T(T, T)>>
struct sparse_table: vector<vector<T>>{
	int N;
	BO bin_op;
	sparse_table(const vector<T> &arr, BO bin_op = [](T x, T y){return min(x, y);}): N(arr.size()), bin_op(bin_op){
		int t = 1, d = 1;
		while(t < N) t *= 2, ++ d;
		this->assign(d, arr);
		for(int i = 0; i < d - 1; ++ i) for(int j = 0; j < N; ++ j){
			(*this)[i + 1][j] = bin_op((*this)[i][j], (*this)[i][min(N - 1, j + (1 << i))]);
		}
	}
	sparse_table(){}
	T query(int l, int r){
		int d = 31 - __builtin_clz(r - l);
		return bin_op((*this)[d][l], (*this)[d][r - (1 << d)]);
	}
	sparse_table operator=(const sparse_table &otr){
		N = otr.N, bin_op = otr.bin_op; this->clear();
		for(auto &t: otr) this->push_back(t);
		return *this;
	}
};
template<int lim = 256>
struct suffix_array{
	int N;
	string s;
	vi p, c, l; // p[i]: starting index of i-th suffix in SA, c[i]: position of suffix of index i in SA, l: lcp array
	sparse_table<int, function<int(int, int)>> rmq;
	suffix_array(const string &s): N(s.size()), c(N), s(s){
		p = sort_cyclic_shifts(s + "$");
		p.erase(p.begin());
		for(int i = 0; i < N; ++ i) c[p[i]] = i;
		l = get_lcp(p);
		rmq = sparse_table<int, function<int(int, int)>>(l);
	}
	vi sort_cyclic_shifts(const string &s){
		int n = s.size();
		vi p(n), c(n), cnt(max(lim, n));
		for(auto x: s) ++ cnt[x];
		for(int i = 1; i < lim; ++ i) cnt[i] += cnt[i - 1];
		for(int i = 0; i < n; ++ i) p[-- cnt[s[i]]] = i;
		int classes = 1;
		for(int i = 1; i < n; ++ i){
			if(s[p[i]] != s[p[i - 1]]) classes ++;
			c[p[i]] = classes - 1;
		}
		vi pn(n), cn(n);
		for(int h = 0; (1 << h) < n; ++ h){
			for(int i = 0; i < n; ++ i){
				pn[i] = p[i] - (1 << h);
				if(pn[i] < 0) pn[i] += n;
			}
			fill(cnt.begin(), cnt.begin() + classes, 0);
			for(auto x: pn) ++ cnt[c[x]];
			for(int i = 1; i < classes; ++ i) cnt[i] += cnt[i - 1];
			for(int i = n - 1; i >= 0; -- i) p[-- cnt[c[pn[i]]]] = pn[i];
			cn[p[0]] = 0, classes = 1;
			for(int i = 1; i < n; ++ i){
				if(c[p[i]] != c[p[i - 1]] || c[(p[i] + (1 << h)) % n] != c[(p[i - 1] + (1 << h)) % n]){
					++ classes;
				}
				cn[p[i]] = classes - 1;
			}
			c.swap(cn);
		}
		return p;
	}
	vi get_lcp(const vector<int> &p){
		int n = sz(s);
		vi rank(n);
		for(int i = 0; i < n; ++ i) rank[p[i]] = i;
		int k = 0;
		vi l(n - 1);
		for(int i = 0; i < n; ++ i){
			if(rank[i] == n - 1){
				k = 0;
				continue;
			}
			int j = p[rank[i] + 1];
			while(i + k < n && j + k < n && s[i + k] == s[j + k]) ++ k;
			l[rank[i]] = k;
			if(k) -- k;
		}
		return l;
	}
	int lcp(int i, int j){
		return rmq.query(min(c[i], c[j]), max(c[i], c[j]));
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s;
	int m;
	cin >> s >> m;
	int n = sz(s);
	string t(s);
	reverse(all(t));
	vi size;
	while(m --){
		string u;
		cin >> u;
		size.push_back(sz(u));
		s += u;
		reverse(all(u));
		t += u;
	}
	suffix_array sa1(s), sa2(t);
	int res = 0;
	for(auto S: size){
		static int l = n, r;
		r = l + S;
		if(S > 1 && S <= n){
			static vi pref(n + 1);
			for(int i = 0; i < n; ++ i){
				pref[i + 1] = max(pref[i], sa1.lcp(i, l));
			}
			for(int i = 0; i + S <= n; ++ i){
				if(pref[i + 1] + sa2.lcp(n - i - S, l)>= S){
					res ++;
					break;
				}
			}
		}
		l = r;
	}
	cout << res;
	return 0;
}
 
/*
 
*/
 
////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////