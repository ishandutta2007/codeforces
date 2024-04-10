#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	string s;
	cin >> n >> qn >> s;
	vector<array<int, 2>> cnt(n);
	for(auto i = 1; i < n; ++ i){
		cnt[i] = cnt[i - 1];
		if(s[i - 1] == s[i]){
			++ cnt[i][s[i] - '0'];
		}
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r;
		cin >> l >> r, -- l, -- r;
		cout << max(cnt[r][0] - cnt[l][0], cnt[r][1] - cnt[l][1]) + 1 << "\n";
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