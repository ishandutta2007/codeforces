#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	if(auto p = find(s.begin(), s.end(), '*'); p != s.end()){
		(int)t.size() >= (int)s.size() - 1 && s.substr(0, p - s.begin()) == t.substr(0, p - s.begin()) && s.substr(p - s.begin() + 1) == t.substr(m - (n - (p - s.begin() + 1))) ? cout << "YES\n" : cout << "NO\n";
	}
	else{
		s == t ? cout << "YES\n" : cout << "NO\n";
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