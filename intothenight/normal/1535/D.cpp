
#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int k;
	string s;
	cin >> k >> s;
	reverse(s.begin(), s.end());
	s = 'x' + s;
	int n = 1 << k;
	vector<int> res(n);
	auto fix = [&](int i)->void{
		if((i << 1 | 1) >= n){
			res[i] = 1 + (s[i] == '?');
		}
		else{
			if(s[i] == '?'){
				res[i] = res[i << 1] + res[i << 1 | 1];
			}
			else{
				res[i] = res[i << 1 | 1 ^ s[i] & 1];
			}
		}
	};
	for(auto i = n - 1; i >= 1; -- i){
		fix(i);
	}
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int i;
		char c;
		cin >> i >> c, i = n - i;
		s[i] = c;
		while(i){
			fix(i);
			i >>= 1;
		}
		cout << res[1] << "\n";
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