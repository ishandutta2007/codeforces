// Hydro submission #61ae0970ebf4f7607a1184d6@1638795632950
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[105];
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	ll n, l, r, k;
	while(t--){
		cin >> n >> l >> r >> k;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		sort(arr, arr + n);
		long long sum = 0;
		for(int i = 0; i < n; i++){
			if(arr[i] >= l && arr[i] <= r && k >= arr[i]){
				sum++;
				k -= arr[i]; 
			}
		}
		cout << sum << endl; 
	}
	return 0;
}