#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define Pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define sz(x) int(x.size())
#define rk(x) (lower_bound(pos.begin(),pos.end(),x)-pos.begin())
using namespace std;
const int N=1e5+5;
int n,m,x,y,d,ds;
int fa[N],df[N],las[N],dy2[N];
ll dep[N],can;
vector<P>e[N];
vector<Pll>ck;
vector<ll>pos;
vector<int>nd[N*40];
priority_queue<int,vector<int>,greater<int> >A;
unordered_map<int,int>dy;

set<int>hv[N],dd[N];
void dfs(int x){
	df[++ds]=x;
	bool fir=0;
	for(P i:e[x])if(i.fi!=fa[x]){
		if(!fir){
			fir=1;
			las[x]=i.fi;
		}
		fa[i.fi]=x;
		dep[i.fi]=dep[x]+i.se;
		dfs(i.fi);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	fo(i,2,n)cin>>x>>y>>d,e[x].pb(P(y,d)),e[y].pb(P(x,d));
	fo(i,1,n)reverse(e[i].begin(),e[i].end());
	dfs(1);
	fo(i,1,m)cin>>x>>y,hv[x].insert(y);
	fd(i,1,n){
		x=df[i];
		ds=0;
		for(P i:e[x])if(i.fi!=fa[x]&&hv[i.fi].size())
			dy2[i.fi]=++ds,swap(dd[ds],hv[i.fi]);
		if(ds){
			int mxp=0;
			fo(i,1,ds)if(dd[i].size()>dd[mxp].size())mxp=i;
			vector<ll>all;
			dy.clear();
			dy[-1]=dy2[las[x]];
			all.pb(-1);
			int mn=*dd[mxp].begin(),mx=*--dd[mxp].end();
			dy[mn]=mxp;
			all.pb(mn);
			fo(i,1,ds)if(i!=mxp){
				for(int j:dd[i]){
					dy[j]=i;
					all.pb(j);
					auto l=dd[mxp].lower_bound(j);
					if(j<mx){
						dy[*l]=mxp;
						all.pb(*l);
					}
					if(j>mn){
						--l;
						dy[*l]=mxp;
						all.pb(*l);
					}
				}
			}
			if(all.size()){
				sort(all.begin(),all.end());
				all.erase(unique(all.begin(),all.end()),all.end());
				int la=0;
				for(int i:all){
					if(la&&dy[la]!=dy[i])
						ck.pb(Pll(la==-1?0:dep[x]+la,dep[x]+i));
					la=i;
				}
			}
			
			if(hv[x].size()<dd[mxp].size())swap(hv[x],dd[mxp]);
			fo(i,1,ds)
				hv[x].insert(dd[i].begin(),dd[i].end());
			fo(i,1,ds)dd[i].clear();
		}
	}
	for(auto i:ck)pos.pb(i.fi),pos.pb(i.se);
	sort(pos.begin(),pos.end());
	pos.erase(unique(pos.begin(),pos.end()),pos.end());
	can=-1;
	for(auto i:ck){
		//printf("%d %d\n",i.fi,i.se);
		x=rk(i.fi);y=rk(i.se);
		nd[x].pb(y);
	}
	fo(i,0,sz(pos)-1){
		if(!A.empty()&&A.top()==i){
			can=pos[i];
			break;
		}
		for(int j:nd[i])A.push(j);
		if(i==sz(pos)-1)break;
		fo(j,1,pos[i+1]-pos[i]){
			if(A.empty())break;
			A.pop();
		}
	}
	if(can==-1)printf("-1 %d\n",ck.size());else{
		int cnt=0;
		for(auto i:ck)cnt+=i.se<can;
		printf("%lld %d\n",can,cnt);
	}
}