#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,l,r;
ll ans=-1;
void solve1(bool o){
	if(k>=r&&k<=r*2)if(o==0||(o==1&&(k-r>0)))ans=max(ans,k-r+n-r);
	for(ll i=0;i<=n;++i){
		ll x=k-r;
		if(i<=n-r){
			if(x%(n+i)==0){
				if(o==0)ans=max(ans,i);
			}
			else{
				ll y=x%(n+i);
				if(y<=r&&y<=i&&(i-y<=n-r)){
					ans=max(ans,i);
				}
			}
		}
		else{
			x=k-r-(i-(n-r));
			if(x<0)continue;
			ll y=x%(n+i);
			if(y+(i-(n-r))<=r&&y<=n-r){
				ans=max(ans,i);
			}
		}
	}
}
void solve2(bool o){
	if(k>=r&&k<=r*2)if(o==0||(o==1&&(k-r>0)))ans=max(ans,k-r+n-r);
	for(ll i=1;i<=k/n;++i){
		ll x=k-r,y=x/i;
		
		if(y<n)continue;
		ll z=y-n,t=x%i;
		z-=t;
		if(z<0)continue;
		if(r<x%i)continue;
		if(z>n-r){
			ll m=z-(n-r);
			m=(m-1)/(i+1)+1;
			z-=(i+1)*m;
			t+=i*m;
		}
		if(z<0||t>r)continue;
		if(o==0||(o==1&&t>0))ans=max(ans,z+t);
	}
}
int main(){
	cin>>n>>l>>r>>k;
	r-=l-1;
	if(r<=0)r+=n;
	if(k<r){
		cout<<"-1\n";
		return 0;
	}
	if(n<1e6)solve1(0);
	else solve2(0);
	k++;
	if(n<1e6)solve1(1);
	else solve2(1);
	cout<<ans<<"\n";
}