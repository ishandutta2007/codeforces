#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<string> a(n);
	map<string, int> cnt;
	for(auto &s: a){
		cin >> s;
		vector<string> cur;
		for(auto j = 0; j < (int)s.size(); ++ j){
			for(auto k = j + 1; k <= (int)s.size(); ++ k){
				cur.push_back(s.substr(j, k - j));
			}
		}
		sort(cur.begin(), cur.end());
		cur.erase(unique(cur.begin(), cur.end()), cur.end());
		for(auto s: cur){
			++ cnt[s];
		}
	}
	for(auto s: a){
		for(auto len = 1; len <= (int)s.size(); ++ len){
			for(auto i = 0; i + len <= (int)s.size(); ++ i){
				if(cnt[s.substr(i, len)] == 1){
					cout << s.substr(i, len) << "\n";
					goto DONE;
				}
			}
		}
		DONE:;
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