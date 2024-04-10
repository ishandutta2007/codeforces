#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int get(int n){
	for(int i=n-1;i>1;--i)
		if(n/i+!!(n%i)>=i)return i;
	return 1;
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		int want=0;
		int nn=n;
		set<int>w;
		vector<pair<int,int>>res;
		while((want=get(nn))!=1){
			assert(!w.count(want));
			res.push_back({n,want});
			nn=nn/want+!!(nn%want);
			while(get(nn)==want){
				res.push_back({n,want});
				nn=nn/want+!!(nn%want);
			}
			res.push_back({want,n});
			w.insert(want);
		}
		assert(n-2-w.size()+res.size()<=n+5);
		cout<<n-2-w.size()+res.size()<<endl;
		for(int i=2;i<n;++i)if(!w.count(i))cout<<i<<" "<<n<<endl;
		for(auto r:res)cout<<r.first<<" "<<r.second<<endl;
	}
}