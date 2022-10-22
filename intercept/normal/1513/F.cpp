#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=1e6+9;
int n;
int a[M],b[M];
ll ans,sum;
pii p[M];
void solve(){
	int num=0;
	for(int i=1;i<=n;++i){
		if(b[i]>a[i])p[++num]=make_pair(b[i],a[i]);
	}
	sort(p+1,p+num+1);
	for(int i=num-1;i>=1;--i){
		p[i].se=min(p[i].se,p[i+1].se);
	}
	for(int i=1;i<=n;++i){
		if(b[i]<=a[i]){
			int x=lower_bound(p+1,p+num+1,make_pair(a[i],0))-p;
			if(x<=num){
				auto o=p[x];
				ans=min(ans,sum-a[i]*2+max(b[i],o.se)*2);
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	for(int i=1;i<=n;++i){
		sum+=abs(a[i]-b[i]);
	}
	ans=sum;
	solve();
	for(int i=1;i<=n;++i)swap(a[i],b[i]);
	solve();
	cout<<ans<<"\n";
	return 0;
}