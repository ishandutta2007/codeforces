#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(n), c(m);
		vector<vector<int>> painters(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i], -- a[i];
		}
		for(auto i = 0; i < n; ++ i){
			cin >> b[i], -- b[i];
		}
		for(auto i = 0; i < m; ++ i){
			cin >> c[i], -- c[i];
			painters[c[i]].push_back(i);
		}
		vector<int> badpos, fix(n);
		for(auto i = 0; i < n; ++ i){
			if(a[i] != b[i]){
				badpos.push_back(i);
				++ fix[b[i]];
			}
		}
		for(auto c = 0; c < n; ++ c){
			if(fix[c] > (int)painters[c].size()){
				cout << "NO\n";
				return 0;
			}
		}
		if(!count(b.begin(), b.end(), c.back())){
			cout << "NO\n";
			return 0;
		}
		int lpos = find(b.begin(), b.end(), c.back()) - b.begin();
		vector<int> res(m, -1);
		for(auto i = 0; i < n; ++ i){
			if(a[i] != b[i]){
				int ind = painters[b[i]].back();
				res[ind] = i;
				painters[b[i]].pop_back();
			}
		}
		if(!~res.back()){
			res.back() = lpos;
			painters[c.back()].pop_back();
		}
		else{
			lpos = res.back();
		}
		for(auto v: painters){
			for(auto ind: v){
				res[ind] = lpos;
			}
		}
		cout << "YES\n";
		for(auto i: res){
			assert(~i);
			cout << i + 1 << " ";
		}
		cout << "\n";
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