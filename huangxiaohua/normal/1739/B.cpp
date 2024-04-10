#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[10005];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=2;i<=n;i++){
			//printf("NMSL%d %d\n",a[i-1],a[i]);
			if(a[i]&&a[i]<=a[i-1]){
				cout<<"-1\n";goto aaa;
			}
			a[i]+=a[i-1];
		}
		for(i=1;i<=n;i++)cout<<a[i]<<' ';
		cout<<endl;
		aaa:;
	}
}