#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
#define ll long long
using namespace std;
const int mod=1e9+7;
const int M=1e5+9;
int n,m,seed,vmax;
int a[M];
map<int,ll>mp;
pair<ll,int> p[M];
int rnd(){
	int t=seed;
	seed=(seed*7ll+13)%mod;
	return t;
}
void split(int x){
	mp[x]=mp.lower_bound(x)->se;
}
int kpow(int x,int y,int z){
	int rex=1;
    for(;y;y>>=1,x=1ll*x*x%z)if(y&1)rex=1ll*rex*x%z;
    return rex;
}
int main(){
	cin>>n>>m>>seed>>vmax;
	for(int i=1;i<=n;++i){
		a[i]=rnd()%vmax+1;
	}
	for(int i=n;i>=1;--i){
		if(i==n||a[i]!=a[i+1])mp[i]=a[i];
	}
	mp[0]=0;
	for(int i=1;i<=m;++i){
		int o,l,r,x,y;
		o=rnd()%4+1;
		l=rnd()%n+1;
		r=rnd()%n+1;
		if(l>r)swap(l,r);
		if(o==3){
			x=rnd()%(r-l+1)+1;
		}
		else x=rnd()%vmax+1;
		if(o==4)y=rnd()%vmax+1;

		split(l-1);
		split(r);
		if(o==1){
			for(auto it=mp.lower_bound(l);it!=mp.end()&&it->first<=r;it=next(it))it->se+=x;
		}
		if(o==2){
			for(auto it=mp.lower_bound(l);it!=mp.end()&&it->first<=r;it=mp.erase(it));
			mp[r]=x;
		}
		if(o==3){
			int num=0;
			for(auto it=mp.lower_bound(l);it!=mp.end()&&it->first<=r;it=next(it)){
				p[++num]=make_pair(it->se,it->fi-prev(it)->fi);
			}
			sort(p+1,p+num+1);
			for(int j=1;j<=num;++j){
				if(x<=p[j].se){
					cout<<p[j].fi<<"\n";
					break;
				}
				else x-=p[j].se;
			}
		}
		if(o==4){
			int num=0;
			for(auto it=mp.lower_bound(l);it!=mp.end()&&it->first<=r;it=next(it)){
				p[++num]=make_pair(it->se,it->fi-prev(it)->fi);
			}
			int ans=0;
			for(int j=1;j<=num;++j){
				ans=(ans+1ll*kpow(p[j].fi%y,x,y)*p[j].se%y)%y;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/*
23323
1
4
*/