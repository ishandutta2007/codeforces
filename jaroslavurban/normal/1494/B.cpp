#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,u,d,r,l;cin>>n>>u>>r>>d>>l;
		bool pos=false;
		for(int i=0;i<(1<<4);++i){
			int cu=u,cd=d,cr=r,cl=l;
			if(i&(1<<0)){
				--cu;
				--cl;
			}
			if(i&(1<<1)){
				--cu;
				--cr;
			}
			if(i&(1<<2)){
				--cr;
				--cd;
			}
			if(i&(1<<3)){
				--cd;
				--cl;
			}
			if(cu>=0&&cu<=n-2&&
				cr>=0&&cr<=n-2&&
				cd>=0&&cd<=n-2&&
				cl>=0&&cl<=n-2)pos=true;
		}
		if(pos)cout<<"YES\n";
		else cout<<"NO\n";
	}
}