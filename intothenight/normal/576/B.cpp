#include <bits/stdc++.h>
using namespace std;

struct permutation: vector<int>{
	using vector<int>::size;
	permutation operator+(const permutation &otr) const{
		permutation res(size());
		for(auto i = 0; i < (int)size(); ++ i) res[i] = (*this)[otr[i]];
		return res;
	}
	permutation &operator+=(const permutation &otr){
		return *this = *this + otr;
	}
	permutation operator-() const{
		permutation res(size());
		for(auto i = 0; i < (int)size(); ++ i) res[(*this)[i]] = i;
		return res;
	}
	permutation operator-(const permutation &otr) const{
		permutation res(size());
		for(auto i = 0; i < (int)size(); ++ i) res[otr[i]] = (*this)[i];
		return res;
	}
	permutation &operator-=(const permutation &otr){
		return *this = *this - otr;
	}
	vector<vector<int>> decompose() const{
		vector<int> vis(size());
		vector<vector<int>> res;
		for(auto i = 0; i < (int)size(); ++ i) if(!vis[i]){
			vector<int> cycle;
			for(auto j = i; !vis[j]; j = (*this)[j]) vis[j] = true, cycle.push_back(j);
			res.push_back(cycle);
		}
		return res;
	}
	permutation operator*(long long n) const{
		if(!n) return permutation(size());
		if(n == 1) return *this;
		if(n == -1) return -*this;
		permutation res(size());
		for(auto cycle: decompose()) for(auto i = 0, j = (int)(n % cycle.size()); i < (int)cycle.size(); ++ i, ++ j){
			if(j < 0) j += (int)cycle.size();
			if(j >= (int)cycle.size()) j -= (int)cycle.size();
			res[cycle[i]] = cycle[j];
		}
		return res;
	}
	permutation &operator*=(long long n){
		return *this = *this * n;
	}
	permutation(int n): vector<int>(n){
		iota(this->begin(), this->end(), 0);
	}
};
permutation operator*(long long n, const permutation &p){
	return p * n;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	permutation p(n);
	for(auto i = 0; i < n; ++ i){
		cin >> p[i], -- p[i];
	}
	auto C = p.decompose();
	sort(C.begin(), C.end(), [&](auto &x, auto &y){ return (int)x.size() < (int)y.size(); });
	if((int)C[0].size() >= 3){
		cout << "NO\n";
		return 0;
	}
	vector<array<int, 2>> res;
	if((int)C[0].size() == 2){
		res.push_back({C[0][0], C[0][1]});
	}
	for(auto i = 1; i < (int)C.size(); ++ i){
		if((int)C[i].size() % (int)C[0].size()){
			cout << "NO\n";
			return 0;
		}
		for(auto j = 0; j < (int)C[i].size(); j += (int)C[0].size()){
			for(auto k = 0; k < (int)C[0].size(); ++ k){
				res.push_back({C[0][k], C[i][j + k]});
			}
		}
	}
	cout << "YES\n";
	for(auto [u, v]: res){
		cout << u + 1 << " " << v + 1 << "\n";
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