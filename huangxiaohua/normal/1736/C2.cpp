#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t;
ll a[200500],mn[200500],p[200500],sb,res[200500];
vector<pair<ll,ll> >q[200500];
ll s1[200500],s2[200500],it,t1,t2;

struct SB{
	ll f[400500],i,j,k;
	void add(ll x,ll y){
		//printf("nmsl%d %d\n",x,y);
		x+=200005;
		for(;x;x-=(-x&x)){f[x]+=y;}
	}
	ll get(ll x,ll y=0){
		x+=200005;
		for(;x<=200050;x+=(-x&x)){y+=f[x];}
		return y;
	}
}f1,f2;

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		a[i]=min(a[i],i)-i;
		mn[i]=min(a[i],mn[i-1]);
		p[i]=p[i-1]+mn[i];
	}
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>j>>k;
		k=min(j,k)-j;
		q[j].push_back({i,k});
		res[i]=n*(n+1)/2;
	}
	s2[0]=n+1;
	for(i=n;i>=1;i--){
		for(auto [id,w]:q[i]){
			w=min(w,mn[i-1]);
			t1=f1.get(w)+1;
			t2=f2.get(w);
			res[id]+=p[i-1]+f2.get(-n)-t2+t1*w;
		}
		while(it&&s1[it]>=a[i]){
			f1.add(s1[it],-(s2[it-1]-s2[it]));
			f2.add(s1[it],-(s2[it-1]-s2[it])*s1[it]);
			it--;
		}
		s1[++it]=a[i];
		s2[it]=i;
		f1.add(s1[it],(s2[it-1]-s2[it]));
		f2.add(s1[it],(s2[it-1]-s2[it])*s1[it]);
		//printf("NMSL%d %d %d\n",i,f1.get(-n),f2.get(-n));
	}
	for(i=1;i<=t;i++){
		cout<<res[i]<<'\n';
	}
}