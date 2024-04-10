#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,NMSL[1005000];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		if((n%4)==0){
			for(i=0;i<n;i++)cout<<i<<' ';
		}
		else if((n%4)==1){
			cout<<0<<' ';
			for(i=2;i<=n;i++)cout<<i<<' ';
		}
		else if((n%4)==2){
			cout<<"1 2 3 4 8 12 ";
			for(i=1;i<=n-6;i++)cout<<99+i<<' ';
		}
		else if((n%4)==3){
			for(i=1;i<=n;i++)cout<<i<<' ';
		}
		cout<<'\n';
	}
}