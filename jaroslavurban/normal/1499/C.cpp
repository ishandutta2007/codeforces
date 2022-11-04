#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100;
int n;
int c[N];

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>c[i];
		int bst[2]={c[0],c[1]};
		ll cost=c[0]+c[1];
		ll res=ll(bst[0]+bst[1])*n;
		for(int i=2;i<n;++i){
			bst[i&1]=min(bst[i&1],c[i]);
			cost+=c[i];
			res=min(res,cost+bst[0]*ll(n-i/2-1)+bst[1]*ll(n-(i+1)/2));
		}
		cout<<res<<'\n';
	}
}