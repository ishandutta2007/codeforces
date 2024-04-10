#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		string s;
		cin >> n >> m >> s;
		if(s == string(n, '0')){
			cout << s << "\n";
			return 0;
		}
		vector<array<int, 2>> dist(n, {numeric_limits<int>::max(), 0});
		for(auto i = 0; i < n; ++ i){
			if(s[i] & 1){
				for(auto j = i - 1; j >= 0; -- j){
					if(s[j] & 1){
						break;
					}
					int d = i - j;
					if(dist[j][0] > d){
						dist[j] = {d, 1};
					}
					else if(dist[j][0] == d){
						++ dist[j][1];
					}
				}
				for(auto j = i + 1; j < n; ++ j){
					if(s[j] & 1){
						break;
					}
					int d = j - i;
					if(dist[j][0] > d){
						dist[j] = {d, 1};
					}
					else if(dist[j][0] == d){
						++ dist[j][1];
					}
				}
			}
		}
		for(auto i = 0; i < n; ++ i){
			if(~s[i] & 1){
				if(dist[i][0] <= m && dist[i][1] != 2){
					s[i] = '1';
				}
			}
		}
		cout << s << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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