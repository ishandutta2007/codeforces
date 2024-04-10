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
	cin >> s;
	int p = find(s.begin(), s.end(), '.') - s.begin();
	if(p == int(s.size())){
		s.push_back('.');
	}
	while(s.back() == '0'){
		s.pop_back();
	}
	int n = int(s.size());
	if(s.substr(0, p) == string(p, '0')){
		int q = find_if(p + 1 + s.begin(), s.end(), [&](auto x){ return x != '0'; }) - s.begin();
		cout << s[q];
		if(q != int(s.size()) - 1){
			cout << "." << s.substr(q + 1);
		}
		cout << "E-" << q - p;
	}
	else if(p == int(s.size()) - 1){
		int i = find_if(s.begin(), s.end(), [&](auto x){ return x != '0'; }) - s.begin();
		s.pop_back();
		while(s.back() == '0'){
			s.pop_back();
		}
		cout << s[i];
		if(int(s.size()) != i + 1){
			cout << "." << s.substr(i + 1);
		}
		if(i + 1 != p){
			cout << "E" << p - i - 1;
		}
	}
	else{
		int i = find_if(s.begin(), s.end(), [&](auto x){ return x != '0'; }) - s.begin();
		s.erase(s.begin() + p);
		cout << s[i] << "." << s.substr(i + 1);
		if(i + 1 != p){
			cout << "E" << p - i - 1;
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