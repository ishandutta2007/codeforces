#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int qn;
	cin >> qn;
	vector<array<int, 3>> q(qn);
	for(auto &[t, x, y]: q){
		cin >> t >> x;
		if(t == 2){
			cin >> y;
		}
	}
	const int mx = 5e5 + 1;
	vector<int> repr(mx);
	iota(begin(repr), end(repr), 0);
	vector<int> res;
	for(auto [t, x, y]: ranges::views::reverse(q)){
		if(t == 1){
			res.push_back(repr[x]);
		}
		else{
			repr[x] = repr[y];
		}
	}
	ranges::copy(ranges::views::reverse(res), ostream_iterator<int>(cout, " "));
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