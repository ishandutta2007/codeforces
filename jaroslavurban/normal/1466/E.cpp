#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=500100,M=60,m=1e9+7; // M is exclusive
int cnt[M];
ll a[N];

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n;cin>>n;
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;++i){
			cin>>a[i];
			for(int j=0;j<M;++j)
				if((1ll<<j)&a[i])
					++cnt[j];
		}
		ll res=0;
		for(int i=0;i<n;++i){
			ll ladd=0,radd=0;
			for(int j=0;j<M;++j){
				if(a[i]&(1ll<<j)){
					ladd=(ladd+cnt[j]*((1ll<<j)%m)%m)%m;
					radd=(radd+n*((1ll<<j)%m)%m)%m;
				}else{
					radd=(radd+cnt[j]*((1ll<<j)%m)%m)%m;
				}
			}
			res=(res+ladd*radd%m)%m;
		}

		cout<<res<<endl;
	}
}