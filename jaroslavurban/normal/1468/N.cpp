#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int c[3],a[5];
		for(int i=0;i<3;++i)cin>>c[i];
		for(int i=0;i<5;++i)cin>>a[i];
		for(int i=0;i<3;++i)c[i]-=a[i];
		if(c[0]>0){
			a[3]-=c[0];
		}
		if(c[1]>0){
			a[4]-=c[1];
		}
		c[2]-=max(0,a[3])+max(0,a[4]);
		cout<<(min({c[0],c[1],c[2]})>=0?"YES\n":"NO\n");
	}
}