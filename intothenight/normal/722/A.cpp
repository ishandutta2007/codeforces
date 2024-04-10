#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int type;
	cin >> type;
	string s;
	cin >> s;
	pair<int, string> res{numeric_limits<int>::max(), {}};
	auto conv = [&](int x)->string{
		if(x == 0){
			return "00";
		}
		else if(x < 10){
			return "0" + to_string(x);
		}
		else{
			return to_string(x);
		}
	};
	if(type == 12){
		for(auto h = 1; h <= 12; ++ h){
			for(auto m = 0; m < 60; ++ m){
				string t = conv(h) + ":" + conv(m);
				int cnt = 0;
				for(auto i = 0; i < 5; ++ i){
					cnt += s[i] != t[i];
				}
				ctmin(res, pair{cnt, t});
			}
		}
	}
	else{
		for(auto h = 0; h < 24; ++ h){
			for(auto m = 0; m < 60; ++ m){
				string t = conv(h) + ":" + conv(m);
				int cnt = 0;
				for(auto i = 0; i < 5; ++ i){
					cnt += s[i] != t[i];
				}
				ctmin(res, pair{cnt, t});
			}
		}
	}
	cout << res.second << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////