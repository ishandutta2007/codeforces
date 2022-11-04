#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=110;
int a[N];

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,u,v;cin>>n>>u>>v;swap(u,v);
		for(int i=0;i<n;++i)cin>>a[i];
		bool same=true;
		for(int i=1;i<n;++i)if(a[i]!=a[0])same=false;
		if(same){
			cout<<min(2*u,u+v)<<endl;
			continue;
		}
		bool wall=true;
		for(int i=1;i<n;++i)if(abs(a[i]-a[i-1])>1)wall=false;
		if(wall){
			cout<<min(u,v)<<endl;
			continue;
		}
		cout<<0<<endl;
	}
}