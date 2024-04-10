#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n);
		int a = 0; int b = 0;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			if(arr[i]==0)a++;
			if(arr[i]==1)b++;
		}
		int v1 = 1LL<<a;
		int v2 = b;
		cout << v1*v2 << "\n";
	}
	return 0;
}