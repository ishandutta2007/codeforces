#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename Str>
vector<int> prefix_function(const Str &s){
	int n = int(s.size());
	vector<int> p(n);
	for(int i = 1; i < n; ++ i){
		int j = p[i - 1];
		while(j > 0 && s[i] != s[j]) j = p[j - 1];
		if(s[i] == s[j]) ++ j;
		p[i] = j;
	}
	return p;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s, t;
	cin >> s >> t;
	int n = int(t.size());
	vector<int> cnt(2);
	for(auto c: s){
		++ cnt[c - '0'];
	}
	auto p = prefix_function(t);
	int r = n - p.back();
	vector<int> fcnt(2), scnt(2);
	for(auto i = 0; i < p.back(); ++ i){
		++ fcnt[t[i] - '0'];
	}
	if(cnt[0] < fcnt[0] || cnt[1] < fcnt[1]){
		cout << s << "\n";
	}
	else{
		cnt[0] -= fcnt[0], cnt[1] -= fcnt[1];
		for(auto i = p.back(); i < n; ++ i){
			++ scnt[t[i] - '0'];
		}
		string res = t.substr(0, p.back());
		while(cnt[0] >= scnt[0] && cnt[1] >= scnt[1]){
			res.append(t.substr(p.back()));
			cnt[0] -= scnt[0], cnt[1] -= scnt[1];
		}
		res.append(cnt[0], '0'), res.append(cnt[1], '1');
		cout << res << "\n";
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