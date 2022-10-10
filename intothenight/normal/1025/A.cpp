#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	string s;
	cin >> n >> s;
	vector<int> cnt(26);
	for(auto c: s){
		++ cnt[c - 'a'];
	}
	sort(cnt.rbegin(), cnt.rend());
	while(!cnt.back()){
		cnt.pop_back();
	}
	(int)cnt.size() == 1 || cnt.front() >= 2 ? cout << "Yes\n" : cout << "No\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////