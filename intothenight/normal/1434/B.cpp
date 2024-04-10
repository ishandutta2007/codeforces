#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<pair<char, int>> log(2 * n);
	for(auto &[c, x]: log){
		cin >> c;
		if(c == '-'){
			cin >> x;
		}
	}
	vector<int> s, val(n, -1);
	int it = 0;
	for(auto i = 0; i < 2 * n; ++ i){
		if(log[i].first == '+'){
			s.push_back(it ++);
		}
		else if(s.empty()){
			cout << "NO\n";
			return 0;
		}
		else{
			val[s.back()] = log[i].second;
			s.pop_back();
		}
	}
	set<int> t;
	it = 0;
	for(auto i = 0; i < 2 * n; ++ i){
		if(log[i].first == '+'){
			t.insert(val[it ++]);
		}
		else{
			if(*t.begin() != log[i].second){
				cout << "NO\n";
				return 0;
			}
			t.erase(t.begin());
		}
	}
	cout << "YES\n";
	for(auto x: val){
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////