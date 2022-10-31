#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a[200500],b[200500],sb;

bool chk(ll x){
	memcpy(b,a,sizeof(ll)*n+50);
	for(i=n;i>=3;i--){
		if(b[i]<x)return 0;
		sb=min(b[i]-x,a[i])/3;
		b[i-1]+=sb;
		b[i-2]+=sb*2;
	}
	return min(b[1],b[2])>=x;
}

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i];
		int l=0,r=1e9,md,res=0;
		while(l<=r){
			md=(l+r)/2;
			if(chk(md)){res=max(res,md);l=md+1;}
			else r=md-1;
		}
		cout<<res<<'\n';
	}
}