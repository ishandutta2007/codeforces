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
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef vector<pii> vpii;
template<class T>
using Ftn = function<T(T, T)>;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tuple<int, int, int> tpl;
typedef vector<tpl> vtpl;

struct disjoint: vi{
	int N;
	// vector<pii> Log; // For persistency
	disjoint(int N): N(N){
		this->resize(N);
		iota(all((*this)), 0);
	}
	int root(int u){
		// Log.emplace_back(u, (*this)[u]);
		return (*this)[u] == u ? u : ((*this)[u] = root((*this)[u]));
	}
	void merge(int u, int v){
		(*this)[root(v)] = root(u);
	}
	int share(int u, int v){
		return root((*this)[u]) == root((*this)[v]);
	}
	/*void reverse(){
		auto [u, p] = Log.back();
		Log.pop_back();
		(*this)[u] = p;
	}*/
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vtpl edge(m);
	for(auto &[u, v, ind]: edge){
		static int cnt = 0;
		cin >> u >> v, u --, v --, ind = cnt ++;
	}
	reverse(all(edge));
	disjoint dsu(n);
	vector<vpii> adj(n);
	for(auto [u, v, ind]: edge){
		if(!dsu.share(u, v)){
			dsu.merge(u, v);
			adj[u].emplace_back(v, ind), adj[v].emplace_back(u, ind);
		}
	}
	vi depth(n);
	vpii par(n, {-1, -1});
	function<void(int, int)> dfs = [&](int u, int p){
		for(auto [v, ind]: adj[u]){
			if(v != p){
				depth[v] = depth[u] + 1;
				par[v] = {u, ind};
				dfs(v, u);
			}
		}
	};
	dfs(0, -1);
	vl d(n, 1), f(m);
	iota(all(dsu), 0);
	for(auto [u, v, ind]: edge){
		if(dsu.share(u, v)){
			int p = u, q = v;
			if(depth[p] < depth[q]) swap(p, q);
			vi path, path2;
			int mxind = -1;
			while(depth[p] > depth[q]){
				path.push_back(par[p].second);
				tie(p, mxind) = pii{par[p].first, max(mxind, par[p].second)};
			}
			while(p != q){
				path.push_back(par[p].second);
				tie(p, mxind) = pii{par[p].first, max(mxind, par[p].second)};
				path2.push_back(par[q].second);
				tie(q, mxind) = pii{par[q].first, max(mxind, par[q].second)};
			}
			reverse(all(path2));
			for(auto t: path2){
				path.push_back(t);
			}
			path2.clear();
			while(!path.empty() && path.back() != mxind){
				path2.push_back(path.back());
				path.pop_back();
			}
			if(is_sorted(all(path)) && is_sorted(all(path2))){
				f[ind] = d[u] = d[v] = d[u] + d[v] - f[mxind];
			}
			else{
				f[ind] = d[u] = d[v] = d[u] + d[v];
			}
		}
		else{
			dsu.merge(u, v);
			f[ind] = d[u] = d[v] = d[u] + d[v];
		}
	}
	for(auto x: d){
		cout << x - 1 << " ";
	}
	return 0;
}