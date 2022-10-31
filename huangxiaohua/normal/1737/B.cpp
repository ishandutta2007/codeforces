#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,l,r;

ll fuck(ll w){
	if(!w)return 0;
	
	ll t1=sqrt(w),ans;
	while((t1+1)*(t1+1)<=w)t1++;
	while(t1*t1>w)t1--;
	
	ans=t1*3;
	if((t1*t1+t1+t1)>w)ans--;
	if((t1*t1+t1)>w)ans--;
	
	return ans;
}

int main() {
	/*for(i=1;i<=100;i++){
		cout<<i<<' '<<fuck(i)<<'\n';
	}*/
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>l>>r;
		ll res=fuck(r)-fuck(l-1);
		cout<<res<<'\n';
	}
}