#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int k;
	cin >> k;
	string res;
	for(auto c = 'a'; k; ++ c){
		int i = 1;
		while((i + 1) * i / 2 <= k){
			++ i;
		}
		k -= i * (i - 1) / 2;
		res += string(i, c);
	}
	if(res.empty()){
		res += 'a';
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