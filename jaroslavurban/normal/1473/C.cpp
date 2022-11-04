#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,k;cin>>n>>k;
		vector<int>res(k);
		iota(res.begin(),res.end(),1);
		for(int i=0;i<n-k+1;++i)res[k-i-1]=2*k-n+i;
		for(auto r:res)cout<<r<<" ";cout<<endl;
	}
}