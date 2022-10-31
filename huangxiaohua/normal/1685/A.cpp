#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1005000],b[1005000];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i];
		if(n&1){
			cout<<"NO\n";continue;
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n/2;i++){
			b[i*2-1]=a[i];
			b[i*2]=a[n/2+i];
		}
		b[n+1]=a[1];
		b[0]=a[n];
		for(i=1;i<=n;i+=2){
			if(b[i]<b[i-1]&&b[i]<b[i+1])continue;
			cout<<"NO\n";goto aaa;
		}
		cout<<"YES\n";
		for(i=1;i<=n;i++){
			cout<<b[i]<<' ';
		}
		cout<<'\n';
		aaa:;
	}
}