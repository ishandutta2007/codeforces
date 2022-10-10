#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	int l = 0, r = 0;
	for(auto x = n - 1; x; x /= 7){
		++ l;
	}
	for(auto x = m - 1; x; x /= 7){
		++ r;
	}
	l = max(l, 1), r = max(r, 1);
	if(l + r > 7){
		cout << "0\n";
		return 0;
	}
	vector<int> c(7);
	for(auto i = 7 - (l + r); i < 7; ++ i){
		c[i] = 1;
	}
	int res = 0;
	do{
		vector<int> p;
		for(auto x = 0; x < 7; ++ x){
			if(c[x]){
				p.push_back(x);
			}
		}
		do{
			int left = 0, right = 0;
			for(auto i = 0; i < l; ++ i){
				left = left * 7 + p[i];
			}
			for(auto i = l; i < l + r; ++ i){
				right = right * 7 + p[i];
			}
			if(left < n && right < m){
				++ res;
			}
		}while(next_permutation(p.begin(), p.end()));
	}while(next_permutation(c.begin(), c.end()));
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////