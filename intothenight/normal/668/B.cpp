#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	array<int, 2> delta{};
	auto normalize = [&](int i){
		i %= n;
		if(i < 0){
			i += n;
		}
		return i;
	};
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 1){
			int x;
			cin >> x;
			for(auto r = 0; r < 2; ++ r){
				delta[r] += x;
			}
		}
		else{
			for(auto r = 0; r < 2; ++ r){
				if(delta[r] + r & 1){
					-- delta[r];
				}
				else{
					++ delta[r];
				}
			}
		}
		for(auto r = 0; r < 2; ++ r){
			delta[r] = normalize(delta[r]);
		}
	}
	vector<int> res(n);
	for(auto i = 0; i < n; ++ i){
		res[normalize(i + delta[i & 1])] = i + 1;
	}
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