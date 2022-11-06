#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
const int N=15e4+10;
struct pt{ll p,t;};
vector<pt> a;
vector<pair<ll,pair<ld,ld> > > d;
int n,p[N],t[N];
ll T;
bool comp(pt a,pt b){
	if (a.t*b.p==a.p*b.t)return a.p<b.p;
	return a.t*b.p<a.p*b.t;
}
ld b[N],c[N];
int check(ld C){
	ll sum=0,las=0,li=0;
	d.clear();
	for (int i=0;i<n;i++){
		if (i>0&&a[i].t*a[i-1].p!=a[i-1].t*a[i].p){
			for (int j=li;j<=i;j++)
				c[j]=a[j].p*(1-C*((ld)sum/T));
			las=sum;
			li=i;				
		}
		sum+=a[i].t;
		b[i]=a[i].p*(1-C*((ld)(las+a[i].t)/T));
	}
	for (int j=li;j<n;j++)
		c[j]=a[j].p*(1-C*((ld)sum/T));
	for (int i=0;i<n;i++)
		d.push_back(make_pair(a[i].p,make_pair(c[i],b[i])));
	sort(d.begin(),d.end());
	ld lmx=0,rmx=0;
	for (int i=0;i<n;i++){
		if (d[i-1].first<d[i].first){
			lmx=rmx;
//			if (d[i-1].second>d[i].second)return 0;
		}
		rmx=max(rmx,d[i].second.second);
		if (lmx>d[i].second.first)return 0;
	}
	return 1;
	
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&p[i]);
	for (int i=1;i<=n;i++)scanf("%d",&t[i]),T+=t[i];
	for (int i=1;i<=n;i++)a.push_back((pt){p[i],t[i]});
	sort(a.begin(),a.end(),comp);
	ld ans=0;
	for (ld u=0.5;u>1e-12;u/=2){
		if (check(ans+u))ans+=u;
	}
	printf("%.9lf\n",ans);
}