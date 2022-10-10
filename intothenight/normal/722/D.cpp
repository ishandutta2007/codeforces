#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	set<int, greater<>> s;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		s.insert(x);
	}
	while(true){
		int mx = *s.begin();
		vector<int> a;
		while(mx){
			if(s.count(mx)){
				a.push_back(mx);
				s.erase(mx);
			}
			else{
				break;
			}
			mx >>= 1;
		}
		if(a.back() == 1){
			for(auto x: a){
				s.insert(x);
			}
			break;
		}
		for(auto x: a){
			s.insert(x >> 1);
		}
	}
	for(auto x: s){
		cout << x << " ";
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