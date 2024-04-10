#include <bits/stdc++.h>
using namespace std;



template<size_t SZ>
struct Z2_OR_AND_matrix_base: vector<bitset<SZ>>{
	using C = vector<bitset<SZ>>;
	using C::assign;
	Z2_OR_AND_matrix_base &operator+=(const Z2_OR_AND_matrix_base &M){
		assert(n == M.n && m == M.m);
		for(auto i = 0; i < n; ++ i) (*this)[i] |= M[i];
		return *this;
	}
	Z2_OR_AND_matrix_base operator+(const Z2_OR_AND_matrix_base &M) const{
		Z2_OR_AND_matrix_base res(n, m);
		res += M;
		return res;
	}
	Z2_OR_AND_matrix_base operator*(const Z2_OR_AND_matrix_base &otr) const{
		assert(m == otr.n);
		int l = otr.m;
		Z2_OR_AND_matrix_base res(n, l);
		vector<bitset<SZ>> temp(l);
		for(auto i = 0; i < l; ++ i) for(auto j = 0; j < m; ++ j) temp[i][j] = otr[j][i];
		for(auto i = 0; i < n; ++ i) for(auto j = 0; j < l; ++ j) res[i][j] = ((*this)[i] & temp[j]).any();
		return res;
	}
	Z2_OR_AND_matrix_base &operator*=(const Z2_OR_AND_matrix_base &otr){
		return *this = *this * otr;
	}
	Z2_OR_AND_matrix_base &operator*=(bool c){
		if(!c) for(auto &v: *this) v.reset();
		return *this;
	}
	Z2_OR_AND_matrix_base operator*(bool c) const{
		Z2_OR_AND_matrix_base res(*this); res *= c;
		return res;
	}
	Z2_OR_AND_matrix_base &operator^=(long long e){
		Z2_OR_AND_matrix_base res(n, n, true);
		for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
		return *this = res;
	}
	Z2_OR_AND_matrix_base operator^(long long e) const{
		assert(n == m);
		Z2_OR_AND_matrix_base res(*this); res ^= e;
		return res;
	}
	Z2_OR_AND_matrix_base transposed() const{
		Z2_OR_AND_matrix_base res(m, n);
		for(auto i = 0; i < n; ++ i) for(auto j = 0; j < m; ++ j) res[j][i] = (*this)[i][j];
		return res;
	}
	Z2_OR_AND_matrix_base &transpose(){
		return *this = transposed();
	}
	Z2_OR_AND_matrix_base inversed() const{
		Z2_OR_AND_matrix_base res(*this);
		res.inverse();
		return res;
	}
	vector<int> operator*(const bitset<SZ> &v) const{
		vector<int> res(n);
		for(auto i = 0; i < n; ++ i) res[i] = ((*this)[i] * v).any();
		return res;
	}
	int n, m;
	Z2_OR_AND_matrix_base(int n, int m, bool init_diagonal = false, bool init_off_diagonal = false): n(n), m(m){
		assign(n, {});
		for(auto i = 0; i < n; ++ i) for(auto j = 0; j < m; ++ j) (*this)[i][j] = i == j ? init_diagonal : init_off_diagonal;
	}
	Z2_OR_AND_matrix_base(const C &arr): n((int)arr.size()), m((int)arr[0].size()){
		assign(n, {});
		for(auto i = 0; i < n; ++ i) for(auto j = 0; j < m; ++ j) (*this)[i][j] = arr[i][j];
	}
};
template<size_t SZ>
Z2_OR_AND_matrix_base<SZ> operator*(bool c, Z2_OR_AND_matrix_base<SZ> M){
	if(!c) for(auto &v: M) v.reset();
	return M;
}
template<size_t SZ>
vector<int> operator*(const vector<int> &v, const Z2_OR_AND_matrix_base<SZ> &M){
	vector<int> res(M.m);
	for(auto i = 0; i < M.n; ++ i) for(auto j = 0; j < M.m; ++ j) res[j] |= v[i] * M[i][j];
	return res;
}
const size_t SZ = 150;
using Z2_OR_AND_matrix = Z2_OR_AND_matrix_base<SZ>;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<array<int, 3>> edges(m);
	for(auto &[w, u, v]: edges){
		cin >> u >> v >> w, -- u, -- v;
	}
	sort(edges.begin(), edges.end());
	Z2_OR_AND_matrix adj(n, n);
	int res = numeric_limits<int>::max();
	vector<int> reach(n);
	reach[0] = 1;
	int pw = 0;
	for(auto [w, u, v]: edges){
		reach = reach * (adj ^ w - pw);
		pw = w;
		adj[u][v] = 1;
		vector<int> dist(n, -1);
		deque<int> dq;
		for(auto u = 0; u < n; ++ u){
			if(reach[u]){
				dq.push_back(u);
				dist[u] = 0;
			}
		}
		while(!dq.empty()){
			int u = dq.front(); dq.pop_front();
			for(auto v = adj[u]._Find_first(); v < n; v = adj[u]._Find_next(v)){
				if(adj[u][v] && !~dist[v]){
					dist[v] = dist[u] + 1;
					dq.push_back(v);
				}
			}
		}
		if(~dist[n - 1]){
			ctmin(res, w + dist[n - 1]);
		}
	}
	res == numeric_limits<int>::max() ? cout << "Impossible\n" : cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////