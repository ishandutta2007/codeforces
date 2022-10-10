#include "bits/stdc++.h"
using namespace std;



int SOLVE(){
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<int> mtr(n);
	int k1;
	cin >> k1;
	for(auto i = 0; i < k1; ++ i){
		int u;
		cin >> u, -- u;
		mtr[u] = true;
	}
	int k2;
	cin >> k2;
	vector<int> ytr(n);
	int init = -1;
	for(auto i = 0; i < k2; ++ i){
		int u;
		cin >> u, -- u;
		ytr[u] = true;
		init = u;
	}
	auto query = [&](char type, int u){
		cout << type << " " << u + 1 << endl;
		int resp;
		cin >> resp;
		if(!~resp) exit(0);
		return resp - 1;
	};
	auto answer = [&](int u){
		cout << "C " << u + 1 << endl;
	};
	int l = query('B', init);
	if(mtr[l]){
		answer(l);
	}
	else if(k2 == 1){
		answer(-2);
	}
	else{
		queue<array<int, 2>> q{{{l, l}}};
		int r;
		while(1){
			auto [u, p] = q.front(); q.pop();
			for(auto v: adj[u]){
				if(v != p){
					if(mtr[v]){
						r = v;
						goto done;
					}
					else{
						q.push({v, u});
					}
				}
			}
		}
		done:;
		int s = query('A', r);
		if(ytr[s]){
			answer(r);
		}
		else{
			answer(-2);
		}
	}
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
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