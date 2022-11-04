#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	vector<pair<int,int>>ac(n);
	for(int i=0;i<n;++i)cin>>ac[i].first>>ac[i].second;
	auto [ca,cc]=ac[0];
	cc+=ca;
	int pc=cc;
	sort(ac.begin(),ac.end());
	ll res=0;
	for(auto [a,c]:ac){
		res+=c;
		if(a>=cc)res+=a-cc;
		cc=max(cc,a+c);
	}
	cc=ac[0].first+ac[0].second;
	for(auto [a,c]:ac){
		if(a>=cc)res+=a-cc;
		cc=max(cc,a+c);
		if(cc>=pc)break;
	}
	cout<<res<<endl;
}