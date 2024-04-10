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
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s;
	for(string in; cin >> in; ){
		s += in;
	}
	int n = int(s.size());
	vector<int> res;
	for(int i = 0; i < n; ){
		static vector<int> cnt;
		int j = i;
		while(s[j] != '>'){
			++ j;
		}
		if(s[i + 1] == 't' && s[j - 1] == 'e'){
			cnt.push_back(0);
		}
		else if(s[i + 2] == 't' && s[j - 1] == 'e'){
			res.push_back(cnt.back());
			cnt.pop_back();
		}
		else if(!cnt.empty() && s[i + 1] == 't' && s[j - 1] == 'd'){
			++ cnt.back();
		}
		i = j + 1;
	}
	sort(res.begin(), res.end());
	for(auto x: res){
		cout << x << " ";
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