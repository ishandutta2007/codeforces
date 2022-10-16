#include <bits/stdc++.h>
#define int long long
using namespace std; 
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,t,tt;
	cin>>n;
	int cnt=0;
	int arr[n+5];
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=1;i<n;i++){
		if(arr[i-1]==1){
			if(arr[i]==2){
				cnt+=3;
				if(i>=2){
					if(arr[i-2]==3)cnt--;
				}
			}
			else cnt+=4;
		}
		else if(arr[i-1]==2){
			if(arr[i]==1){
				cnt+=3;
				
			}
			else{
				cout<<"Infinite"<<endl;
				return 0;
			}
		}
		else{
			if(arr[i]==1)cnt+=4;
			else {
				cout<<"Infinite"<<endl;
				return 0;
			}
		}
		swap(t,tt);
	}
	cout<<"Finite"<<endl<<cnt<<endl;
	return 0;
}