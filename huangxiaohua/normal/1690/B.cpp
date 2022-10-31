#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,a[100500],b[100500];

int main(void){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n;
    	for(i=1;i<=n;i++)cin>>a[i];
    	for(i=1;i<=n;i++)cin>>b[i];
    	int mx=0;
    	for(i=1;i<=n;i++)mx=max(mx,a[i]-b[i]);
    	for(i=1;i<=n;i++){
    		a[i]=max(0,a[i]-mx);
    		if(a[i]!=b[i]){
    			cout<<"NO\n";goto aaa;
			}
		}
		cout<<"YES\n";
		aaa:;
	}
}