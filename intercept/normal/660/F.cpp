#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=2e5+9;
int n;
ll a[M];
__int128_t p[M],s[M],g[M];
int q[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],p[i]=p[i-1]+i*a[i],s[i]=s[i-1]+a[i];
	ll ans=0;
	int tot=0;
	for(int i=1;i<=n;++i){
		int l=0,r=tot-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(s[i]*(q[mid+1]-q[mid])<g[q[mid]]-g[q[mid+1]])l=mid+1;
			else r=mid;
		}
		ans=max(ans,(ll)(p[i]-q[l]*s[i]-g[q[l]]));
		ans=max(ans,(ll)(p[i]-q[l+1]*s[i]-g[q[l+1]]));
		g[i]=p[i]-i*s[i];
		while(tot&&(g[q[tot]]-g[i])*(q[tot]-q[tot-1])>(g[q[tot-1]]-g[q[tot]])*(i-q[tot]))tot--;
		q[++tot]=i;
	}
	cout<<ans<<endl;
	return 0;
}