#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, s;
	cin >> n >> s;
	vector<int> deg(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		++ deg[u], ++ deg[v];
	}
	if(n == 2){
		cout << s << "\n";
	}
	else{
		cout << fixed << setprecision(15);
		cout << 1.0 * s / count(deg.begin(), deg.end(), 1) * 2 << "\n";
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