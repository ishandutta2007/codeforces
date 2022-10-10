#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<string> a(n);
		for(auto &s: a){
			cin >> s;
		}
		array<int, 3> p{0, 1, 2}; // O, X, fix
		pair<int, array<int, 3>> res{numeric_limits<int>::max(), {}};
		do{
			int cnt = 0;
			for(auto i = 0; i < n; ++ i){
				for(auto j = 0; j < n; ++ j){
					if((i + j) % 3 == p[0]){
						cnt += a[i][j] == 'X';
					}
					else if((i + j) % 3 == p[1]){
						cnt += a[i][j] == 'O';
					}
				}
			}
			ctmin(res, pair{cnt, p});
		}while(next_permutation(p.begin(), p.end()));
		p = res.second;
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < n; ++ j){
				if((i + j) % 3 == p[0]){
					if(a[i][j] == 'X'){
						a[i][j] = 'O';
					}
				}
				else if((i + j) % 3 == p[1]){
					if(a[i][j] == 'O'){
						a[i][j] = 'X';
					}
				}
			}
		}
		for(auto s: a){
			cout << s << "\n";
		}
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