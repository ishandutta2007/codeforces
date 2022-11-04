#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		vector<int>a(n);
		for(int i=0;i<n;++i)cin>>a[i];
		int m;cin>>m;
		vector<int>b(m);
		for(int i=0;i<m;++i)cin>>b[i];
		vector<int>p1(n+1),p2(m+1);
		for(int i=0;i<n;++i)p1[i+1]=a[i]+p1[i];
		for(int i=0;i<m;++i)p2[i+1]=b[i]+p2[i];
		int res=-1e9;
		for(int i=0;i<=n;++i)
			for(int j=0;j<=m;++j)
				res=max(res,p1[i]+p2[j]);
		cout<<res<<endl;
	}
}