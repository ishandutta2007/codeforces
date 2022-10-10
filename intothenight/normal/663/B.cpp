#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		string s;
		cin >> s;
		s = s.substr(4);
		vector<int> a;
		for(auto len = 1; len <= (int)s.size(); ++ len){
			if(auto x = stoi(s.substr((int)s.size() - len)); x >= 1989 && s[(int)s.size() - len] != '0' && find(a.begin(), a.end(), x) == a.end()){
				a.push_back(x);
			}
			else{
				for(auto d = 1; ; ++ d){
					if(auto x = stoi(to_string(d) + s.substr((int)s.size() - len)); x >= 1989 && find(a.begin(), a.end(), x) == a.end()){
						a.push_back(x);
						break;
					}
				}
			}
		}
		cout << a.back() << "\n";
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