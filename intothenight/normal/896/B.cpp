#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, c;
	cin >> n >> m >> c;
	vector<int> state(n, -1);
	for(auto i = 0; i < m; ++ i){
		int x;
		cin >> x;
		if(x <= c / 2){
			int p = 0;
			while(~state[p] && state[p] <= x){
				++ p;
			}
			cout << p + 1 << endl;
			state[p] = x;
		}
		else{
			int p = n - 1;
			while(~state[p] && state[p] >= x){
				-- p;
			}
			cout << p + 1 << endl;
			state[p] = x;
		}
		if(all_of(state.begin(), state.end(), [&](int x){ return ~x; })){
			return 0;
		}
	}
	assert(false);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////