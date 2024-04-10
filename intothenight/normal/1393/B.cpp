#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> cnt(1e5);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x, -- x;
		++ cnt[x];
	}
	multiset<int, greater<>> ms(cnt.begin(), cnt.end());
	int qq;
	cin >> qq;
	while(qq --){
		char type;
		int x;
		cin >> type >> x, -- x;
		ms.erase(ms.find(cnt[x]));
		if(type == '+'){
			ms.insert(++ cnt[x]);
		}
		else{
			ms.insert(-- cnt[x]);
		}
		if(!ms.empty() && *ms.begin() >= 8 || int(ms.size()) >= 2 && (*ms.begin() >= 6 && *next(ms.begin()) >= 2 || *ms.begin() >= 4 && *next(ms.begin()) >= 4) || int(ms.size()) >= 3 && *ms.begin() >= 4 && *next(ms.begin()) >= 2 && *next(next(ms.begin())) >= 2){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
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