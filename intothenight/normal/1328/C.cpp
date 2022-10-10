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



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		int n;
		string s;
		cin >> n >> s;
		string a, b;
		bool check = false;
		for(int i = 0; i < n; ++ i){
			if(check){
				a.push_back('0');
				b.push_back(s[i]);
			}
			else{
				if(s[i] == '0'){
					a.push_back('0');
					b.push_back('0');
				}
				else if(s[i] == '2'){
					a.push_back('1');
					b.push_back('1');
				}
				else{
					check = true;
					a.push_back('1');
					b.push_back('0');
				}
			}
		}
		cout << a << "\n" << b << "\n";
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