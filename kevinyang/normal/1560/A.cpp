#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	vector<int>arr;
	for(int i = 0; i<100000; i++){
		if(i%3==0||i%10==3)continue;
		arr.push_back(i);
	}
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		cout << arr[x-1] << "\n";
	}
	return 0;
}