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
	int n;
	cin >> n;
	vector<string> a;
	for(string s; cin >> s; ){
		a.push_back(s);
	}
	auto fail = [&](){
		cout << "Error occurred";
		exit(0);
	};
	if(int(a.size()) != 2 * n - 1){
		fail();
	}
	if(n == 1){
		if(a[0] == "int"){
			cout << a[0];
			return 0;
		}
		else{
			fail();
		}
	}
	string res;
	vector<int> cnt;
	for(auto s: a){
		if(s == "pair"){
			res += s + '<';
			cnt.push_back(0);
		}
		else{
			res += s;
			while(!cnt.empty() && cnt.back() == 1){
				res += '>';
				cnt.pop_back();
			}
			if(!cnt.empty()){
				++ cnt.back();
				res += ',';
			}
		}
	}
	if(!cnt.empty()){
		fail();
	}
	cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////