#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int T;
	cin>>T;
	while(T--) {
		ll n,s;
		cin>>n>>s;
		vector<ll> t(n);
		for(int i=0;i<n;++i) cin>>t[i];
		priority_queue<pair<ll,int>> pq;
		ll sum=0;
		ll ans=0, ans_skip=0;
		for(int i=0;i<n;++i) {
			sum+=t[i];
			pq.push({t[i],i+1});
			
			if(sum<=s) {
				ans=i+1;
				ans_skip=0;
			}else {
				
				if(sum-pq.top().first<=s) {
					if(ans<i) {
						ans=i;
						ans_skip=pq.top().second;
					}
				}else {
					break;
				}
			}
		}
		cout<<ans_skip<<"\n";
	}
	return 0;
}