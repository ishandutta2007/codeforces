#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<array<int, 4>> res;
	int pivot = -1;
	for(auto rep = 0; rep < 2; ++ rep){
		vector<array<int, 3>> a(m);
		for(auto i = 0; i < m; ++ i){
			for(auto j = 0; j < 2; ++ j){
				cin >> a[i][j];
			}
			a[i][2] = i + 1;
		}
		sort(a.begin(), a.end());
		auto move = [&](int i, int x, int y){
			while(a[i][0] < x){
				res.push_back({a[i][0], a[i][1], a[i][0] + 1, a[i][1]});
				++ a[i][0];
			}
			while(x < a[i][0]){
				res.push_back({a[i][0], a[i][1], a[i][0] - 1, a[i][1]});
				-- a[i][0];
			}
			while(a[i][1] < y){
				res.push_back({a[i][0], a[i][1], a[i][0], a[i][1] + 1});
				++ a[i][1];
			}
			while(y < a[i][1]){
				res.push_back({a[i][0], a[i][1], a[i][0], a[i][1] - 1});
				-- a[i][1];
			}
		};
		while(true){
			bool changed = false;
			for(auto i = 0; i < m; ++ i){
				if(a[i][0] != i + 1){
					for(auto j = 0; j < m; ++ j){
						if(a[i][1] == a[j][1] && (a[i][0] < a[j][0] && a[j][0] <= i + 1 || i + 1 <= a[j][0] && a[j][0] < a[i][0])){
							goto FAIL;
						}
					}
					changed = true;
					move(i, i + 1, a[i][1]);
					FAIL:;
				}
			}
			if(!changed){
				break;
			}
		}
		for(auto i = 0; i < m; ++ i){
			move(i, i + 1, a[i][2]);
		}
		for(auto i = 0; i < m; ++ i){
			move(i, a[i][2], a[i][2]);
		}
		if(!rep){
			pivot = (int)res.size();
		}
	}
	reverse(res.begin() + pivot, res.end());
	for(auto i = pivot; i < (int)res.size(); ++ i){
		swap(res[i][0], res[i][2]), swap(res[i][1], res[i][3]);
	}
	cout << (int)res.size() << "\n";
	for(auto m: res){
		for(auto x: m){
			cout << x << " ";
		}
		cout << "\n";
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