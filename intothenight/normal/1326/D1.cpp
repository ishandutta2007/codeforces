#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename Str>
struct polyhash: vector<vector<long long>>{
	const int lim;
	const long long base, mod;
	vector<long long> p;
	polyhash(int lim, long long mod): lim(lim), p(lim, 1), mod(mod), base(rngll() % (long long)(0.4 * mod) + 0.3 * mod){
		for(int i = 1; i < lim; ++ i) p[i] = p[i - 1] * base % mod;
	}
	void insert(const Str &s){
		this->emplace_back(s.size() + 1);
		for(int i = 0; i < int(s.size()); ++ i) this->back()[i + 1] = (this->back()[i] * base + s[i]) % mod;
	}
	void extend(typename Str::value_type c, int i = 0){
		(*this)[i].push_back(((*this)[i].back() * base + c) % mod);
	}
	long long query(int ql, int qr, int i = 0){
		return ((*this)[i][qr] - (*this)[i][ql] * p[qr - ql] % mod + mod) % mod;
	}
	int lcp(int i, int j, int posi = 0, int posj = 0){ // returns the length
		int low = 0, high = min(int((*this)[i].size()) - posi, int((*this)[j].size()) - posj);
		while(high - low > 1){
			int mid = low + high >> 1;
			query(posi, posi + mid, i) == query(posj, posj + mid, j) ? low = mid : high = mid;
		}
		return low;
	}
	int lcs(int i, int j, int posi, int posj){
		int low = 0, high = min(posi, posj) + 1;
		while(high - low > 1){
			int mid = low + high >> 1;
			query(posi - mid, posi, i) == query(posj - mid, posj, j) ? low = mid : high = mid;
		}
		return low;
	}
	vector<int> search(const Str &s, bool FIND_ALL = true, int i = 0){
		int len = s.size();
		long long v = 0;
		for(auto c: s) v = (v * base + c) % mod;
		vector<int> res;
		for(int j = 0; j + len < (*this)[i].size(); ++ j) if(v == query(j, j + len, i)){
			res.push_back(j);
			if(!FIND_ALL) break;
		}
		return res;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		string s;
		cin >> s;
		string t(s);
		reverse(t.begin(), t.end());
		int n = int(s.size());
		polyhash<string> hash(n + 1, 1e9 + 7);
		hash.insert(s), hash.insert(t);
		array<int, 4> res{0, 0, 0, 0}; // len, ttt, parity, i
		for(int ttt = 0; ttt < 2; ++ ttt){
			for(int i = 1; i <= n; ++ i){
				if(n - i >= i){ // even
					if(hash.lcp(0, 1) + hash.lcs(0, 1, i, n - i) >= i){
						ctmax(res, {2 * i, ttt, 0, i});
					}
				}
				if(n - i >= i - 1){ // odd
					if(hash.lcp(0, 1) + hash.lcs(0, 1, i, n + 1 - i) >= i){
						ctmax(res, {2 * i - 1, ttt, 1, i});
					}
				}
			}
			swap(hash[0], hash[1]);
		}
		if(res[1]){
			swap(s, t);
		}
		if(res[2]){
			string a = s.substr(0, res[3]);
			int sz = int(a.size());
			for(int i = sz - 2; i >= 0; -- i){
				a.push_back(a[i]);
			}
			cout << a << "\n";
		}
		else{
			string a = s.substr(0, res[3]);
			int sz = int(a.size());
			for(int i = sz - 1; i >= 0; -- i){
				a.push_back(a[i]);
			}
			cout << a << "\n";
		}
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