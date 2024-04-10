#include <bits/stdc++.h>
using namespace std; 
int arr[16];
int tsort(int a,int s){
	if(a==1){
		return 1;
	}
	int t=a+s;
	int abc[a];
	for(int i=0;i<a;i++)abc[i]=arr[i+s];
	sort(abc,abc+a);
	for(int i=s;i<s+a;i++){
		if(abc[i-s]!=arr[i]){
				return max(tsort(a/2,s),tsort(a/2,s+a/2));
		}
	}
	return a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;

	for(int i=0;i<n;i++)cin>>arr[i];
	cout<<tsort(n,0)<<endl;
	return 0;
}