#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
	}
	vector<int> res(n);
	for(auto l = 0; l < n; ++ l){
		vector<int> cnt(n);
		array<int, 2> cur{0, -1};
		for(auto i = l; i < n; ++ i){
			++ cnt[a[i]];
			if(cur[0] < cnt[a[i]] || cur[0] == cnt[a[i]] && cur[1] > a[i]){
				cur = {cnt[a[i]], a[i]};
			}
			++ res[cur[1]];
		}
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