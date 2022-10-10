#include "bits/stdc++.h"
using namespace std;



int SOLVE(){
	string s;
	cin >> s;
	int n = int(s.size());
	vector<int> pref(n + 1);
	for(auto i = 0; i < n; ++ i){
		pref[i + 1] = pref[i] + (s[i] == '+' ? 1 : -1);
	}
	long long res = 0;
	for(auto init = 0, r = 0; ; ++ init){
		while(r <= n && pref[r] + init >= 0){
			++ r;
		}
		res += r;
		if(r == n + 1){
			break;
		}
	}
	cout << res - 1 << "\n";
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
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