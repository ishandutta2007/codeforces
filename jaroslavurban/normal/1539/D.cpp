#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	deque<pair<ll,ll>>a(n); // for disc, want to buy
	for(int i=0;i<n;++i)cin>>a[i].second>>a[i].first;
	sort(a.begin(),a.end());
	ll bought=0,res=0;
	for(;a.size();){
		auto[todisc,want]=a.front();
//		cerr<<"need "<<todisc<<" and want "<<want<<endl;
		while(todisc>bought&&a.size()){
			ll need=todisc-bought;
			auto&[tod,tobuy]=a.back();
			ll buys=min(tobuy,need);
//			cerr<<"buying "<<buys<<" from "<<tod<<endl;
			tobuy-=buys;
			bought+=buys;
			res+=2*buys;
			if(!tobuy)a.pop_back();
		}
		if(a.size()){
			auto[todisc,want]=a.front();
			assert(todisc<=bought);
//			cerr<<"buying "<<want<<" for 1 from "<<todisc<<endl;
			bought+=want;
			res+=want;
			a.pop_front();
		}
	}
	cout<<res<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}