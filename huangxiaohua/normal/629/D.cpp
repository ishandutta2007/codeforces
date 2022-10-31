#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define se (*it).second

int i,j,k,n,m;
ll a[100500],x,y;
set<pair<ll,ll> >s;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&x,&y);
		a[i]=x*x*y;
	}
	s.insert({-1,0});
	s.insert({5e18,5e18});
	for(i=1;i<=n;i++){
		auto it=s.lower_bound({a[i],-1}),it2=it;
		it--;y=a[i]+se;it++;
		if((*it).first==a[i]&&se>=y){continue;}
		while(se<y){
			it2=it;it++;s.erase(it2);
		}
		s.insert({{a[i],y}});
	}
	auto it=s.end();it--;it--;
	printf("%.20lf",se*asin(1)*2);
}