#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int res = 0;
	vector<string> a{"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
	for(auto i = 0; i < n; ++ i){
		string s;
		cin >> s;
		if('0' <= s[0] && s[0] <= '9'){
			res += stoi(s) < 18;
		}
		else{
			auto it = find(a.begin(), a.end(), s);
			if(it != a.end()){
				++ res;
			}
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