#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		for(int i = 0; i<d; i++){
			for(int j = 2; j<=n; j++){
				if(arr[j]>0){
					arr[j]--;
					arr[j-1]++;
					break;
				}
			}
		}
		cout << arr[1] << "\n";
	}
	return 0;
}