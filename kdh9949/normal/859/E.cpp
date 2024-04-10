#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int, int> elist[300001];
vector<pair<int, int> > e[300001];
vector<int> cpn[300001];
int n, dir[300001], tst;
bool vis[300001], iscyc[300001], valid[300001], found;
vector<int> cyc;
stack<pair<int, int> > st;
const ll mod = 1000000007;
ll ans = 1;

void cpnfill(int x){
	if(vis[x]) return;
	vis[x] = true;
	cpn[tst].push_back(x);
	for(int i = 0; i < e[x].size(); i++) cpnfill(e[x][i].first);
}

void findcyc(int x, int pe){
	if(found) return;
	if(vis[x]){
		int last = x;
		while(true){
			if(elist[st.top().second].first == last) dir[st.top().second] = 0;
			else dir[st.top().second] = 1;
			iscyc[last] = true;
			cyc.push_back(last);
			if(st.top().first == x) break;
			last = st.top().first;
			st.pop();
		}
		found = true;
		return;
	}
	vis[x] = true;
	for(int i = 0; i < e[x].size(); i++){
		if(e[x][i].second == pe) continue;
		st.push({x, e[x][i].second});
		findcyc(e[x][i].first, e[x][i].second);
		if(found) return;
		st.pop();
	}
}

void treedir(int x, int pe){
	if(iscyc[x]) return;
	if(vis[x]) return;
	vis[x] = true;
	if(elist[pe].first == x) dir[pe] = 1;
	else dir[pe] = 0;
	for(int i = 0; i < e[x].size(); i++){
		if(e[x][i].second == pe) continue;
		treedir(e[x][i].first, e[x][i].second);
	}
}

void center(int x){
	for(int i = 0; i < e[x].size(); i++) treedir(e[x][i].first, e[x][i].second);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int x, y; scanf("%d%d", &x, &y);
		elist[i] = {x, y};
		e[x].push_back({y, i});
		if(x != y) e[y].push_back({x, i});
	}
	for(int i = 1; i <= 300000; i++){
		if(!vis[i] && e[i].size()){
			tst++;
			cpnfill(i);
		}
	}
	fill(vis + 1, vis + 300001, false);
	for(int i = 1; i <= tst; i++){
		while(!st.empty()) st.pop();
		vector<int>().swap(cyc);
		found = false;
		findcyc(cpn[i][0], 0);
		for(int j = 0; j < cpn[i].size(); j++) vis[cpn[i][j]] = false;
		for(int j = 0; j < cyc.size(); j++){
			center(cyc[j]);
		}
		if(cyc.empty()){
			ans *= cpn[i].size();
			center(cpn[i][0]);
		}
		else{
			ans *= (1 + (cyc.size() > 1));
		}
		ans %= mod;
	}
	bool flag = true;
	for(int i = 1; i <= n; i++){
		int t;
		if(dir[i] == 1) t = elist[i].first;
		else t = elist[i].second;
		if(valid[t]){ flag = false; break; }
		valid[t] = true;
	}
	printf("%lld\n", (ll)flag * ans);
}