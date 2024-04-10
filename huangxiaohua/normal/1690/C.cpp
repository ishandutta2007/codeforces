#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,a[1000500],b[1000500];

int main(void){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n;
    	for(i=1;i<=n;i++)cin>>a[i];
    	for(i=1;i<=n;i++)cin>>b[i];
    	for(i=1;i<=n;i++){
    		cout<<b[i]-max(a[i],b[i-1])<<' ';
		}
		cout<<"\n";
		aaa:;
	}
}