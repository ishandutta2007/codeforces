#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<string> res(n);
	for(auto i = 0; i < n; ++ i){
		res[i] = {'A' + i / 26, 'a' + i % 26};
	}
	for(auto i = 0; i <= n - k; ++ i){
		string s;
		cin >> s;
		if(s == "NO"){
			res[i + k - 1] = res[i];
		}
	}
	for(auto s: res){
		cout << s << " ";
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