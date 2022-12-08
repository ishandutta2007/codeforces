#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int Case;
namespace G{
	int n,m;
	int hed[N],to[N],nxt[N],cnt;
	int deg[N],u[N],v[N],d[N],vis[N],par[N],del[N];
	bool vis2[N];
	inline void adde(int u,int v){
		del[cnt+1]=0;++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
	}
	inline void read(){
		cnt=1;cin >> n >> m;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u[i],&v[i]);
			deg[u[i]]++, deg[v[i]]++;
		}
	}
	inline void output(vector<int> del){
		vector<bool> ans(n+1,0);
		if((int)del.size()==n){
			puts("No");
		}else{
			puts("Yes");
			printf("%d\n",n-(int)del.size());
			for(size_t i=0;i<del.size();i++)ans[del[i]]=1;
			for(int i=1;i<=n;i++){
				if(!ans[i])printf("%d ",i);
			}puts("");
		}
	}
	vector<int> ret;
	int rt, Rt[N], dep[N] ;
	inline void dfs(int x,int pre){
		dep[x] = dep[pre]+1;Rt[x] = rt;par[x] = pre;
		vis[x] = 1;
		// cout << x << endl;
		int T = 0;
		for(int i=hed[x];i;i=nxt[i]){
			int v=to[i];if(v==pre)continue;
			if(vis[v]){
				if(dep[v] < dep[x]){
					if(!ret.size()){
						if(!T)T=v;
						else if(dep[v] > dep[T])T=v;
					}
				}
			}
		}
		if(T){
			int cur = x;
			// cout << cur << " :";
			ret.push_back(cur);
			while(cur!=T){
				cur = par[cur];
				// cout << cur << " :";
				ret.push_back(cur);
			}
		}
		for(int i=hed[x];i;i=nxt[i]){
			int v=to[i];if(!vis[v]){
				dfs(v,x);
			}
		}
	}
	vector<int> getpath(int x,int y){
		bool tag = 0;
		if(dep[x] < dep[y])swap(x,y),tag = 1;
		vector<int> a,b;
		while(dep[x] > dep[y]){
			a.push_back(x);
			// cout << x << "?" << endl;
			x = par[x];
		}
		while(x!=y){
			a.push_back(x),b.push_back(y);
			x=par[x],  y = par[y];
		}
		a.push_back(x);
		reverse(b.begin(),b.end());
		for(size_t i=0;i<b.size();i++)a.push_back(b[i]);
		if(tag)reverse(a.begin(),a.end());
		return a;
	}
	typedef pair<int,int> pi;
	bool sx[N],sy[N];
	void Answer(int x,vector<int> path,int y){
		for(int i=1;i<=n;i++)sx[i] = sy[i] = 0;
		for(int i=1;i<=m;i++){
			if(u[i]==x)sx[v[i]]=1;
			if(u[i]==y)sy[v[i]]=1;
		}
		for(int i=0;i<(int)path.size();i++)if(sy[path[i]]){
			path.resize(i+1);
			break;
		}
		vector<int> s;
		for(int i=(int)path.size()-1;~i;i--){
			s.push_back(path[i]);
			if(sx[path[i]])break;
		}
		s.push_back(x),s.push_back(y);
		output(s);
	}
	vector<pi> s[N];
	vector<int> RRR;
	int delnode[N];
	inline int DF(int x,int pre){
		if(sx[x]){RRR.push_back(x);return x;}
		int T = 0;
		for(int i=hed[x];i;i=nxt[i])if(to[i]!=pre&&!delnode[to[i]]){
			int ret = DF(to[i],x);
			if(ret > 0){T = 1;break;}
		}
		if(T)RRR.push_back(x);
		return T;
	}
	void Sol(int nd1,int cnt0){
		// cout << "Sol" << nd1 << endl;
		for(int i=1;i<=n;i++)sx[i] = 0;
		for(int i=1;i<=m;i++)if(u[i]==cnt0)sx[v[i]]=1;
		RRR.push_back(nd1);
		int R = 2;if(sx[nd1])R--;
		for(int i=hed[nd1];i;i=nxt[i]){
			int v = to[i];
			if(DF(v,nd1))R--;
			if(!R)break;
		}
		// output(RRR);
	}
	inline void solve(){
		int BLOCKS = 0;
		// cerr << "step" << endl;
		for(int i=1;i<=n;i++){if(deg[i]%3 == 0){output(vector<int> (1,i));return ;}}
		for(int i=1;i<=m;i++){
			if(deg[u[i]]%3==1 && deg[v[i]]%3==1){
				vector<int> r(2,0);r[0] = u[i], r[1] = v[i];
				output(r);
				return ;
			}
			if(deg[u[i]]%3==2 && deg[v[i]]%3==2){
				adde(u[i],v[i]), adde(v[i],u[i]);
				d[u[i]]++, d[v[i]]++;
			}
		}
		
		// cerr << "step" << endl;
		ret.clear();
		for(int i=1;i<=n;i++)if(deg[i]%3 == 2 && !vis[i]){
			// cout << i << "dfs" << endl;
			BLOCKS++;
			rt = i;dfs(i,0);
		}
		if(ret.size()){output(ret);return ;}
		// cerr << "step" << endl;
		vector<int> cnt1;
		for(int i=1;i<=n;i++)if(deg[i]%3==1)cnt1.push_back(i);
		// if(Case == 186){
		// 	cout << -(int)cnt1.size() << endl;
		// }
		if((int)cnt1.size()>1){
			for(int i=1;i<=m;i++){
				if(deg[u[i]]%3==2 && deg[v[i]]%3==1)swap(u[i],v[i]);
				if(deg[u[i]]%3==1 && deg[v[i]]%3==2){
					int r = Rt[v[i]];
					s[r].push_back(pi(u[i],v[i]));
				}
			}
			for(int i=1;i<=n;i++)if(s[i].size()){
				sort(s[i].begin(),s[i].end());
				for(int j=1;j<(int)s[i].size();j++){
					if(s[i][j].first!=s[i][j-1].first){
						vector<int> ret = getpath(s[i][j].second, s[i][j-1].second);
						// cout << s[i][j].second << " " << s[i][j-1].second << endl;
						// for(size_t k=0;k<ret.size();k++)cout << ret[k] << " ";puts("");
						Answer(s[i][j].first, ret, s[i][j-1].first);
						return ;
					}
				}
			}
		}else{
			RRR.clear();
			// cout << BLOCKS << "??" << endl;
			for(int i=1;i<=m;i++)
				if(deg[u[i]]%3==2 && deg[v[i]]%3==1)swap(u[i],v[i]);
			for(int i=1;i<=n;i++)sx[i] = 0, delnode[i] = 0, vis2[i] = 0;
			for(int i=1;i<=m;i++)if(u[i]==cnt1[0])sx[v[i]]=1;
				RRR.push_back(cnt1[0]);
				for(int i=1;i<=n;i++)vis2[i] = 0;
				int T = 2;
				for(int i=1;i<=n;i++)if(deg[i]%3==2){
					
					if(!vis2[Rt[i]]){
						vis2[Rt[i]]=1,Sol(i,cnt1[0]),T--;
					}
					if(T==0){
						break;
					}
				}
				output(RRR);			
			return ;
		}
	}
	void clear(){
		for(int i=1;i<=n;i++)dep[i] = Rt[i] = par[i] = vis[i] = hed[i] = 0, d[i] = deg[i] = 0;cnt=1;
		for(int i=1;i<=n;i++)s[i].clear();
	}
}

int main()
{
	int T;cin >> T;
	while(T--){
		Case++;
		G::read();
		G::solve();
		G::clear();
	}
}