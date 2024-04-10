#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll l,r,a[105],b[105],c[105],lst;

int main(){
	cin>>t;
	while(t--){
		cin>>n>>i;
		l=r=i;
		lst=0;
		for(i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(i=1;i<=n;i++){
			l-=(a[i]-lst);
			r+=(a[i]-lst);
			lst=a[i];
			if(r<b[i]||l>c[i]){
				cout<<"NO\n";goto aaa;
			}
			l=max(l,b[i]);
			r=min(r,c[i]);
		}
		cout<<"YES\n";
		aaa:;
	}
}