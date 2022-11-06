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
		for(int i = 0; i<n; i++){
			if(i%2==0){
				cout << abs(arr[i])*-1 << " ";
			}
			else{
				cout << abs(arr[i]) << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}