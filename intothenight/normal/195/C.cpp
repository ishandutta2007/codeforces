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
	cin >> n >> ws;
	bool active = false;
	while(n --){
		string s;
		getline(cin, s);
		static vector<string> st;
		int i = find_if(s.begin(), s.end(), [&](auto x){ return x != ' '; }) - s.begin();
		if(i == int(s.size())){
			continue;
		}
		while(s.back() == ' '){
			s.pop_back();
		}
		if(s[i + 1] == 'r'){ // try
			st.emplace_back();
		}
		else if(s[i + 1] == 'h'){ // throw
			if(!st.empty()){
				s.pop_back();
				i = find_if(find(i + s.begin(), s.end(), '(') + 1, s.end(), [&](auto x){ return x != ' '; }) - s.begin();
				int j = find(i + s.begin(), s.end(), ' ') - s.begin();
				st.back() = s.substr(i, j - i);
			}
		}
		else{ // catch
			s.pop_back();
			string cur;
			i = find_if(find(i + s.begin(), s.end(), '(') + 1, s.end(), [&](auto x){ return x != ' '; }) - s.begin();
			int j = find_if(i + s.begin(), s.end(), [&](auto x){ return x == ' ' || x == ','; }) - s.begin();
			if(s.substr(i, j - i) == st.back()){
				i = find(s.begin() + j, s.end(), '"') - s.begin() + 1;
				int j = find(s.begin() + i, s.end(), '"') - s.begin();
				cout << s.substr(i, j - i);
				return 0;
			}
			else if(int(st.size()) > 1 && !st.back().empty()){
				*next(st.rbegin()) = move(st.back());
				st.pop_back();
			}
			else{
				st.pop_back();
			}
		}
	}
	cout << "Unhandled Exception";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////