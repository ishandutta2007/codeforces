#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	array<vector<int>, 3> pos;
	for(auto i = 0; i < n; ++ i){
		char type;
		cin >> a[i][0] >> type;
		if(type == 'B'){
			a[i][1] = 1;
		}
		else if(type == 'G'){
			a[i][1] = 2;
		}
		pos[a[i][1]].push_back(i);
	}
	if(pos[2].empty()){
		cout << (pos[0].empty() ? 0 : a[pos[0].back()][0] - a[pos[0].front()][0]) + (pos[1].empty() ? 0 : a[pos[1].back()][0] - a[pos[1].front()][0]) << "\n";
		return 0;
	}
	long long res = 0;
	for(auto t = 0; t < 2; ++ t){
		if(!pos[t].empty()){
			if(pos[t].front() < pos[2].front()){
				res += a[pos[2].front()][0] - a[pos[t].front()][0];
			}
			if(pos[2].back() < pos[t].back()){
				res += a[pos[t].back()][0] - a[pos[2].back()][0];
			}
		}
	}
	for(auto X = 1; X < (int)pos[2].size(); ++ X){
		int l = pos[2][X - 1], r = pos[2][X];
		array<vector<int>, 2> cpos;
		for(auto i = l; i <= r; ++ i){
			if(a[i][1] != 1){
				cpos[0].push_back(i);
			}
			if(a[i][1] != 0){
				cpos[1].push_back(i);
			}
		}
		array<int, 2> mx{};
		for(auto t = 0; t < 2; ++ t){
			for(auto i = 1; i < (int)cpos[t].size(); ++ i){
				ctmax(mx[t], a[cpos[t][i]][0] - a[cpos[t][i - 1]][0]);
			}
		}
		res += min(2LL * (a[r][0] - a[l][0]), 3LL * (a[r][0] - a[l][0]) - mx[0] - mx[1]);
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////