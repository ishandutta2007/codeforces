#include <bits/stdc++.h>
using namespace std;
int n,m,t,a[110000],b[110000];
map<int,int> mp;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>t;
	for (int i=1;i<=n;i++) cin>>a[i];
	cin>>m>>t;
	for (int i=1;i<=m;i++) cin>>b[i];
	int ans=2;
	for (int k=0;k<30;k++){
		int d=(1<<k);
		for (int i=1;i<=n;i++){
			mp[a[i]%(2*d)]++;
			ans=max(ans,mp[a[i]%(2*d)]);
		}
		for (int i=1;i<=m;i++){
			mp[(b[i]+d)%(2*d)]++;
			ans=max(ans,mp[(b[i]+d)%(2*d)]);
		}
		mp.clear();
	}
	cout<<ans<<endl;
	return 0;
}