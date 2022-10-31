#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,a[500500],res,pre[500500],sb;

ll chk(ll x){
	ll l=0,r=(n-x)/k,md,ans=0,tmp;
	while(l<=r){
		md=(l+r)/2;
		tmp=pre[md*k+x]-pre[x];
		if(tmp<=m){
			l=md+1;
			ans=max(ans,md);
		}
		else{
			r=md-1;
		}
	}
	return ans*k;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		res=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++){
			if(i<=k){
				pre[i]=a[i];
			}
			else{
				pre[i]=pre[i-k]+a[i];
			}
		}
		sb=0;
		for(i=0;i<=n;i++){
			m-=a[i];
			if(m<0)break;
			res=max(res,i+chk(i));
		}
		cout<<res<<'\n';
	}
}