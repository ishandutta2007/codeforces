#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int i,j,k,n,m,t,a[666666];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)a[i]=i;
		for(i=n-1;i>=1;i-=2)swap(a[i],a[i+1]);
		for(i=1;i<=n;i++)cout<<a[i]<<' ';
		cout<<endl;
	}
}