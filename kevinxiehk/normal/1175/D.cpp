#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 
bool cmd(int a,int b){
	if(a>b)return true;
	return false;
}
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	int arr[n+5];
	for(int i=1;i<=n;i++)cin>>arr[i];
	int psum[n+5];
	psum[n]=arr[n];
	for(int i=n-1;i>=1;i--)psum[i]=psum[i+1]+arr[i];
	sort(psum+2,psum+n+1,cmd);
	int sum=0;
	for(int i=1;i<=k;i++)sum+=psum[i];
	cout<<sum<<endl;
	return 0;
}