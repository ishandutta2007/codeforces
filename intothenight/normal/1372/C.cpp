#include "bits/stdc++.h"
using namespace std;



int solve_testcase(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	if(is_sorted(a.begin(), a.end())){
		cout << "0\n";
		return 0;
	}
	int l = 0;
	while(l < n && a[l] == l + 1){
		++ l;
	}
	while(l < n && a[l] != l + 1){
		++ l;
	}
	while(l < n && a[l] == l + 1){
		++ l;
	}
	if(l == n){
		cout << "1\n";
	}
	else{
		cout << "2\n";
	}
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		solve_testcase();
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