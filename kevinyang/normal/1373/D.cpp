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
		long long sum = 0;
		for(int i = 0; i<n; i+=2){
			sum+=arr[i];
		}
		long long mx = 0;
		long long cur = 0;
		for(int i = 0;i<n-1; i+=2){
			cur+=(arr[i+1]-arr[i]);
			if(cur<0)cur = 0;
			mx = max(mx,cur);
		}
		cur = 0;
		for(int i = 1; i<n-1; i+=2){
			cur+=(arr[i]-arr[i+1]);
			if(cur<0)cur = 0;
			mx = max(mx,cur);
		}
		cout << mx + sum << "\n";
	}
	return 0;
}