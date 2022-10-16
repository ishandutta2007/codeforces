#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 	
int arr[200005];
int bs(int a,int b,int target){
	if(b-a<=2)return a;
	int t=(a+b)/2;
	if(arr[t]<target)return bs(t,b,target);
	return bs(a,t,target);
}
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		arr[i]=abs(arr[i]);
	}
	sort(arr,arr+n);
	int cnt=0;
	for(int i=0;i<n-1;i++){
		if(arr[i+1]>arr[i]*2)continue;
		int a=bs(i+1,n-1,arr[i]*2);
		//cout<<a<<endl;
		while(arr[a]<=arr[i]*2){
			a++;
			if(a==n)break;
		}
		cnt+=(a-i-1);
	}
	cout<<cnt<<endl;
	return 0;
}