#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	if(n == 1){
		if(k){
			cout << "-1\n";
		}
		else{
			cout << "1\n";
		}
		return 0;
	}
	if(k < n / 2){
		cout << "-1\n";
		return 0;
	}
	vector<int> used(2 * n + 10);
	k -= n / 2 - 1;
	if(k < (int)used.size()){
		used[k] = true;
	}
	if(2 * k < (int)used.size()){
		used[2 * k] = true;
	}
	vector<int> a(n);
	a[0] = k, a[1] = 2 * k;
	for(auto i = 2, x = 1; i + 1 < n; i += 2){
		while(used[x] || used[x + 1]){
			++ x;
		}
		a[i] = x, a[i + 1] = x + 1;
		used[x] = used[x + 1] = true;
		x += 2;
	}
	if(n & 1){
		int x = 1;
		while(used[x]){
			++ x;
		}
		a.back() = x;
	}
	for(auto x: a){
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