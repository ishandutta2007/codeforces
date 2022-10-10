#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto query = [&](int i, int j){
		cout << "? " << i << " " << j << endl;
		int resp;
		cin >> resp;
		if(!~resp){
			exit(0);
		}
		return resp;
	};
	int n;
	cin >> n;
	vector<int> eq(n), off(n - 1);
	for(auto i = 0; i < n; ++ i){
		eq[i] = query(i, i);
	}
	for(auto i = 0; i < n - 1; ++ i){
		off[i] = query(i + 1, i);
	}
	vector<vector<int>> s;
	for(auto x = 0; x < n; ++ x){
		vector<int> p(n), b(n);
		p[0] = x;
		for(auto i = 0; i < n - 1; ++ i){
			b[i] = p[i] ^ eq[i];
			p[i + 1] = b[i] ^ off[i];
		}
		b[n - 1] = p[n - 1] ^ eq[n - 1];
		for(auto i = 0; i < n; ++ i){
			if(b[i] >= n || p[b[i]] != i){
				goto FAIL;
			}
		}
		s.push_back(p);
		FAIL:;
	}
	cout << "!\n" << (int)s.size() << "\n";
	for(auto x: s[0]){
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