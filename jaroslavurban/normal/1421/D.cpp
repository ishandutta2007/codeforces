#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=6;
const unsigned long long inf=ULLONG_MAX;
pair<ll,ll>v[N]={
	{1,1},
	{0,1},
	{-1,0},
	{-1,-1},
	{0,-1},
	{1,0},
};
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	ll tt;cin>>tt;
	while(tt--){
		ll x,y;cin>>y>>x;
		ll cos[N];
		unsigned long long pr=inf;
		for(int i=0;i<N;++i)cin>>cos[i];
		for(int i=0;i<N;++i)
			for(int j=i+1;j<N;++j){
				ll a=v[i].first,b=v[j].first,c=v[i].second,d=v[j].second;
				ll det=a*d-b*c;
				if(det!=0){
					ll yy=(y*d-b*x)/det;
					ll xx=(a*x-y*c)/det;
					if(!((y*d-b*x)%det==0&&(a*x-y*c)%det==0))continue;
					if(!(xx>=0&&yy>=0))continue;
					unsigned long long yt=yy;
					unsigned long long xt=xx;
					unsigned long long r=yt*cos[i]+xt*cos[j];
					pr=min(pr,r);
				}
			}
		assert(pr!=inf);
		cout<<pr<<endl;
	}
}