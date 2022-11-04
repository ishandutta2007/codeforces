#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int q;cin>>q;
	while(q--){
		int u,v;cin>>u>>v;
		if(__builtin_popcount(u)<__builtin_popcount(v)||u>v){
			cout<<"NO\n";
			continue;
		}
		if(u==v){
			cout<<"YES\n";
			continue;
		}
		for(int i=29;i>=0;--i)if((1<<i)&u&v){
			u^=(1<<i);
			v^=(1<<i);
		}
		else if((1<<i)&v)break;
		int i=0,j=0;
		int n=__builtin_popcount(u),m=__builtin_popcount(v);
		assert(n>=m);
		bool pos=true;
		for(int k=0;k<m-1;++k){
			while(!((1<<i)&u))++i;
			while(!((1<<j)&v))++j;
			if(i>j){pos=false;break;}
			++i;++j;
		}
		if(pos)cout<<"YES\n";
		else cout<<"NO\n";
	}
}