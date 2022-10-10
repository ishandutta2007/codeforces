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
		cin >> n;
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		bool yes = true, flag = false;
		for(int i = 1; i < n; ++ i){
			if(a[i] == a[i - 1]){
				yes = false;
			}
			else{
				flag = true;
			}
		}
		if(a[0] == a.back()){
			yes = false;
		}
		else{
			flag = true;
		}
		if(yes && n % 2){
			cout << "3\n3 ";
			for(int i = 1; i < n; ++ i){
				cout << (i % 2 ? '1' : '2') << " ";
			}
			cout << "\n";
		}
		else if(flag){
			cout << "2\n";
			if(n % 2){
				bool done = false;
				for(int i = 1; i < n; ++ i){
					if(a[i - 1] == a[i]){
						for(int j = 0; j <= i - 1; ++ j){
							(i - 1 - j) % 2 ? cout << "2 " : cout << "1 ";
						}
						for(int j = i; j < n; ++ j){
							(j - i) % 2 ? cout << "2 " : cout << "1 ";
						}
						done = true;
						break;
					}
				}
				if(!done){
					for(int i = 0; i < n - 1; ++ i){
						i % 2 ? cout << "2 " : cout << "1 ";
					}
					cout << "1 ";
				}
			}
			else{
				for(int i = 0; i < n; ++ i){
					i % 2 ? cout << "1 " : cout << "2 ";
				}
			}
			cout << "\n";
		}
		else{
			cout << "1\n";
			for(int i = 0; i < n; ++ i){
				cout << "1 ";
			}
			cout << "\n";
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