#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],sb;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		int l=1,r=n/2,md,ans=n+1;
		while(l<=r){
			md=(l+r)/2;
			md*=2;
			cout<<"? "<<1<<' '<<md<<endl;
			k=0;
			for(i=1;i<=md;i++){
				cin>>j;
				if(j>md)k^=1;
			}
			if(k){
				ans=min(ans,md);r=md/2-1;
			}
			else l=md/2+1;
		}
		cout<<"? "<<ans-1<<' '<<ans-1<<endl;
		cin>>k;
		cout<<"! ";
		if(k==(ans-1))cout<<ans-1<<endl;
		else cout<<ans<<endl;
	}
}