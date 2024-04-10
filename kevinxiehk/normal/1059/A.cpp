#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,l,a,sum=0;
	cin>>n>>l>>a;
	double arr[n+5],use[n+5];
	for(int i=0;i<n;i++){
		cin>>arr[i]>>use[i];
	}
	sum+=floor(arr[0]/a);
	for(int i=0;i<n-1;i++){
		sum+=(arr[i+1]-arr[i]-use[i])/a;
	}
	sum+=floor((l-1-(arr[n-1]+use[n-1]-1))/a);
	cout<<sum<<endl;
	return 0;
}