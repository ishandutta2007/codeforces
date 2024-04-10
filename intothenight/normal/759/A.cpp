#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> p(n), b(n);
	for(auto i = 0; i < n; ++ i){
		cin >> p[i], -- p[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> b[i];
	}
	vector<int> vis(n);
	int res = 0;
	for(auto u = 0; u < n; ++ u){
		if(!vis[u]){
			++ res;
			int cnt = 0;
			for(auto v = u; v ^ u || !cnt; v = p[v]){
				vis[v] = true;
				++ cnt;
			}
		}
	}
	if(res == 1){
		-- res;
	}
	cout << res + (~accumulate(b.begin(), b.end(), 0) & 1) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////