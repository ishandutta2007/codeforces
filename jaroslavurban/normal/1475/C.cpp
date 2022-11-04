#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int a,b,k;cin>>a>>b>>k;
		map<pair<int,int>,int>cntboth;
		vector<int>aa(k),bb(k);
		vector<int>cnt(a+1),cnt2(b+1);
		for(int i=0;i<k;++i){
			cin>>aa[i];++cnt[aa[i]];
		}
		for(int i=0;i<k;++i){
			cin>>bb[i];++cnt2[bb[i]];
		}
		for(int i=0;i<k;++i)++cntboth[{aa[i],bb[i]}];
		ll res=0;
		for(int i=0;i<k;++i)res+=(k-cnt[aa[i]]-cnt2[bb[i]]+cntboth[{aa[i],bb[i]}]);
		cout<<res/2<<endl;
	}
}