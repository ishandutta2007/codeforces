#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,k;cin>>n>>k;
		vector<int>res;
		for(int i=1;i<=n;++i)if(i+i>=k&&i!=k)res.push_back(i);
		cout<<res.size()<<endl;
		for(auto r:res)cout<<r<<" ";cout<<endl;
	}
}