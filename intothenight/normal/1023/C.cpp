#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	string s;
	cin >> n >> k >> s;
	k = n - k >> 1;
	vector<int> p(n), st;
	for(auto i = 0; i < n; ++ i){
		if(s[i] == '('){
			st.push_back(i);
		}
		else{
			p[st.back()] = i, p[i] = st.back();
			st.pop_back();
		}
	}
	vector<int> ded(n);
	for(auto i = 0; k && i < n; ++ i){
		if(s[i] == '('){
			ded[i] = ded[p[i]] = true;
			-- k;
		}
	}
	for(auto i = 0; i < n; ++ i){
		if(!ded[i]){
			cout << s[i];
		}
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