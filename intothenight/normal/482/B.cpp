#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<array<int, 3>> q(qn);
	for(auto &[l, r, x]: q){
		cin >> l >> r >> x, -- l;
	}
	const int mx = 30;
	vector<int> res(n);
	for(auto bit = 0; bit < mx; ++ bit){
		vector<int> update(n + 1);
		for(auto [l, r, x]: q){
			if(x & 1 << bit){
				++ update[l], -- update[r];
			}
		}
		vector<int> pref(n + 1);
		for(auto i = 0; i < n; ++ i){
			update[i + 1] += update[i];
			update[i] = !!update[i];
			pref[i + 1] = pref[i] + update[i];
		}
		for(auto [l, r, x]: q){
			if(~x & 1 << bit && pref[r] - pref[l] == r - l){
				cout << "NO\n";
				return 0;
			}
		}
		for(auto i = 0; i < n; ++ i){
			res[i] |= update[i] << bit;
		}
	}
	cout << "YES\n";
	for(auto x: res){
		cout << x << " ";
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