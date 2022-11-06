#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	int cnt = 0;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		cnt+=arr[i];
	}
	while(q--){
		int t;
		cin >> t;
		if(t==1){
			int x;
			cin >> x;
			if(arr[x])cnt--;
			else cnt++;
			arr[x]^=1;
		}
		else{
			int k;
			cin >> k;
			if(cnt>=k){
				cout << "1\n";
			}
			else{
				cout << "0\n";
			}
		}
	}
	return 0;
}