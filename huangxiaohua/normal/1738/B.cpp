#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int i,j,k,n,m,t;
ll a[1000050],p[1000050];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n+5;i++)a[i]=p[i]=0;
		for(i=1;i<=m;i++){
			cin>>p[n-m+i];
			if(i>1){
				a[n-m+i]=p[n-m+i]-p[n-m+i-1];
			}
		}
		
		if(m==1){
			cout<<"yes\n";continue;
		}
		for(i=n-m+1;i>=1;i--){
			a[i]=a[i+1];
			p[i]=p[i+1]-a[i+1];
		}
		a[1]=p[1];
		
		//for(i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<'\n';
		for(i=2;i<=n;i++){
			if(a[i]<a[i-1]){
				cout<<"no\n";goto aaa;
			}
		}
		cout<<"yes\n";
		aaa:;
	}
}