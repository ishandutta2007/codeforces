#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	auto query = [&](char c, int i, int j){
		if(c == '^'){
			cout << "XOR ";
		}
		else if(c == '&'){
			cout << "AND ";
		}
		else{
			cout << "OR ";
		}
		cout << i + 1 << " " << j + 1 << endl;
		int resp;
		cin >> resp;
		if(!~resp){
			exit(0);
		}
		return resp;
	};
	auto answer = [&](vector<int> a){
		cout << "! ";
		for(auto x: a){
			cout << x << " ";
		}
		cout << endl;
	};
	vector<int> q(n - 1), pref(n);
	for(auto i = 0; i < n - 1; ++ i){
		q[i] = query('^', i, i + 1);
		pref[i + 1] = pref[i] ^ q[i];
	}
	vector<int> pos(n, -1);
	for(auto i = 0; i < n; ++ i){
		if(~pos[pref[i]]){
			vector<int> res(n);
			res[i] = query('&', pos[pref[i]], i);
			for(auto j = 0; j < n; ++ j){
				res[j] = res[i] ^ pref[i] ^ pref[j];
			}
			answer(res);
			return 0;
		}
		pos[pref[i]] = i;
	}
	vector<int> res(n);
	int i = find(pref.begin(), pref.end(), 1) - pref.begin();
	res[0] = query('&', 0, i) >> 1 << 1;
	int j = find(pref.begin(), pref.end(), 2) - pref.begin();
	res[0] |= query('&', 0, j) & 1;
	for(auto i = 1; i < n; ++ i){
		res[i] = res[0] ^ pref[i];
	}
	answer(res);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////