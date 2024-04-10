#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());


typedef bitset<100000> bs;
int solve_linear_equations(vector<bs> A, bs &x, vector<int> b, int m){
	int n = int(A.size()), rank = 0, br;
	vector<int> col(m);
	iota(col.begin(), col.end(), 0);
	for(int i = 0; i < n; ++ i){
		for(br = i; br < n; ++ br) if(A[br].any()) break;
		if(br == n){
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
	for(int i = rank; i --; ){
		if(!b[i]) continue;
		x[col[i]] = 1;
		for(int j = 0; j < i; ++ j) b[j] ^= A[j][i];
	}
	return rank;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	long long x;
	cin >> x;
	vector<long long> pool{x};
	vector<string> res;
	auto insert = [&](int i, int j, char c){
		res.push_back(to_string(pool[i]) + " " + c + " " + to_string(pool[j]));
		if(c == '+'){
			pool.push_back(pool[i] + pool[j]);
		}
		else{
			pool.push_back(pool[i] ^ pool[j]);
		}
	};
	const int mx = 40;
	for(auto i = 0; i < mx; ++ i){
		insert(i, i, '+');
	}
	const long long th = 4e18;
	for(auto rep = 0; rep < 400; ++ rep){
		int i = rng() % (int)pool.size(), j = rng() % (int)pool.size();
		if(pool[i] + pool[j] >= th){
			insert(i, j, '^');
		}
		else{
			insert(i, j, rng() % 2 ? '+' : '^');
		}
	}
	const int bitmx = 63;
	vector<bs> A(bitmx);
	for(auto bit = 0; bit < bitmx; ++ bit){
		for(auto i = 0; i < (int)pool.size(); ++ i){
			if(pool[i] & 1LL << bit){
				A[bit].set(i);
			}
		}
	}
	vector<int> b(bitmx);
	b[0] = 1;
	bs sol;
	assert(~solve_linear_equations(A, sol, b, (int)pool.size()));
	vector<long long> a;
	for(auto i = 0; i < (int)pool.size(); ++ i){
		if(sol[i]){
			a.push_back(pool[i]);
		}
	}
	assert((int)a.size() >= 2);
	long long	prev = a[0];
	for(auto i = 1; i < (int)a.size(); ++ i){
		res.push_back(to_string(prev) + " ^ " + to_string(a[i]));
		prev ^= a[i];
	}
	cout << (int)res.size() << "\n";
	for(auto s: res){
		cout << s << "\n";
	}
	return 0;
}

/*
(x-1)(x+1)
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////