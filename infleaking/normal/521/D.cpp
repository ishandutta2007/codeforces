#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
vector<pair<int,int> > a[N],b[N];
int p[N],mx[N],k,n,m,id[N];
struct pi{ll x,y,i,z,ty;};
bool operator < (pi a,pi b){
	if (a.z!=b.z)return a.z>b.z;
	return a.x*b.y>a.y*b.x;
}
vector<pi> h;
pi make(ll x,ll y,ll i,ll ty){
	return (pi){x%y,y,i,x/y,ty};
}
bool comp(pi a,pi b){
	return a.ty<b.ty;
}
int main(){
	cin>>n>>k>>m;
	for (int i=1;i<=n;i++)scanf("%d",&p[i]);
	for (int i=1;i<=k;i++){
		int ty,x,v;
		scanf("%d%d%d",&ty,&x,&v);
		if (ty==1){
			mx[x]=max(mx[x],v);
			if (mx[x]==v)id[x]=i;
		}
		if (ty==2)
			a[x].push_back(make_pair(v,i));
		if (ty==3)
			b[x].push_back(make_pair(v,i));
	}
	for (int i=1;i<=n;i++){
		if (mx[i]>p[i])
			a[i].push_back(make_pair(mx[i]-p[i],id[i]));
		sort(a[i].begin(),a[i].end());
		reverse(a[i].begin(),a[i].end());
		ll sum=p[i];
		int tag=0;
		for (auto x:a[i]){
			int z1=(x.first==mx[i]-p[i])&&(!tag);
			tag+=z1;
			h.push_back(make(sum+x.first,sum,x.second,2-z1));
			sum+=x.first;
		}
		for (auto x:b[i])
			h.push_back(make(x.first,1,x.second,3));
	}
	sort(h.begin(),h.end());
	while (h.size()>m)h.pop_back();
	sort(h.begin(),h.end(),comp);
	cout<<h.size()<<endl;
	for (auto i:h)printf("%lld ",i.i);
}