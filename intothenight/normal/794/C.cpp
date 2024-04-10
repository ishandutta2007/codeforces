#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	string s, t;
	cin >> s >> t;
	int n = (int)s.size();
	sort(s.begin(), s.end()), sort(t.rbegin(), t.rend());
	s.resize(n + 1 >> 1), t.resize(n >> 1);
	reverse(s.begin(), s.end()), reverse(t.begin(), t.end());
	string res(n, '?');
	for(auto i = 0; i < n; ++ i){
		if(~i & 1){
			if(t.empty() || t.back() > s.back()){
				res[i] = s.back();
				s.pop_back();
			}
			else{
				reverse(s.begin(), s.end()), reverse(t.begin(), t.end());
				for(auto j = n - 1; j >= i; -- j){
					if(~(n - 1 - j) & 1){
						res[j] = s.back();
						s.pop_back();
					}
					else{
						res[j] = t.back();
						t.pop_back();
					}
				}
				break;
			}
		}
		else{
			if(s.empty() || s.back() < t.back()){
				res[i] = t.back();
				t.pop_back();
			}
			else{
				reverse(s.begin(), s.end()), reverse(t.begin(), t.end());
				for(auto j = n - 1; j >= i; -- j){
					if(~(n - 1 - j) & 1){
						res[j] = t.back();
						t.pop_back();
					}
					else{
						res[j] = s.back();
						s.pop_back();
					}
				}
				break;
			}
		}
	}
	cout << res << "\n";
	return 0;
}

/*
s  >
t  <
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////