#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=100100,inf=1e18;
ll t[N],x[N];

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;t[n]=inf;
		for(int i=0;i<n;++i)cin>>t[i]>>x[i];
		ll cx=0,dest=0;
		int res=0;
		for(int i=0;i<n;++i){
			if(cx==dest){
				dest=x[i];
			}
			if(cx>dest){
				if(x[i]<=cx&&x[i]>=dest&&x[i]+t[i+1]-t[i]>=cx)++res;
				cx=max(dest,cx-(t[i+1]-t[i]));
			}
			else if(cx<dest){
				if(x[i]>=cx&&x[i]<=dest&&cx+t[i+1]-t[i]>=x[i])++res;
				cx=min(dest,cx+(t[i+1]-t[i]));
			}
			else ++res;
		}
		cout<<res<<endl;
	}
}