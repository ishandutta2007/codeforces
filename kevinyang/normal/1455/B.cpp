#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		int count = 1;
		while(count*(count+1)/2<x){
			count++;
		}
		if(count*(count+1)/2==x+1){
			count++;
		}
		cout << count << "\n";
	}
	return 0;
}