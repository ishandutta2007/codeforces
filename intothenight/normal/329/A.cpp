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
	vector<string> a(n);
	vector<int> r(n), c(n);
	vector<int> ir(n), ic(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		for(auto j = 0; j < n; ++ j){
			if(a[i][j] == '.'){
				r[i] = c[j] = true;
				ir[i] = j;
				ic[j] = i;
			}
		}
	}
	if(accumulate(r.begin(), r.end(), 0) == n){
		for(auto i = 0; i < n; ++ i){
			cout << i + 1 << " " << ir[i] + 1 << "\n";
		}
	}
	else if(accumulate(c.begin(), c.end(), 0) == n){
		for(auto j = 0; j < n; ++ j){
			cout << ic[j] + 1 << " " << j + 1 << "\n";
		}
	}
	else{
		cout << "-1\n";
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