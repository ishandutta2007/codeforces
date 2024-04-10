#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> p(n), a(n), b(n);
	for(auto i = 0; i < n; ++ i){
		cin >> p[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> b[i], -- b[i];
	}
	array<array<vector<int>, 3>, 3> t;
	for(auto i = 0; i < n; ++ i){
		t[a[i]][b[i]].push_back(p[i]);
	}
	for(auto i = 0; i < 3; ++ i){
		for(auto j = 0; j < 3; ++ j){
			sort(t[i][j].rbegin(), t[i][j].rend());
		}
	}
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int c;
		cin >> c, -- c;
		int res = numeric_limits<int>::max(), ri = -1, rj = -1;
		for(auto i = 0; i < 3; ++ i){
			for(auto j = 0; j < 3; ++ j){
				if(i == c || j == c){
					if(!t[i][j].empty() && res > t[i][j].back()){
						res = t[i][j].back();
						ri = i;
						rj = j;
					}
				}
			}
		}
		res == numeric_limits<int>::max() ? cout << "-1 " : cout << res << " ";
		if(~ri){
			t[ri][rj].pop_back();
		}
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