#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<array<int, 4>> query(qn);
	for(auto i = 0; i < qn; ++ i){
		for(auto j = 0; j < 4; ++ j){
			cin >> query[i][j];
		}
		-- query[i][1];
	}
	reverse(query.begin(), query.end());
	vector<int> a(n, numeric_limits<int>::max() / 2);
	for(auto [t, l, r, x]: query){
		if(t == 1){
			for(auto i = l; i < r; ++ i){
				a[i] -= x;
			}
		}
		else{
			for(auto i = l; i < r; ++ i){
				a[i] = min(a[i], x);
			}
		}
	}
	for(auto &x: a){
		if(x < -1'000'000'000){
			cout << "NO\n";
			return 0;
		}
		x = min(x, 1'000'000'000);
	}
	auto temp = a;
	reverse(query.begin(), query.end());
	for(auto [t, l, r, x]: query){
		if(t == 1){
			for(auto i = l; i < r; ++ i){
				a[i] += x;
			}
		}
		else{
			if(*max_element(a.begin() + l, a.begin() + r) != x){
				cout << "NO\n";
				return 0;
			}
		}
	}
	a = temp;
	cout << "YES\n";
	for(auto x: a){
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