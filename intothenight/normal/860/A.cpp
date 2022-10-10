#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string s;
	cin >> s;
	int n = (int)s.size();
	vector<int> cons(300, true);
	cons['a'] = cons['e'] = cons['i'] = cons['o'] = cons['u'] = false;
	vector<int> range{0};
	for(auto i = 0; i + 3 <= n; ++ i){
		if(cons[s[i]] && cons[s[i + 1]] && cons[s[i + 2]] && (s[i] != s[i + 1] || s[i + 1] != s[i + 2] || s[i + 2] != s[i])){
			range.push_back(i + 2);
			++ i;
		}
	}
	range.push_back(n);
	for(auto i = 1; i < (int)range.size(); ++ i){
		cout << s.substr(range[i - 1], range[i] - range[i - 1]) << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////