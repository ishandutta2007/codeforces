#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	multiset<int> ms;
	int res = 0;
	long long h = 0;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		if(h + x >= 0){
			ms.insert(x);
			h += x;
			++ res;
		}
		else if(!ms.empty() && *ms.begin() < x){
			h -= *ms.begin(); ms.erase(ms.begin());
			h += x; ms.insert(x);
		}
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