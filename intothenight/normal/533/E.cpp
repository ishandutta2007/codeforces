#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	string s, t;
	cin >> n >> s >> t;
	int i = 0, j = n - 1;
	while(s[i] == t[i]){
		++ i;
	}
	while(s[j] == t[j]){
		-- j;
	}
	if(i == j){
		cout << "2\n";
	}
	else{
		vector<string> res;
		for(auto rep = 0; rep < 2; ++ rep){
			string ress = s, rest = t;
			ress.insert(ress.begin() + i, t[i]);
			rest.insert(rest.begin() + j + 1, s[j]);
			if(ress == rest){
				res.push_back(ress);
			}
			swap(s, t);
		}
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		cout << (int)res.size() << "\n";
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