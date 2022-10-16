#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int arr[n+5];
	map<int,int>cnt;
	for(int i=0;i<=200000;i++)cnt[i]=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		cnt[arr[i]]++;
	}
	int max=0,maxi=0;
	for(int i=0;i<200000;i++){
		if(cnt[i]>max){
			max=cnt[i];
			maxi=i;
		}
	}
	int first=1,last=n;
	while(arr[first]!=maxi)first++;
	while(arr[last]!=maxi)last--;
	cout<<n-max<<endl;
	for(int i=last+1;i<=n;i++){
		if(arr[i]<maxi)cout<<"1 "<<i<<" "<<i-1<<endl;
		else if(arr[i]>maxi)cout<<"2 "<<i<<" "<<i-1<<endl;
	}
	for(int i=first-1;i>0;i--){
		if(arr[i]<maxi)cout<<"1 "<<i<<" "<<i+1<<endl;
		else if(arr[i]>maxi)cout<<"2 "<<i<<" "<<i+1<<endl;
	}
	for(int i=first+1;i<last;i++){
		if(arr[i]==maxi)continue;
		if(arr[i]<maxi)cout<<"1 "<<i<<" "<<i-1<<endl;
		else if(arr[i]>maxi)cout<<"2 "<<i<<" "<<i-1<<endl;
	}
	return 0;
}