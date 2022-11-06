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
		int xr = 0;
		for(int i = 0; i<n; i++){
			cin >> arr[i];
			xr ^= arr[i];
		}
		if(xr==0){
			cout << "DRAW\n";
			continue;
		}
		for(int i = 30; i>=0; i--){
			if(xr & (1<<i)){
				int ones = 0;
				int zeroes = 0;
				for(int j = 0; j<n; j++){
					if(arr[j]&(1<<i)){
						ones++;
					}
					else{
						zeroes++;
					}
					
				}
				if(ones%4==3&&zeroes%2==0){
					cout <<"LOSE\n";
				}
				else{
					cout << "WIN\n";
				}
				break;
			}
		}
	}
	return 0;
}