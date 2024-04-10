#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string s;
	cin >> s;
	vector<char> q;
	for(auto c: s){
		if(q.empty() || q.back() != c){
			q.push_back(c);
		}
		else{
			q.pop_back();
		}
	}
	q.empty() ? cout << "Yes\n" : cout << "No\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////