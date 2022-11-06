#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int>arr(n);
	for(int i = 0; i<n; i++){
		arr[i] = (int)(s[i]-'0');
	}
	vector<int>arr2(n);
	for(int i = 0; i<k; i++){
		int cur = arr[i];
		for(int j = i; j<n; j+=k){
			arr2[j] = cur;
		}
	}
	bool larger = true;
	int ind = 0;
	for(int i = 0; i<n; i++){
		if(arr2[i]<arr[i]){
			larger = false;
			ind = i;
			break;
		}
		if(arr2[i]>arr[i])break;
	}
	if(larger){
		cout << n << "\n";
		for(int i = 0; i<n; i++){
			cout << arr2[i];
		}
		cout << "\n";
	}
	else{
		ind = min(ind,k-1);
		int cur = arr[ind]+1;
		for(int i = ind; i<n; i+=k){
			arr2[i] = cur;
		}
		cout << n << "\n";
		for(int i = n-1; i>0; i--){
			if(arr2[i]>9){
				arr2[i]-=10;
				arr2[i-1]++;
			}
		}
		for(int i = 0; i<k; i++){
			cur = arr2[i];
			for(int j = i; j<n; j+=k){
				arr2[j] = cur;
			}
		}
		for(int i = 0; i<n; i++){
			cout << arr2[i];
		}
		cout << "\n";
	}
	return 0;
}