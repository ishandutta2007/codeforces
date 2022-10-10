#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<vector<array<int, 3>>> update(n);
	const int mx = 1e6;
	for(auto qi = 0; qi < qn; ++ qi){
		int type, lvl;
		cin >> type >> lvl, -- lvl;
		if(type == 1){
			int l, r, x;
			cin >> l >> r >> x, -- l, -- x;
			update[lvl].push_back({l, r, x});
		}
		else{
			int p;
			cin >> p, -- p;
			int ql = p, qr = p + 1, res = 0;
			static vector<int> was(mx, -1);
			for(auto i = lvl; i < n; ++ i){
				for(auto [l, r, x]: update[i]){
					if(max(ql, l) < min(qr, r) && was[x] != qi){
						was[x] = qi;
						++ res;
					}
				}
				if(ql){
					ql += __lg(ql) + 1;
				}
				if(qr){
					qr += __lg(qr) + 1;
				}
			}
			cout << res << "\n";
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