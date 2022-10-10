#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	string t;
	cin >> t;
	int n = int(t.size());
	auto query = [&](const string &s){
		cout << "? " << s << endl;
		string resp;
		cin >> resp;
		if(resp == "0") exit(0);
		return resp;
	};
	auto answer = [&](const string &s){
		cout << "! " << s << endl;
		exit(0);
	};
	vector<int> p({1});
	for(auto k = 0; k < 4; ++ k){
		p.push_back(p.back() * 26);
	}
	vector<pair<vector<int>, vector<int>>> maps_to(1);
	for(auto i = 0; i < n; ++ i){
		maps_to[0].first.push_back(i), maps_to[0].second.push_back(i);
	}
	for(auto k = 0; k < 3; ++ k){
		vector<pair<vector<int>, vector<int>>> temp(26), maps_to_next;
		string s(n, 'a');
		for(auto i = 0; i < n; ++ i){
			s[i] = i % p[k + 1] / p[k] + 'a';
			temp[i % p[k + 1] / p[k]].first.push_back(i);
		}
		string res = query(s);
		for(auto i = 0; i < n; ++ i){
			temp[res[i] - 'a'].second.push_back(i);
		}
		for(auto c = 0; c < 26; ++ c){
			for(auto &[p, q]: maps_to){
				vector<int> cur_from, cur_to;
				set_intersection(p.begin(), p.end(), temp[c].first.begin(), temp[c].first.end(), back_inserter(cur_from));
				set_intersection(q.begin(), q.end(), temp[c].second.begin(), temp[c].second.end(), back_inserter(cur_to));
				if(!cur_from.empty()){
					maps_to_next.emplace_back(move(cur_from), move(cur_to));
				}
			}
		}
		swap(maps_to, maps_to_next);
	}
	string res(n, 'a');
	for(auto &[p, q]: maps_to){
		res[p[0]] = t[q[0]];
	}
	answer(res);
	return 0;
}

/*
(abc...z)(abc...z)...
(aaa...a)(bbb...b)...
(aaa...a)(aaa...a)...
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////