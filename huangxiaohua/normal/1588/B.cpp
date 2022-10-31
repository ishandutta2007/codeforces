#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,t;

ll l,r,md,k,sb,nmsl,ans,res,nmsl1,nmsl2;

ll ask(ll l,ll r){
	cout<<"? "<<l<<' '<<r<<endl;
	ll NMSL;cin>>NMSL;return NMSL;
}

int main() {

	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		res=0;
		l=1;r=n;
		while(l<=r){
			md=(l+r)/2;
			if(!ask(1,md)){
				res=max(res,md);l=md+1;
			}
			else r=md-1;
		}
		nmsl1=res+ask(res,n)-ask(res+1,n)+1;
		nmsl2=nmsl1+ask(nmsl1,n)-ask(nmsl1+1,n);
		
		cout<<"! "<<res<<' '<<nmsl1<<' '<<nmsl2<<endl;
	}
}