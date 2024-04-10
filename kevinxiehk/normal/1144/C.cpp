#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<int,int>cnt;
	for(int i=0;i<=200000;i++)cnt[i]=false;
	int n,dis=0,t;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		cnt[t]++;
		if(cnt[t]>2){
			cout<<"NO"<<endl;
			return 0;
		}
		if(cnt[t]==1)dis++;
	}
	cout<<"YES"<<endl;
	cout<<dis<<endl;
	int outcnt=0;
	for(int i=0;i<=200000;i++){
		if(cnt[i]>=1){
			cout<<i;
			outcnt++;
			if(outcnt!=dis)cout<<" ";
		}	
	}
	cout<<endl<<n-dis<<endl;
	for(int i=200000;i>=0;i--){
		if(cnt[i]==2){
			cout<<i;
			outcnt++;
			if(outcnt!=n)cout<<" ";
		}	
	}
	cout<<endl;
	return 0;
}