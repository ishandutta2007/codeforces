#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	for(auto i = 0; i < n; ++ i){
		int m;
		cin >> m;
		for(auto j = 0; j < m; ++ j){
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	int m;
	cin >> m;
	vector<array<int, 10>> ban(m);
	for(auto i = 0; i < m; ++ i){
		for(auto j = 0; j < n; ++ j){
			cin >> ban[i][j], -- ban[i][j];
		}
	}
	sort(ban.begin(), ban.end());
	priority_queue<pair<long long, array<int, 10>>> pq;
	set<array<int, 10>> in_pq;
	{
		long long sum = 0;
		array<int, 10> build{};
		for(auto i = 0; i < n; ++ i){
			build[i] = (int)a[i].size() - 1;
			sum += a[i].back();
		}
		pq.push({sum, build});
		in_pq.insert(build);
	}
	while(true){
		auto [sum, build] = pq.top();
		pq.pop();
		if(!binary_search(ban.begin(), ban.end(), build)){
			for(auto i = 0; i < n; ++ i){
				cout << build[i] + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
		for(auto i = 0; i < n; ++ i){
			if(build[i]){
				sum -= a[i][build[i]];
				sum += a[i][-- build[i]];
				if(!in_pq.count(build)){
					pq.push({sum, build});
					in_pq.insert(build);
				}
				sum -= a[i][build[i]];
				sum += a[i][++ build[i]];
			}
		}
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