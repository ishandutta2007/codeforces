#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P(a) pair<a,int>
#define fi first
#define se second
#define pb push_back
#define db double
using namespace std;
const int N=1e5+5;
int k,n,m,t,b,a[N],ma[N],w[N],op[N];
vector<P(int)>d[N];
vector<P(db)>s;
bool cmp(P(int) a,P(int) b){return a.fi>b.fi;}
bool cmp2(P(db) a,P(db) b){return a.fi>b.fi;}
bool cmp3(P(db) a,P(db) b){return op[a.se]<op[b.se];}
int main(){
	ios::sync_with_stdio(false);
	cin>>k>>n>>m;
	fo(i,1,k)cin>>a[i];
	fo(i,1,n){
		cin>>t;
		op[i]=t;
		if(t==1){
			cin>>t>>b;
			if(b>ma[t])ma[t]=b,w[t]=i;
		}else
		if(t==2){
			cin>>t>>b;
			d[t].pb(P(int)(b,i));
		}else{
			cin>>t>>b;
			s.pb(P(db)(b,i));
		}
	}
	fo(i,1,k){
		if(ma[i]>a[i])d[i].pb(P(int)(ma[i]-a[i],w[i]));
		sort(d[i].begin(),d[i].end(),cmp);
		ll t=a[i];
		for(auto j:d[i]){
			s.pb(P(db)((db)j.fi/t+1,j.se));
			t+=j.fi;
		}
	}
	sort(s.begin(),s.end(),cmp2);
	if(s.size()>m)s.resize(m);
	sort(s.begin(),s.end(),cmp3);
	printf("%d\n",s.size());
	for(auto i:s)printf("%d ",i.se);
}