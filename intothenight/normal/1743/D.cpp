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
	string s;
	cin >> n >> s;
	if(s == string(n, '0')){
		cout << "0\n";
		return 0;
	}
	s.erase(s.begin(), ranges::find(s, '1'));
	n = (int)s.size();
	int zero = ranges::find(s, '0') - s.begin();
	string res = s, req(n - zero, '0');
	vector<int> c(zero), cnext;
	iota(c.begin(), c.end(), 0);
	for(auto i = zero; i < n; ++ i){
		if(s[i] == '1'){
			continue;
		}
		cnext.clear();
		for(auto j: c){
			if(s[j + i - zero] == '1'){
				cnext.push_back(j);
			}
		}
		if(!cnext.empty()){
			req[i - zero] = '1';
			res[i] = '1';
			swap(c, cnext);
		}
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////