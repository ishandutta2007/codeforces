#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int i,j,k,n,t;
ll x[200500],y[200500],s[200500],sb,m;
int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++)cin>>x[i]>>y[i];
		ll l=0,r=3e14,md,ans=0;
		while(l<=r){
			md=(l+r)/2;
			sb=m;
			for(i=1;i<=n;i++){
				sb-=x[i];
				if(y[i]<md){s[i]=m+1;continue;}
				s[i]=max(0ll,md-x[i]);
			}
			sort(s+1,s+n+1);
			for(i=1;i+i-1<=n;i++){
				sb-=s[i];
				if(sb<0)break;
			}
			if(sb>=0){ans=max(ans,md);l=md+1;}
			else r=md-1;
		}
		cout<<ans<<'\n';
	}
}