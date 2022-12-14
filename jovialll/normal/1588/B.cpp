#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,n,ans,l,r,mid,l1,l2,i,j,k,gg,zz;
ll ask(ll i,ll j,ll k){
	cout<<"? "<<i<<" "<<k<<"\n";cout.flush();
	ll x;cin>>x;return x;
} 
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		ans=ask(1,1,n);
		l=1;r=n;
		while(l<r){
			mid=r-(r-l>>1);
			if(ask(1,1,mid)==ans)r=mid-1;
			else l=mid;
		}
		l2=ans-ask(1,1,l);
		k=l+1;
		j=k-l2;
		gg=(ans-l2*(l2+1)/2)*2;
		zz=sqrt(gg);
		for(i=max(1ll,zz-5);i<=zz+5;++i){
			if(1ll*i*(i-1)==gg)l1=i;
		}
		i=j-l1;
		cout<<"! "<<i<<' '<<j<<" "<<k<<"\n";cout.flush();
	}
}