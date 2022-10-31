#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,t,fa[1005000],a[1005000],l,r,sz[1005000];
bool y[1005000],vis[1005000];
vector<int> v[1005000],cl[1005000];
vector<tuple<int,int,int,int> > st;
ll res,sb;
map<int,vector<pair<int,int> > >q;

int find0(int x){return (fa[x]==x)?x:fa[x]=find0(fa[x]);}
int find(int x){while(x!=fa[x]){x=fa[x];}return fa[x];}

void hb(int x,int y){
	x=find(x);y=find(y);
	if(sz[x]>sz[y]){
		st.push_back({y,fa[y],x,sz[x]});
		fa[y]=x;sz[x]+=sz[y];
	}
	else{
		st.push_back({x,fa[x],y,sz[y]});
		fa[x]=y;sz[y]+=sz[x];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	for(i=1;i<=1000005;i++)fa[i]=i,sz[i]=1;
	cin>>n>>m>>t;
	for(i=1;i<=n;i++){
		cin>>a[i];
		cl[a[i]].push_back(i);
	}
	for(i=1;i<=m;i++){
		cin>>l>>r;
		v[l].push_back(r);
		v[r].push_back(l);
	}
	for(i=1;i<=t;i++){
		for(auto j:cl[i]){
			for(auto k:v[j]){
				if(a[k]==a[j]){
					sz[find0(k*2+0)]+=sz[find0(j*2+1)];
					sz[find0(k*2+1)]+=sz[find0(j*2+0)];
					fa[find0(j*2+1)]=find0(k*2+0);
					fa[find0(j*2+0)]=find0(k*2+1);
				}
			}
		}
		for(auto j:cl[i]){
			if(find0(j*2)==find0(j*2+1))goto aaa;
		}
		sb++;y[i]=1;
		aaa:;
	}
	for(i=1;i<=n;i++)find0(i*2+0),find0(i*2+1);
	for(i=1;i<=t;i++){
		q.clear();
		if(!y[i])continue;
		res+=sb-1;
		for(auto j:cl[i]){
			for(auto k:v[j]){
				if(!y[a[k]]||a[k]<=i)continue;
				q[a[k]].push_back({j,k});
			}
		}
		for(auto &[id,v]:q){
			res-=2;
			for(auto [x,y]:v){
				hb(x*2+1,y*2+0);
				hb(x*2+0,y*2+1);
			}
			for(auto [x,y]:v){
				if(find(x*2+0)==find(x*2+1))goto bbb;
				if(find(y*2+0)==find(y*2+1))goto bbb;
			}
			res+=2;
			bbb:;
			reverse(st.begin(),st.end());
			for(auto [a,b,c,d]:st){
				fa[a]=b;sz[c]=d;
			}
			st.clear();
		}
	}
	cout<<res/2;
}