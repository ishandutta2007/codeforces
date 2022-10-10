#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int qn;
	cin >> qn;
	vector<int> gold(qn + 1), cost(qn + 1, -1);
	cin >> gold[0] >> cost[0];
	const int lg = __lg(qn) + 1;
	vector lift(lg, vector<int>(qn + 1));
	for(auto u = 1; u <= qn; ++ u){
		int type;
		cin >> type;
		if(type == 1){
			int p;
			cin >> p;
			cin >> gold[u] >> cost[u];
			lift[0][u] = p;
			for(auto bit = 1; bit < lg; ++ bit){
				lift[bit][u] = lift[bit - 1][lift[bit - 1][u]];
			}
		}
		else{
			int u, w;
			cin >> u >> w;
			int wres = 0;
			long long costres = 0;
			while(w && gold[u]){
				int v = u;
				for(auto bit = lg - 1; bit >= 0; -- bit){
					if(gold[lift[bit][v]]){
						v = lift[bit][v];
					}
				}
				int x = min(gold[v], w);
				gold[v] -= x;
				w -= x;
				wres += x;
				costres += 1LL * x * cost[v];
			}
			cout << wres << " " << costres << endl;
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