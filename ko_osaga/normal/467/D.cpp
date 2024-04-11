#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

vector<string> v;
vector<string> mp;
vector<pair<string, string>> edg;

vector<int> gph[200005], rev[200005];

void norm(string &s){
	for(auto &i : s){
		if(i >= 'A' && i <= 'Z'){
			i -= 'A' - 'a';
		}
	}
}

int cnt[200005], len[200005];
int vis[200005], comp[200005];
pi opt[200005];

vector<int> dag[200005], dfn;

void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	for(auto &i : gph[x]) dfs(i);
	dfn.push_back(x);
}

void rdfs(int x, int p){
	if(vis[x]) return;
	vis[x] = 1;
	comp[x] = p;
	for(auto &i : rev[x]) rdfs(i,p);
}

int main(){
	int n;
	scanf("%d",&n);
	v.resize(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
		norm(v[i]);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		string s1, s2;
		cin >> s1 >> s2;
		norm(s1); norm(s2);
		mp.push_back(s1);
		mp.push_back(s2);
		edg.emplace_back(s1, s2);
	}
	sort(mp.begin(), mp.end());
	mp.resize(unique(mp.begin(), mp.end()) - mp.begin());
	for(auto &i : edg){
		int s = lower_bound(mp.begin(), mp.end(), i.first) - mp.begin();
		int e = lower_bound(mp.begin(), mp.end(), i.second) - mp.begin();
		gph[s].push_back(e);
		rev[e].push_back(s);
	}
	int p = 0;
	for(auto &i : mp){
		cnt[p] = count(i.begin(), i.end(), 'r');
		len[p] = i.size();
		p++;
	}
	p = 0;
	for(int i=0; i<mp.size(); i++){
		if(!vis[i]) dfs(i);
	}
	reverse(dfn.begin(), dfn.end());
	memset(vis, 0, sizeof(vis));
	for(auto &i : dfn){
		if(!vis[i]) rdfs(i, p++);
	}
	fill(opt, opt + p, pi(1e9, 1e9));
	for(int i=0; i<mp.size(); i++){
		opt[comp[i]] = min(opt[comp[i]], pi(cnt[i], len[i]));
		for(auto &j : gph[i]){
			dag[comp[i]].push_back(comp[j]);
		}
	}
	for(int i=p-1; i>=0; i--){
		for(auto &j : dag[i]){
			opt[i] = min(opt[i], opt[j]);
		}
	}
	lint ret1 = 0, ret2 = 0;
	for(auto &i : v){
		auto t = lower_bound(mp.begin(), mp.end(), i);
		if(t != mp.end() && *t == i){
			int u = t - mp.begin(); 
			pi t = opt[comp[u]];
			ret1 += t.first, ret2 += t.second;
		}
		else{
			ret1 += count(i.begin(), i.end(), 'r');
			ret2 += i.size();
		}
	}
	printf("%lld %lld",ret1, ret2);
}