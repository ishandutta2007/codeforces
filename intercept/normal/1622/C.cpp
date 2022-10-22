#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n;
ll k;
ll a[M],s[M];
void work(){
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	s[n]=a[n];
	for(int i=n-1;i>=1;--i){
		s[i]=s[i+1]+a[i];
	}
	if(s[1]<=k){
		puts("0");
		return;
	}
	ll ans=s[1]-k;
	for(int i=n,j=2;i>=2;--i,++j){
		ll l=0,r=2e9;
		while(l<r){
			ll mid=(l+r)>>1;
			if(s[2]-s[i]+1ll*j*(a[1]-mid)<=k)r=mid;
			else l=mid+1;
		}
		ans=min(ans,l+j-1);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
10 1
1 1 1 2 2 3 6 6 8 10
*/