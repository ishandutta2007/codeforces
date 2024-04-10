#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef bitset<200000> bs;
int solve_linear_equations(const vector<bs> &AA, bs& x, const vector<int> &bb, int m){
	vector<bs> A(AA);
	vector<int> b(bb);
	int n = int(A.size()), rank = 0, br;
	vector<int> col(m);
	iota(col.begin(), col.end(), 0);
	for(int i = 0; i < n; ++ i){
		for(br = i; br < n; ++ br) if(A[br].any()) break;
		if (br == n){
			for(int j = i; j < n; ++ j) if(b[j]) return -1;
			break;
		}
		int bc = (int)A[br]._Find_next(i-1);
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		for(int j = 0; j < n; ++ j) if(A[j][i] != A[j][bc]) A[j].flip(i), A[j].flip(bc);
		for(int j = i + 1; j < n; ++ j) if(A[j][i]) b[j] ^= b[i], A[j] ^= A[i];
		++ rank;
	}
	x = bs();
	for (int i = rank; i --;){
		if (!b[i]) continue;
		x[col[i]] = 1;
		for(int j = 0; j < i; ++ j) b[j] ^= A[j][i];
	}
	return rank;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	if(!accumulate(a.begin(), a.end(), 0, bit_xor<int>())){
		cout << -1;
		return 0;
	}
	vector<bs> coef(31);
	bs x;
	for(int bit = 0; bit < 32; ++ bit){
		for(int i = 0; i < n; ++ i){
			if(a[i] & 1 << bit){
				coef[bit].set(i);
			}
		}
	}
	cout << solve_linear_equations(coef, x, vector<int>(31), n);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////