#include "bits/stdc++.h"
using namespace std;



int solve_testcase(){
	int n, k;
	cin >> n >> k;
	vector<string> res(n, string(n, '0'));
	vector<int> r(n), c(n);
	for(auto i = 0; i < k; ++ i){
		res[(i / n + i) % n][i % n] = '1';
		++ r[(i / n + i) % n], ++ c[i % n];
	}
	auto sq = [&](int x){
		return x * x;
	};
	auto get = [&](auto r){
		return sq(*max_element(r.begin(), r.end()) - *min_element(r.begin(), r.end()));
	};
	cout << get(r) + get(c) << "\n";
	for(auto s: res){
		cout << s << "\n";
	}
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		solve_testcase();
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