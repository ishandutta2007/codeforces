#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[6666];

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		m=unique(a+1,a+n+1)-a-1;
		cout<<n-((n-m+1)/2)*2<<endl;
	}
}