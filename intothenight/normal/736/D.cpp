#include <bits/stdc++.h>
using namespace std;

template<size_t SZ>
struct Z2_matrix_base: vector<bitset<SZ>>{
	using C = vector<bitset<SZ>>;
	using C::assign;
	Z2_matrix_base &operator+=(const Z2_matrix_base &M){
		assert(n == M.n && m == M.m);
		for(int i = 0; i < n; ++ i) (*this)[i] ^= M[i];
		return *this;
	}
	Z2_matrix_base operator+(const Z2_matrix_base &M) const{
		Z2_matrix_base res(n, m); res += M;
		return res;
	}
	Z2_matrix_base operator*(const Z2_matrix_base &otr) const{
		assert(m == otr.n);
		int l = otr.m;
		Z2_matrix_base res(n, l);
		vector<bitset<SZ>> temp(l);
		for(int i = 0; i < l; ++ i) for(int j = 0; j < m; ++ j) temp[i][j] = otr[j][i];
		for(int i = 0; i < n; ++ i) for(int j = 0; j < l; ++ j) res[i][j] = ((*this)[i] & temp[j]).count() & 1;
		return res;
	}
	Z2_matrix_base &operator*=(const Z2_matrix_base &otr){
		return *this = *this * otr;
	}
	Z2_matrix_base &operator*=(bool c){
		if(c) for(int i = 0; i < n; ++ i) (*this)[i].flip();
		return *this;
	}
	Z2_matrix_base operator*(bool c) const{
		Z2_matrix_base res(*this); res *= c;
		return res;
	}
	Z2_matrix_base &operator^=(long long e){
		Z2_matrix_base res(n, n, true);
		for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
		return *this = res;
	}
	Z2_matrix_base operator^(long long e) const{
		assert(n == m);
		Z2_matrix_base res(*this); res ^= e;
		return res;
	}
	Z2_matrix_base transposed() const{
		Z2_matrix_base res(m, n);
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) res[j][i] = (*this)[i][j];
		return res;
	}
	Z2_matrix_base &transpose(){
		return *this = transposed();
	}
	bool det() const{
		assert(n == m);
		Z2_matrix_base temp(*this);
		for(int i = 0; i < n; ++ i){
			for(int j = i + 1; j < n; ++ j) if(temp[j][i]){
				if(temp[i][i]) temp[j] ^= temp[i];
				else swap(temp[i], temp[j]);
			}
			if(!temp[i][i]) return false;
		}
		return true;
	}
	bool inverse(){
		assert(n == m);
		C temp(*this), res(n);
		for(int i = 0; i < n; ++ i) res[i].set(i);
		for(int j = 0; j < n; ++ j){
			int pivot = -1;
			for(int i = j; i < n; ++ i) if(temp[i][j]){
				pivot = i;
				break;
			}
			if(!~pivot) return false;
			swap(temp[j], temp[pivot]), swap(res[j], res[pivot]);
			for(int i = 0; i < n; ++ i) if(i != j && temp[i][j]) temp[i] ^= temp[j], res[i] ^= res[j];
		}
		swap(*this, res);
		return true;
	}
	Z2_matrix_base inversed() const{
		Z2_matrix_base res(*this); res.inverse();
		return res;
	}
	int n, m;
	Z2_matrix_base(int n, int m, bool init_diagonal = false, bool init_off_diagonal = false): n(n), m(m){
		assign(n, {});
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) (*this)[i][j] = i == j ? init_diagonal : init_off_diagonal;
	}
	Z2_matrix_base(const C &arr): n((int)arr.size()), m((int)arr[0].size()){
		assign(n, {});
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j) (*this)[i][j] = arr[i][j];
	}
};
template<size_t SZ>
Z2_matrix_base<SZ> operator*(bool c, Z2_matrix_base<SZ> M){
	if(c) for(int i = 0; i < M.n; ++ i) M[i].flip();
	return M;
}
const size_t SZ = 2e3;
using Z2_matrix = Z2_matrix_base<SZ>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<array<int, 2>> a(m);
	Z2_matrix M(n, n);
	for(auto &[x, y]: a){
		cin >> x >> y, -- x, -- y;
		M[x][y] = true;
	}
	assert(M.inverse());
	for(auto [x, y]: a){
		M[y][x] ? cout << "NO\n" : cout << "YES\n";
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