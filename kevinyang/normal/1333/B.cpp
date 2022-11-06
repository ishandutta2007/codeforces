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
		vector<int>arr2(n);
		for(int i = 0; i<n; i++){
			cin >> arr[i];
		}
		for(int i = 0; i<n; i++){
			cin >> arr2[i];
		}
		int start = n;
		int start2 = n;
		for(int i = 0; i<n; i++){
			if(arr[i]==1){
				start=i;
				break;
			}
		}
		for(int i = 0; i<n; i++){
			if(arr[i]==-1){
				start2 = i;
				break;
			}
		}
		bool f = true;
		for(int i = n-1; i>=0; i--){
			if(arr2[i]==arr[i])continue;
			if(arr2[i]<arr[i]&&start2<i)continue;
			if(arr2[i]>arr[i]&&start<i)continue;
			f = false;
		}
		if(f){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}

	}
	return 0;
}