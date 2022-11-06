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
		vector<int>odd;
		vector<int>even;
		for(int i = 0; i<n; i++){
			if(i%2==0){
				int x;
				cin >> x;
				even.push_back(x);
			}
			else{
				int x;
				cin >> x;
				odd.push_back(x);
			}
		}
		sort(odd.begin(),odd.end());
		sort(even.begin(),even.end());
		vector<int>arr;
		vector<int>arr2;
		for(int i = 0; i<n; i++){
			if(i%2==0){
				arr.push_back(even[i/2]);
				arr2.push_back(even[i/2]);
			}
			else{
				arr2.push_back(odd[i/2]);
				arr.push_back(odd[i/2]);
			}
		}
		sort(arr2.begin(),arr2.end());
		bool f = true;
		for(int i = 0; i<n; i++){
			if(arr[i]!=arr2[i])f = false;
		}
		if(f)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}