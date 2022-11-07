#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n);
	int mx = 0;
	int mn = 2e9;
	for(int i = 0; i<n; i++){
		cin >> arr[i];
		mx = max(mx,arr[i]);
		mn = min(mn,arr[i]);
	}
	vector<int>arr2(n);
	int mxgcd = mx-mn;
	for(int i = 0; i<n; i++){
		arr2[i] = mx-arr[i];
		if(arr2[i]!=0)
		mxgcd = gcd(mxgcd,arr2[i]);
	}
	long long total = 0;
	for(int i = 0; i<n; i++){
		total+=arr2[i]/mxgcd;
	}
	cout << total << " " << mxgcd;
	return 0;
}