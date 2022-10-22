#include<bits/stdc++.h>
using namespace std;
#define N 100100
typedef long long ll;
int n,a[N],b[N],p[N],t[N],vis[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
		p[a[i]]=b[i];
		vis[i]=0;
	}
	int jb=0;
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		int cnt=0;
		for(int u=i;!vis[u];u=p[u]){
			++cnt;
			vis[u]=1;
		}
		jb+=cnt&1;
	}
	int m=(n-jb)/2;
	ll ans=0;
	for(int i=1;i<=m;++i){
		ans+=(n-i+1)-i;
	}
	cout<<ans*2<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}