#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
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
	int n;
	string s;
	cin >> n >> s;
	vector<int> pos, t, rt;
	for(int i = 0; i < n; ++ i){
		if(s[i] == '0'){
			pos.push_back(i);
			t.push_back(i % 2);
			rt.push_back(!t.back());
		}
	}
	polyhash<vector<int>> hash(200000, 1e9 + 7);
	hash.insert(t), hash.insert(rt);
	int qq;
	cin >> qq;
	while(qq --){
		int p1, p2, len;
		cin >> p1 >> p2 >> len, -- p1, -- p2;
		int l1 = lower_bound(pos.begin(), pos.end(), p1) - pos.begin(), r1 = lower_bound(pos.begin(), pos.end(), p1 + len) - pos.begin();
		int l2 = lower_bound(pos.begin(), pos.end(), p2) - pos.begin(), r2 = lower_bound(pos.begin(), pos.end(), p2 + len) - pos.begin();
		if(r1 - l1 == r2 - l2 && (abs(p1 - p2) & 1 && hash.query(l1, r1, 0) == hash.query(l2, r2, 1) || !(abs(p1 - p2) & 1) && hash.query(l1, r1) == hash.query(l2, r2))){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
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