#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto query = [&](int i, int j){
		cout << "? " << i + 1 << " " << j + 1 << endl;
		int resp;
		cin >> resp;
		if(!~resp) exit(0);
		return resp;
	};
	int n;
	cin >> n;
	vector<int> res(n, n);
	int p = 0;
	for(auto i = 1; i < n; ++ i){
		int x = query(p, i), y = query(i, p);
		if(x > y){
			res[p] = x;
			p = i;
		}
		else{
			res[i] = y;
		}
	}
	cout << "! ";
	for(auto x: res){
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