#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<array<int, 2>> pos;
	vector<int> len;
	for(auto i = 0; i < n; ){
		while(i < n && s[i] == '_'){
			++ i;
		}
		if(i < n){
			int j = i;
			while(j < n && s[j] == '#'){
				++ j;
			}
			pos.push_back({i, j});
			i = j;
		}
	}
	if(pos.empty()){
		cout << "0\n";
		return 0;
	}
	if(s == string(n, '#')){
		cout << "1\n" << n << "\n";
		return 0;
	}
	len.push_back(pos.front()[0]);
	len.push_back(n - pos.back()[1]);
	for(auto i = 1; i < (int)pos.size(); ++ i){
		len.push_back(pos[i][0] - pos[i - 1][1] - 1);
	}
	sort(len.begin(), len.end());
	len.erase(unique(len.begin(), len.end()), len.end());
	int mx = len.front();
	vector<int> ok(mx + 1, true);
	for(auto x: len){
		if(~x & 1){
			if(1 <= mx){
				ok[1] = false;
			}
		}
		if(x){
			ok[0] = false;
			if(x - 1 <= mx){
				ok[x - 1] = false;
			}
		}
		for(auto y = x + 1; y <= mx; ++ y){
			ok[y] = false;
		}
	}
	if(none_of(ok.begin(), ok.end(), [&](int x){ return x; })){
		cout << "-1\n";
		return 0;
	}
	int x = find_if(ok.begin(), ok.end(), [&](int x){ return x; }) - ok.begin();
	vector<int> res;
	auto process = [&](int len){
		if(len - x & 1){
			res.push_back(2);
			res.insert(res.end(), len - x - 3 >> 1, 1);
		}
		else{
			res.insert(res.end(), len - x >> 1, 1);
		}
	};
	process(pos.front()[0]);
	res.push_back(pos[0][1] - pos[0][0] + x);
	for(auto i = 1; i < (int)pos.size(); ++ i){
		process(pos[i][0] - pos[i - 1][1] - 1);
		res.push_back(pos[i][1] - pos[i][0] + x);
	}
	process(n - pos.back()[1]);
	cout << (int)res.size() << "\n";
	for(auto x: res){
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