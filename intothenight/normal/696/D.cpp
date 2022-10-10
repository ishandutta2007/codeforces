#include <bits/stdc++.h>
using namespace std;

template<int lim = 26>
struct aho_corasic_automaton_fixed{
	function<int(int)> convert;
	struct node{
		array<int, lim> next;
		int depth = 0;
		int link = -1, exit_link = -1; // longest proper suffix, longest porper suffix which is also a leaf
		int cnt = 0, leafcnt = 0;
		long long val = 0;
	};
	vector<node> states = {{}};
	aho_corasic_automaton_fixed(function<int(int)> convert = [](int c){ return tolower(c) - 'a'; }): convert(convert){ }
	template<class Str>
	aho_corasic_automaton_fixed(const vector<Str> &a, function<int(int)> convert = [](int c){ return tolower(c) - 'a'; }): convert(convert){
		insert(a), build();
	}
	void clear(){
		states = {{}};
	}
	template<class Str>
	void insert(const vector<Str> &a){
		for(auto &s: a) insert(s);
	}
	template<class Str>
	int insert(const Str &s){ // add word
		int u = 0;
		++ states[u].cnt;
		for(auto C: s){
			int c = convert(C);
			if(!states[u].next[c]){
				states[u].next[c] = (int)states.size();
				states.emplace_back();
				states.back().depth = states[u].depth + 1;
			}
			u = states[u].next[c];
			++ states[u].cnt;
		}
		++ states[u].leafcnt;
		return u;
	}
	int next_state(int u, int c){
		return states[u].next[c];
	}
	void build(){ // generate links
		deque<int> dq{0};
		while(!dq.empty()){
			int u = dq.front(); dq.pop_front();
			for(auto c = 0; c < lim; ++ c) if(states[u].next[c]){
				int v = states[u].next[c];
				states[v].link = !~states[u].link ? 0 : states[states[u].link].next[c];
				states[v].exit_link = states[states[v].link].leafcnt ? states[v].link : states[states[v].link].exit_link;
				dq.push_back(v); 
			}
			if(u) for(auto c = 0; c < lim; ++ c) if(!states[u].next[c]) states[u].next[c] = states[states[u].link].next[c];
		}
	}
};

template<class T, T (*zero)(), T (*one)()> // T must support +=, *=, *
struct matrix_base: vector<vector<T>>{
	using C = vector<vector<T>>; // container type
	using C::assign;
	matrix_base &operator+=(const matrix_base &M){
		assert(n == M.n && m == M.m);
		for(auto i = 0; i < n; ++ i) for(auto j = 0; j < m; ++ j) (*this)[i][j] += M[i][j];
		return *this;
	}
	matrix_base operator+(const matrix_base &M) const{
		matrix_base res(*this); res += M;
		return res;
	}
	matrix_base operator*(const matrix_base &M) const{
		assert(m == M.n);
		int l = M.m;
		matrix_base res(n, l);
		for(auto i = 0; i < n; ++ i) for(auto j = 0; j < m; ++ j) for(auto k = 0; k < l; ++ k) res[i][k] += (*this)[i][j] * M[j][k];
		return res;
	}
	matrix_base &operator*=(const matrix_base &M){
		return *this = *this * M;
	}
	matrix_base &operator*=(T c){
		for(auto i = 0; i < n; ++ i) for(auto j = 0; j < m; ++ j) (*this)[i][j] *= c;
		return *this;
	}
	matrix_base operator*(T c) const{
		matrix_base res(*this); res *= c;
		return res;
	}
	matrix_base &operator^=(long long e){
		assert(e >= 0);
		matrix_base res(n, n, one());
		for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
		return *this = res;
	}
	matrix_base operator^(long long e) const{
		assert(n == m);
		matrix_base res(*this); res ^= e;
		return res;
	}
	matrix_base transposed() const{
		matrix_base res(m, n);
		for(auto i = 0; i < n; ++ i) for(auto j = 0; j < m; ++ j) res[j][i] = (*this)[i][j];
		return res;
	}
	matrix_base &transpose(){
		return *this = transposed();
	}
	vector<T> maps_to(const vector<T> &v) const{
		assert(m == (int)v.size());
		vector<T> res(n, zero());
		for(auto i = 0; i < n; ++ i) for(auto j = 0; j < m; ++ j) res[i] += (*this)[i][j] * v[j];
		return res;
	}
	int n, m;
	matrix_base(int n, int m, T init_diagonal = zero(), T init_off_diagonal = zero()): n(n), m(m){
		assign(n, vector<T>(m, zero()));
		for(auto i = 0; i < n; ++ i) for(auto j = 0; j < m; ++ j) (*this)[i][j] = i == j ? init_diagonal : init_off_diagonal;
	}
	matrix_base(const C &arr): n((int)arr.size()), m((int)arr[0].size()){
		assign(n, vector<T>(m, zero()));
		for(auto i = 0; i < n; ++ i) for(auto j = 0; j < m; ++ j) (*this)[i][j] = arr[i][j];
	}
};
template<class T, T (*zero)(), T (*one)()>
matrix_base<T, zero, one> operator*(T c, matrix_base<T, zero, one> M){
	for(auto i = 0; i < M.n; ++ i) for(auto j = 0; j < M.m; ++ j) M[i][j] = c * M[i][j];
	return M;
}
template<class T> T ZERO(){
	return {numeric_limits<long long>::min() / 2};
}
template<class T> T ONE(){
	return {0};
}
template<class T> using matrix = matrix_base<T, ZERO<T>, ONE<T>>;
struct X{
	long long data;
	X &operator+=(const X &otr){
		data = max(data, otr.data);
		return *this;
	}
	X &operator*=(const X &otr){
		data += otr.data;
		return *this;
	}
	X operator*(const X &otr) const{
		return {data + otr.data};
	}
};
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	long long len;
	cin >> n >> len;
	aho_corasic_automaton_fixed aut;
	vector<int> w(n);
	for(auto i = 0; i < n; ++ i){
		cin >> w[i];
	}
	for(auto i = 0; i < n; ++ i){
		string s;
		cin >> s;
		int u = aut.insert(s);
		aut.states[u].val += w[i];
	}
	aut.build();
	int sz = (int)aut.states.size();
	vector<long long> calc(sz);
	for(auto u = 0; u < sz; ++ u){
		for(auto v = u; ~v; v = aut.states[v].exit_link){
			calc[u] += aut.states[v].val;
		}
	}
	matrix<X> mat(sz, sz);
	for(auto u = 0; u < sz; ++ u){
		for(auto c = 0; c < 26; ++ c){
			mat[u][aut.next_state(u, c)] = {calc[aut.next_state(u, c)]};
		}
	}
	mat ^= len;
	long long res = 0;
	for(auto u = 0; u < sz; ++ u){
		ctmax(res, mat[0][u].data);
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