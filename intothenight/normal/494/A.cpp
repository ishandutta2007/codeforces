#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<int> pos, res;
	int balance = 0;
	for(auto i = 0; i < n; ++ i){
		if(s[i] == '#'){
			s[i] = ')';
			pos.push_back(i);
			res.push_back(1);
		}
		if(s[i] == '('){
			++ balance;
		}
		else{
			-- balance;
		}
	}
	if(balance < 0){
		cout << "-1\n";
		return 0;
	}
	res.back() += balance;
	s.insert(pos.back(), balance, ')');
	balance = 0;
	for(auto c: s){
		if(c == '('){
			++ balance;
		}
		else{
			-- balance;
		}
		if(balance < 0){
			cout << "-1\n";
			return 0;
		}
	}
	for(auto x: res){
		cout << x << "\n";
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