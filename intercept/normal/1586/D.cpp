#include<bits/stdc++.h>
using namespace std;
int n;
int a[109];
int p=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cout<<"? ";
		for(int j=1;j<n;++j){
			cout<<"1 ";
		}
		cout<<i<<endl;
		cout.flush();
		int x;
		cin>>x;
		a[x]=i-1;
	}
	for(int i=1;i<=n;++i){
		cout<<"? ";
		for(int j=1;j<n;++j){
			cout<<i<<" ";
		}
		cout<<1<<endl;
		cout.flush();
		int x;
		cin>>x;
		a[x]=1-i;
		if(x)p=min(p,1-i);
	}
	for(int i=1;i<=n;++i)a[i]-=p-1;
	cout<<"! ";
	for(int i=1;i<=n;++i)cout<<a[i]<<" ";
	return 0;
}