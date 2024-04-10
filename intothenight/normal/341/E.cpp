#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	if(count(a.begin(), a.end(), 0) >= n - 1){
		cout << "-1\n";
		return 0;
	}
	vector<array<int, 2>> res;
	auto act = [&](int i, int j)->void{
		assert(a[i] >= a[j]);
		a[i] -= a[j];
		a[j] <<= 1;
		res.push_back({j, i});
	};
	for(auto p1 = 0, p2 = 1, i = 2; i < n; ++ i){
		array<int, 3> order{p1, p2, i};
		ranges::sort(order, [&](int i, int j){ return a[i] < a[j]; });
		while(a[order[0]]){
			if(a[order[1]] % a[order[0]] * 2 < a[order[0]]){
				for(auto q = a[order[1]] / a[order[0]]; q; q >>= 1){
					act(order[2 - (q & 1)], order[0]);
				}
			}
			else{
				for(auto q = a[order[1]] / a[order[0]] + 1; q >= 2; q >>= 1){
					act(order[2 - (q & 1)], order[0]);
				}
				act(order[0], order[1]);
			}
			ranges::sort(order, [&](int i, int j){ return a[i] < a[j]; });
		}
		while(p1 < i - 1 && !a[p1]){
			++ p1;
		}
		p2 = p1 + 1;
		while(p2 < i && !a[p2]){
			++ p2;
		}
	}
	cout << (int)res.size() << "\n";
	for(auto [i, j]: res){
		cout << i + 1 << " " << j + 1 << "\n";
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