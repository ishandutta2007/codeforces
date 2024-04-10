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
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		bool f = false;
		for(int i = 1; i<n-1; i++){
			int min1 = n;
			int min2 = n;
			int ind1 = 0;
			int ind2 = 0;
			for(int j = 0; j<i; j++){
				if(arr[j]<min1){
					ind1 = j;
					min1 = arr[j];
				}
			}
			for(int j = i+1; j<n; j++){
				if(arr[j]<min2){
					ind2 = j;
					min2 = arr[j];
				}
			}
			if(min1<arr[i] && arr[i]>min2){
				f = true;
				cout << "Yes\n";
				cout << ind1+1 << " " << i+1 << " " << ind2+1 << "\n";
				break;
			}
		}
		if(!f){
			cout << "No\n";
		}
	}
	return 0;
}