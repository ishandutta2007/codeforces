#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string s;
	cin >> s;
	vector<int> first(26, -1);
	for(auto i = (int)s.size() - 1; i >= 0; -- i){
		first[s[i] - 'a'] = i;
	}
	int p = find(first.begin(), first.end(), -1) - first.begin();
	is_sorted(first.begin(), first.begin() + p) && all_of(first.begin() + p, first.end(), [&](int x){ return !~x; }) ? cout << "YES\n" : cout << "NO\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////