#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,third,min;
	cin>>n;
	int arr[n+5];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	third=arr[2];
	sort(arr,arr+n);
	cout<<2+(third^arr[0])<<endl;
	return 0;
}