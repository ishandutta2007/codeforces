#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n,k;cin>>n>>k;
	vector<int>f(n*k),lst(n,-1),tmp((n+k-2)/(k-1)),done(n);
	vector<pair<int,int>>res(n);
	multiset<int>can(tmp.begin(),tmp.end());
	int i=0;
	for(int&v:f){
		cin>>v;--v;
//		cerr<<v<<" "<<lst[v]<<endl;
		if(~lst[v]&&!done[v]){
			int l=lst[v],r=i+1;
//			cerr<<l<<" "<<*can.begin()<<endl;
			if(*can.begin()<=l){
				res[v]={l,r};
				can.erase(prev(can.lower_bound(l+1)));
				can.insert(r);
				done[v]=true;
			}
		}
		lst[v]=i;
		++i;
	}
	for(auto[l,r]:res)cout<<l+1<<" "<<r<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}