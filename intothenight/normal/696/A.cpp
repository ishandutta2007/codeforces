#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int qn;
	cin >> qn;
	map<long long, array<long long, 2>> mp;
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 1){
			long long u, v;
			int w;
			cin >> u >> v >> w;
			while(u != v){
				if(u < v){
					swap(u, v);
				}
				mp[u >> 1][u & 1] += w;
				u >>= 1;
			}
		}
		else{
			long long u, v;
			cin >> u >> v;
			long long res = 0;
			while(u != v){
				if(u < v){
					swap(u, v);
				}
				res += mp[u >> 1][u & 1];
				u >>= 1;
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