#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	array<int, 6> a;
	for(auto i = 0; i < 6; ++ i){
		cin >> a[i];
	}
	int n;
	cin >> n;
	vector<int> b(n);
	for(auto i = 0; i < n; ++ i){
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> t;
	for(auto x: a){
		for(auto y: b){
			t.push_back(y - x);
		}
	}
	sort(t.begin(), t.end()), t.erase(unique(t.begin(), t.end()), t.end());
	int low = -1, high = 1e9;
	auto test = [&](int th){ // difference can be <= th
		for(auto mindif: t){
			int i = 0;
			for(auto x: a){
				if(b[i] - x >= mindif){
					i = upper_bound(b.begin(), b.end(), x + th + mindif) - b.begin();
				}
				else{
					break;
				}
				if(i == n){
					return true;
				}
			}
		}
		return false;
	};
	while(high - low >= 2){
		int mid = low + (high - low >> 1);
		if(test(mid)){
			high = mid;
		}
		else{
			low = mid;
		}
	}
	cout << high << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////