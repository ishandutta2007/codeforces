#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<array<long long, 2>> pos(n);
	for(auto i = 0; i < n; ++ i){
		cin >> pos[i][0] >> pos[i][1];
	}
	vector<tuple<long long, int, bool>> seg;
	for(auto i = 0; i < n - 1; ++ i){
		seg.push_back({pos[i + 1][0] - pos[i][1], i, true});
		seg.push_back({pos[i + 1][1] - pos[i][0] + 1, i, false});
	}
	sort(seg.rbegin(), seg.rend());
	vector<pair<long long, int>> b(m);
	for(auto i = 0; i < m; ++ i){
		cin >> b[i].first, b[i].second = i;
	}
	sort(b.begin(), b.end());
	set<pair<long long, int>> cur;
	vector<int> res(n - 1, -1);
	for(auto [len, id]: b){
		while(!seg.empty() && get<0>(seg.back()) <= len){
			auto [x, i, type] = seg.back(); seg.pop_back();
			if(type){
				cur.insert({pos[i + 1][1] - pos[i][0] + 1, i});
			}
			else if(cur.count({pos[i + 1][1] - pos[i][0] + 1, i})){
				cout << "No\n";
				return 0;
			}
		}
		if(cur.empty()){
			continue;
		}
		auto [ignore, i] = *cur.begin(); cur.erase(cur.begin());
		res[i] = id;
	}
	if(any_of(res.begin(), res.end(), [&](int x){ return !~x; })){
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	for(auto id: res){
		cout << id + 1 << " ";
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