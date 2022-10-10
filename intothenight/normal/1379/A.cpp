#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](){
		int n;
		string s, p("abacaba");
		cin >> n >> s;
		auto it = search(s.begin(), s.end(), p.begin(), p.end());
		if(it == s.end()){
			for(auto i = 0; i + 7 <= n; ++ i){
				bool ok = true;
				for(auto j = 0; j < 7; ++ j){
					if(s[i + j] != '?' && p[j] != s[i + j]){
						ok = false;
						break;
					}
				}
				if(ok){
					string t = s;
					for(auto j = 0; j < 7; ++ j){
						t[i + j] = p[j];
					}
					if(search(t.begin(), t.end(), p.begin(), p.end()) == t.begin() + i && search(t.begin() + i + 1, t.end(), p.begin(), p.end()) == t.end()){
						cout << "Yes\n";
						for(auto c: t){
							c == '?' ? cout << 'z' : cout << c;
						}
						cout << "\n";
						return 0;
					}
				}
			}
			cout << "No\n";
		}
		else{
			it = search(it + 1, s.end(), p.begin(), p.end());
			if(it == s.end()){
				cout << "Yes\n";
				for(auto c: s){
					c == '?' ? cout << 'z' : cout << c;
				}
				cout << "\n";
			}
			else{
				cout << "No\n";
			}
		}
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_it = 0; __tc_it < __tc_cnt; ++ __tc_it){
		__solve_tc();
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