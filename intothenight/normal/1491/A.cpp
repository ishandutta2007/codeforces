#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<int> a(n);
	array<int, 2> cnt{};
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		++ cnt[a[i]];
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int t, i;
		cin >> t >> i;
		if(t == 1){
			-- i;
			-- cnt[a[i]];
			++ cnt[a[i] = 1 - a[i]];
		}
		else{
			if(cnt[1] >= i){
				cout << "1\n";
			}
			else{
				cout << "0\n";
			}
		}
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