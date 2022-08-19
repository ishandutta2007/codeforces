#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;
const int mod = 1e9 + 7;

vector<int> sm[100005], lg[100005];
int n, m, vis[100005];

int getnext(int x, int p){
	if(x < p){
		auto l = lower_bound(lg[x].begin(), lg[x].end(), p);
		if(lg[x].begin() == l){
			if(sm[x].size()) return sm[x].back();
			return lg[x].back();
		}
		l--;
		return *l;
	}
	else{
		auto l = lower_bound(sm[x].begin(), sm[x].end(), p);
		if(l == sm[x].begin()){
			if(lg[x].size()) return lg[x].back();
			if(sm[x].back() > *l) return sm[x].back();
			assert(0);
		}
		l--;
		return *l;
	}
}

int rev[100005];
set<pi> s;

void dfs(int p, int x, vector<int> &v){
	if(s.find(pi(p, x)) != s.end()) return;
	s.insert(pi(p, x));
	v.push_back(x);
	int nxt = getnext(x, p);
	dfs(x, nxt, v);
}

vector<int> gph[100005];
int ans[100005];
int sz[100005], msz[100005];
vector<int> dfn;

void dfs2(int x, int p){
	sz[x] = 1;
	msz[x] = 0;
	dfn.push_back(x);
	for(auto &i : gph[x]){
		if(vis[i]) continue;
		if(i == p) continue;
		dfs2(i, x);
		sz[x] += sz[i];
		msz[x] = max(msz[x], sz[i]);
	}
}

int get_center(int x){
	dfn.clear();
	dfs2(x, -1);
	int cur = 1e9, ret = x;
	for(auto &i : dfn){
		msz[i] = max(msz[i], (int)dfn.size() - sz[i]);
		if(msz[i] < cur){
			ret = i;
			cur = msz[i];
		}
	}
	return ret;
}

void solve(int l){
	memset(vis, 0, sizeof(vis));
	queue<int> que, dep;
	que.push(1);
	dep.push(1);
	while(!que.empty()){
		int x = que.front();
		int d = dep.front();
		que.pop();
		dep.pop();
		x = get_center(x);
		vis[x] = 1;
		ans[x] = d;
		for(auto &i : gph[x]){
			if(!vis[i]){
				que.push(i);
				dep.push(d+1);
			}
		}
	}
	for(int i=1; i<=l; i++) printf("%d ", ans[i]);
}

int main(){
	scanf("%d %d",&n,&m);
	vector<pi> v;
	for(int i=0; i<m; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		if(s > e) swap(s, e);
		v.push_back(pi(s, e));
		v.push_back(pi(e, s));
		sm[e].push_back(s);
		lg[s].push_back(e);
	}
	for(int i=1; i<n; i++){
		v.push_back(pi(i, i+1));
		sm[i+1].push_back(i);
		lg[i].push_back(i+1);
	}
	v.push_back(pi(n, 1));
	sm[n].push_back(1);
	lg[1].push_back(n);
	for(int i=1; i<=n; i++){
		sort(sm[i].begin(), sm[i].end());
		sort(lg[i].begin(), lg[i].end());
	}
	vector<pair<vector<int> , int> > lis;
	map<pi, int> mp;
	vector<pi> edgs;
	for(auto &ii : v){
		if(s.find(ii) == s.end()){
			vector<int> v;
			dfs(ii.first, ii.second, v);
			for(int j=0; j<v.size(); j++){
			//	printf("%d ", v[j]);
				int nxt = v[(j+1)%v.size()];
				int cur = v[j];
				if(cur > nxt) swap(cur, nxt);
				if(mp.find(pi(cur, nxt)) != mp.end()){
					edgs.push_back({mp[pi(cur, nxt)], (int)lis.size()});
				}
				else mp[pi(cur, nxt)] = lis.size();
			}
		//	puts("");
			sort(v.begin(), v.end());
			reverse(v.begin(), v.end());
			lis.push_back({v, (int)lis.size()});
		}
	}
	sort(lis.begin(), lis.end());
	int idx = 0;
	for(auto &i : lis){
		idx++;
		rev[i.second] = idx;
	}
	for(auto &i : edgs){
		i.first = rev[i.first];
		i.second = rev[i.second];
		gph[i.first].push_back(i.second);
		gph[i.second].push_back(i.first);
	}
	solve(idx);
}