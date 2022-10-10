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
	vector<int> a(n), b(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	copy_n(istream_iterator<int>(cin), n, b.begin());
	bool swapped = false;
	if(accumulate(a.begin(), a.end(), 0LL) > accumulate(b.begin(), b.end(), 0LL)){
		swap(a, b);
		swapped = true;
	}
	vector<array<int, 2>> appear(n, {-1, -1});
	appear[0] = {0, 0};
	int dif = 0;
	for(auto i = 0, j = 0; i < n; ++ i){
		dif += a[i];
		while(j < n && dif >= b[j]){
			dif -= b[j];
			++ j;
		}
		if(~appear[dif][0]){
			auto [al, bl] = appear[dif];
			auto [ar, br] = pair{i + 1, j};
			if(swapped){
				swap(al, bl);
				swap(ar, br);
			}
			cout << ar - al << "\n";
			for(auto i = al; i < ar; ++ i){
				cout << i + 1 << " ";
			}
			cout << "\n";
			cout << br - bl << "\n";
			for(auto i = bl; i < br; ++ i){
				cout << i + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
		appear[dif] = {i + 1, j};
	}
	assert(false);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////