#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	vector<vector<int>>f(n,vector<int>(n,-1));
	function<int(int,int,int,int)>travel=[&](int i,int j,int p,int l){
//		if(i>=n)cout<<i<<" "<<j<<" "<<p<<" "<<l<<endl;
		assert(i<n);
		assert(!~f[i][j]);
		f[i][j]=p;
		if(!--l)return 0;
		if(j&&!~f[i][j-1])return travel(i,j-1,p,l);
		return travel(i+1,j,p,l);
	};
	for(int i=0;i<n;++i){
		int p;cin>>p;
		travel(i,i,p,p);
	}
	for(int i=0;i<n;++i,cout<<"\n")
		for(int j=0;j<=i;++j)
			cout<<f[i][j]<<" ";
}