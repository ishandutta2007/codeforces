#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int i = n >> 1;
	long long sum = 0;
	if(a[i] < s){
		while(i < n && a[i] < s){
			sum += s - a[i];
			++ i;
		}
	}
	else{
		while(i >= 0 && a[i] > s){
			sum += a[i] - s;
			-- i;
		}
	}
	cout << sum << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////