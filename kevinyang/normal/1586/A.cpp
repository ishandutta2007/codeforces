#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isprime(int x){
	for(int i = 2; i*i<=x; i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int sum = 0;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
			sum+=arr[i];
		}
		if(!isprime(sum)){
			cout << n << "\n";
			for(int i = 1; i<=n; i++){
				cout << i << " ";
			}
			cout << "\n";
		}
		else{
			assert(sum%2==1);
			int bad = 0;
			cout << n-1 << "\n";
			for(int i = 1; i<=n; i++){
				if(arr[i]%2==1){
					bad = i;
					break;
				}
			}
			for(int i = 1; i<=n; i++){
				if(bad==i)continue;
				cout << i << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}