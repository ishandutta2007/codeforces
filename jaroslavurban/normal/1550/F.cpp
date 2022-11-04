#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000100;
int nxt[N],prv[N],a[N],idx[N],vis[N],when[N][2],disc[N][2];
int n,t,s,d;

int getnxt(int u){
	if(u<0)return getnxt(0);
	if(u>=N)return 1e9;
	return ~idx[u]&&!vis[u]?u:nxt[u]=getnxt(nxt[u]);
}

int getprv(int u){
	if(u<0)return -1;
	if(u>=N)return getprv(N-1);
	return ~idx[u]&&!vis[u]?u:prv[u]=getprv(prv[u]);
}

void ProGamerMove(){
	memset(idx,-1,sizeof(idx));
	cin>>n>>t>>s>>d;--s;
	for(int i=0;i<n;++i){
		cin>>a[i];
		idx[a[i]]=i;
	}
	for(int i=0;i<N;++i)when[i][0]=when[i][1]=INT_MAX;
	prv[0]=-1;
	for(int i=1;i<N;++i)if(~idx[i-1])prv[i]=i-1;
	else prv[i]=prv[i-1];
	nxt[N-1]=1e9;
	for(int i=N-2;i>=0;--i)if(~idx[i+1])nxt[i]=i+1;
	else nxt[i]=nxt[i+1];
	vector<tuple<int,int,int>>qs;
	for(int i=0;i<t;++i){
		int ai,kk;cin>>ai>>kk;--ai;
		qs.push_back({kk,ai,i});
	}
	sort(qs.rbegin(),qs.rend()); // k, a
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q; // when, u
	q.push({0,a[s]});
	int ck=0;
	function<void(int)>upd=[&](int u){
		int v=getnxt(u-d-ck);
//		cerr<<u-d-ck-1<<" "<<v<<endl;
		if(v<N){
			int nk=ck+v-(u-d+ck);
			if(when[v][0]>nk){
//				cerr<<u<<" "<<v<<" "<<ck<<" "<<d<<" "<<nk<<endl;
//				cerr<<u<<" 1 inviting "<<v<<" at "<<nk<<endl;
				when[v][0]=nk;
				disc[v][0]=u;
				q.push({nk,v});
			}
		}
		v=getnxt(u+d-ck);
		if(v<N){
			int nk=ck+v-(u+d+ck);
			if(when[v][0]>nk){
//				cerr<<u<<" 2 inviting "<<v<<" at "<<nk<<endl;
				when[v][0]=nk;
				disc[v][0]=u;
				q.push({nk,v});
			}
		}
		v=getprv(u-d+ck);
		if(~v){
			int nk=ck+(u-d-ck)-v;
			if(when[v][1]>nk){
			//cerr<<u<<" 3 inviting "<<v<<" at "<<nk<<endl;
				when[v][1]=nk;
				disc[v][1]=u;
				q.push({nk,v});
			}
		}
		v=getprv(u+d+ck);
		if(~v){
			int nk=ck+(u+d-ck)-v;
			if(when[v][1]>nk){
//				cerr<<u<<" 4 inviting "<<v<<" at "<<nk<<endl;
				when[v][1]=nk;
				disc[v][1]=u;
				q.push({nk,v});
			}
		}
	};
	vector<int>res(t);
	while(q.size()){
		auto[dist,u]=q.top();q.pop();
		if(vis[u])continue;
		if(dist>ck){
			while(qs.size()&&get<0>(qs.back())<dist){
				auto[kk,ai,qi]=qs.back();qs.pop_back();
				if(vis[a[ai]])res[qi]=1;
			}
			if(qs.empty())break;
		}
		ck=max(ck,dist);
//		cerr<<"getting to "<<u<<" at "<<ck<<", "<<dist<<endl;
		vis[u]=true;
		upd(u);
		for(int i=0;i<2;++i)if(when[u][i]!=INT_MAX)upd(disc[u][i]);
	}
	while(qs.size()){
		auto[kk,ai,qi]=qs.back();qs.pop_back();
		if(vis[a[ai]])res[qi]=1;
	}
	for(auto r:res)if(r)cout<<"Yes\n";
	else cout<<"No\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}