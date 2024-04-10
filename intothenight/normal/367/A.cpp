#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<array<int, 3>> cnt(n + 1);
	for(auto i = 0; i < n; ++ i){
		cnt[i + 1] = cnt[i];
		++ cnt[i + 1][s[i] - 'x'];
	}
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r;
		cin >> l >> r, -- l;
		if(r - l <= 2 || max({cnt[r][0] - cnt[l][0], cnt[r][1] - cnt[l][1], cnt[r][2] - cnt[l][2]}) - min({cnt[r][0] - cnt[l][0], cnt[r][1] - cnt[l][1], cnt[r][2] - cnt[l][2]}) <= 1){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
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