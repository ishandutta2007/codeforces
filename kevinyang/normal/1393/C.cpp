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
		vector<int>arr(100001);
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			arr[x]++;
		}
		sort(arr.begin(), arr.end());
		int len = arr[100000]-1;
		int cur = 0;
		int end = 0;
		int sum = 0;
		for(int i = 99999; i>=0; i--){
			if(arr[i]==arr[100000])cur++;
			else{
				end = i; break;
			}
		}
		for(int i = 0; i<=end; i++){
			sum+=arr[i];
		}
		cur+=sum/len;
		cout << cur << "\n";
	}
	return 0;
}