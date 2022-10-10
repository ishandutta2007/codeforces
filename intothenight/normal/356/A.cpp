#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	set<int> rem;
	for(auto i = 0; i < n; ++ i){
		rem.insert(i);
	}
	vector<int> res(n, -1);
	for(auto i = 0; i < m; ++ i){
		int l, r, x;
		cin >> l >> r >> x, -- l, -- x;
		auto it = rem.lower_bound(l);
		while(it != rem.end() && *it < r){
			if(*it == x){
				++ it;
			}
			else{
				res[*it] = x;
				it = rem.erase(it);
			}
		}
	}
	for(auto &u: res){
		cout << u + 1 << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////