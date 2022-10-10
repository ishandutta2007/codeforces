#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	auto isnum = [&](string s){
		return all_of(s.begin(), s.end(), [&](int c){ return isdigit(c); }) && s[0] != '0';
	};
	auto convert = [&](string s){
		int res = 0;
		for(auto c: s){
			res = res * 10 + c - '0';
		}
		return res;
	};
	vector<pair<string, int>> a(n);
	int e = 0;
	set<string> present;
	for(auto &[s, type]: a){
		cin >> s >> type, e += type;
		present.insert(s);
	}
	set<string> pool_left, pool_right;
	for(auto x = 1; x <= e; ++ x){
		pool_left.insert(to_string(x));
	}
	for(auto x = e + 1; x <= n; ++ x){
		pool_right.insert(to_string(x));
	}
	set<string> opp_left, opp_right;
	set<string> rem_left, rem_right;
	for(auto [s, type]: a){
		if(type){
			if(isnum(s) && convert(s) <= n){
				if(e < convert(s)){
					opp_left.insert(s);
					pool_right.erase(s);
				}
				else{
					pool_left.erase(s);
				}
			}
			else{
				rem_left.insert(s);
			}
		}
		else{
			if(isnum(s) && convert(s) <= n){
				if(convert(s) <= e){
					opp_right.insert(s);
					pool_left.erase(s);
				}
				else{
					pool_right.erase(s);
				}
			}
			else{
				rem_right.insert(s);
			}
		}
	}
	vector<array<string, 2>> res;
	if(!opp_left.empty() && pool_left.empty() && !opp_right.empty() && pool_right.empty()){
		int x = 1;
		while(present.count(to_string(x))){
			++ x;
		}
		auto s = *opp_left.begin();
		opp_left.erase(s);
		pool_right.insert(s);
		rem_left.insert(to_string(x));
		res.push_back({s, to_string(x)});
	}
	while(!opp_left.empty() || !opp_right.empty()){
		if(!opp_left.empty() && !pool_left.empty()){
			auto s = *opp_left.begin();
			opp_left.erase(s);
			auto t = *pool_left.begin();
			pool_left.erase(t);
			res.push_back({s, t});
			pool_right.insert(s);
		}
		else if(!opp_right.empty() && !pool_right.empty()){
			auto s = *opp_right.begin();
			opp_right.erase(s);
			auto t = *pool_right.begin();
			pool_right.erase(t);
			res.push_back({s, t});
			pool_left.insert(s);
		}
		else{
			assert(false);
		}
	}
	while(!rem_left.empty() || !rem_right.empty()){
		if(!rem_left.empty() && !pool_left.empty()){
			auto s = *rem_left.begin();
			rem_left.erase(s);
			auto t = *pool_left.begin();
			pool_left.erase(t);
			res.push_back({s, t});
		}
		else if(!rem_right.empty() && !pool_right.empty()){
			auto s = *rem_right.begin();
			rem_right.erase(s);
			auto t = *pool_right.begin();
			pool_right.erase(t);
			res.push_back({s, t});
		}
		else{
			assert(false);
		}
	}
	assert(opp_left.empty() && opp_right.empty());
	assert(rem_left.empty() && rem_right.empty());
	assert(pool_left.empty() && pool_right.empty());
	cout << (int)res.size() << "\n";
	for(auto [s, t]: res){
		cout << "move " << s << " " << t << "\n";
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