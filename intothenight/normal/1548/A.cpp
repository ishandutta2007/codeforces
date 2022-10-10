#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<int> badness(n);
	int good = n;
	auto insert = [&](int u, int v)->void{
		tie(u, v) = pair{min(u, v), max(u, v)};
		if(!badness[u]){
			-- good;
		}
		++ badness[u];
	};
	auto erase = [&](int u, int v)->void{
		tie(u, v) = pair{min(u, v), max(u, v)};
		-- badness[u];
		if(!badness[u]){
			++ good;
		}
	};
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		insert(u, v);
	}
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 3){
			cout << good << "\n";
		}
		else{
			int u, v;
			cin >> u >> v, -- u, -- v;
			if(type == 1){
				insert(u, v);
			}
			else{
				erase(u, v);
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