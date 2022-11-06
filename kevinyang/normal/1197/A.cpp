#include <bits/stdc++.h>
using namespace std;
int main(){
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
		sort(arr.begin(), arr.end());
		int height = min(arr[n-2],arr[n-1]);
		height--;
		height = min(height,n-2);
		cout << height << "\n";
	}
	return 0;
}