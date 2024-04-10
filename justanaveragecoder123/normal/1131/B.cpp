#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<pair<int,int>> t(n+1);
	t[0]={0,0};
	for(int i=1;i<=n;++i) cin>>t[i].first>>t[i].second;
	int ans=0;
	for(int i=0;i+1<=n;++i) {
		if(t[i].first==t[i+1].first && t[i].second==t[i+1].second) continue ;
		
		
		int legkisebb=max(t[i].first, t[i].second);
		int legnagyobb=min(t[i+1].first, t[i+1].second);
		//cerr<<legkisebb<<" "<<legnagyobb<<"\n";
		ans+=max(0,legnagyobb-legkisebb+1);
		if(t[i+1].first==t[i+1].second) ans--;
		
	}
	if(t[n].first==t[n].second) ans++;
	cout<<ans<<"\n";
	
	
	return 0;
}