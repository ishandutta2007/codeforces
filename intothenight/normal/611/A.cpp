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
	vector<string> a(3);
	copy_n(istream_iterator<string>(cin), 3, a.begin());
	int x = stoi(a[0]);
	if(a[2] == "month"){
		if(x <= 29){
			cout << 12;
		}
		else if(x <= 30){
			cout << 11;
		}
		else{
			cout << 7;
		}
	}
	else{
		switch(x){
			case 1:
			cout << 52;
			break;
			case 2:
			cout << 52;
			break;
			case 3:
			cout << 52;
			break;
			case 4:
			cout << 52;
			break;
			case 5:
			cout << 53;
			break;
			case 6:
			cout << 53;
			break;
			default:
			cout << 52;
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