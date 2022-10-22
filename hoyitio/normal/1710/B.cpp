#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
typedef pair<ll,ll> pll;
typedef pair<pll,int>ppi;
#define fi first
#define se second
ll c[maxn],mx[maxn];
int id[maxn],m,n,p[maxn],t_case,x[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		vector<ppi>v;
		for(ri i=1;i<=n;++i){
			c[i]=mx[i]=0;
			ri x,p;
			scanf("%d%d",&x,&p);
			v.emplace_back(pll{x,p},i);
		}
		sort(v.begin(),v.end());
		for(ri i=1;i<=n;++i){
			x[i]=v[i-1].fi.fi;
			p[i]=v[i-1].fi.se;
			id[v[i-1].se]=i;
		}
		multiset<ll>s;
		ll sum=0;
		for(ri i=1;i<=n;++i){
			while(s.size()&&*s.begin()<=x[i])sum-=*s.begin()-x[i-1],s.erase(s.begin());
			sum-=1ll*s.size()*(x[i]-x[i-1])-p[i];
			c[i]+=sum;
			s.insert(x[i]+p[i]);
		}
		{multiset<ll>().swap(s);}
		sum=0,x[n+1]=INT_MAX;
		for(ri i=n;i;--i){
			while(s.size()&&*s.begin()<=-x[i])sum-=*s.begin()+x[i+1],s.erase(s.begin());
			sum-=1ll*s.size()*(x[i+1]-x[i])-p[i];
			c[i]+=sum-p[i];
			s.insert(p[i]-x[i]);
		}
		for(ri i=1;i<=n;++i)ckmax(c[i]-=m,0ll);
		ll tot=LLONG_MIN;
		for(ri i=1;i<=n;++i){
			tot+=x[i]-x[i-1];
			if(c[i])ckmax(tot,c[i]);
			ckmax(mx[i],tot);
		}
		tot=LLONG_MIN;
		for(ri i=n;i;--i){
			tot+=x[i+1]-x[i];
			if(c[i])ckmax(tot,c[i]);
			ckmax(mx[i],tot);
		}
		for(ri i=1;i<=n;++i)putchar(48|(mx[id[i]]<=p[id[i]]));
		putchar(10);
	}
	return 0;
}