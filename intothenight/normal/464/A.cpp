#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, p;
	string s;
	cin >> n >> p >> s;
	{
		bool last = true;
		for(auto i = 0; i < n; ++ i){
			if(s[i] != 'a' + p - 1 - i % 3){
				last = false;
				break;
			}
		}
		if(last){
			cout << "NO\n";
			return 0;
		}
	}
	for(auto i = n - 1; i >= 0; -- i){
		++ s[i];
		while(i >= 1 && s[i] == s[i - 1] || i >= 2 && s[i] == s[i - 2]){
			++ s[i];
		}
		if(s[i] < 'a' + p){
			for(auto j = i + 1; j < n; ++ j){
				s[j] = 'a';
				while(j >= 1 && s[j] == s[j - 1] || j >= 2 && s[j] == s[j - 2]){
					++ s[j];
				}
			}
			break;
		}
	}
	cout << s << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////