#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500];
ll r1,l[200500],r[200500];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		for(i=1;i<=n+10;i++)l[i]=r[i]=0;
		r1=0;
		if(n&1){
			for(i=2;i<n;i+=2){
				r1+=max(0,max(a[i-1],a[i+1])+1-a[i]);
			}
			cout<<r1<<'\n';continue;
		}
		r1=1e18;
		for(i=2;i<=n;i++){
			l[i]=l[i-2]+max(0,max(a[i-1],a[i+1])+1-a[i]);
		}
		for(i=n-1;i>=1;i--){
			r[i]=r[i+2]+max(0,max(a[i-1],a[i+1])+1-a[i]);
		}
		for(i=2;i<n;i+=2){
			r1=min(r1,l[i]+r[i+3]);
		}
		for(i=3;i<=n;i+=2){
			r1=min(r1,l[i]+r[i+2]);
		}
		cout<<r1<<'\n';continue;
	}
}