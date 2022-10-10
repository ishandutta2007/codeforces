#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string s;
	cin >> s;
	if(s.front() != s.back()){
		for(auto i = 1; i < (int)s.size(); ++ i){
			if(s[i - 1] == s[i]){
				rotate(s.begin(), s.begin() + i, s.end());
				break;
			}
		}
	}
	int res = numeric_limits<int>::min();
	for(auto i = 0; i < (int)s.size(); ){
		int j = i + 1;
		while(j < (int)s.size() && s[j - 1] != s[j]){
			++ j;
		}
		ctmax(res, j - i);
		i = j;
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