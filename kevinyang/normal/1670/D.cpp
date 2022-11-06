#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	vector<int>arr(200001);
	vector<int>a(3);
	for(int i = 1; i<=200000; i++){
		int v = i%3;
		int val = a[0]+a[1]+a[2]-a[v];
		val*=2;
		arr[i] = arr[i-1]+val;
		a[v]++;
	}
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << lower_bound(arr.begin(),arr.end(),n)-arr.begin() << "\n";
	}
	return 0;
}