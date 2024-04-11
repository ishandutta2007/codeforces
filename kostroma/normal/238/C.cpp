#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cassert>
using namespace std;
typedef long long li;
typedef pair<int, int> pi;
#define FILENAME "arrays"

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
void solve();

int main(){
#ifdef room210
	freopen("in.txt","r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<FILENAME<<endl;
#else
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif
	int t = 1;
	//cin>>t;
	while(t--)
		solve();
	return 0;
}

//#define int li

int n;
vector <pair<int,int> > g[4000];
bool used[4000];
int all_up = 0;
int up[4000];
int down[4000];
int mx[4000];

int best;

void dfs (int v, int how = 0, int p = -1){
	used[v] = true;
	if (p != -1){
		down[v] = down[p];
		up[v] = up[p];
		mx[v] = mx[p];
	}
	if (how == 1)
		down[v]++;
	if (how == -1)
		up[v]++;
	best = min(best, down[v] - up[v] - mx[v]);
	mx[v] = max(down[v] - up[v], mx[v]);
	//cout<<v<<' '<<up[v]<<' '<<down[v]<<endl;
	for (int i = 0; i < g[v].size(); ++i){
		int to = g[v][i].first;
		if (to == p)
			continue;
		if (g[v][i].second == -1)
			all_up++;
	}
	
	//cout<<mx[v]<<endl;
	for (int i = 0; i < g[v].size(); ++i){
		int to = g[v][i].first;
		if (to != p)
			dfs(to, g[v][i].second, v);
	}
}

void solve(){
	cin>>n;
	for (int i = 0; i < n - 1; ++i){
		int q, w;
		cin>>q>>w;
		--q; --w;
		g[q].push_back(mp(w, 1));
		g[w].push_back(mp(q, -1));
	}

	int ans = 1000000000;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			used[j] = false;
			mx[j] = -1000000000;
			up[j] = 0;
			down[j] = 0;
		}
		all_up = 0;
		best = 1000000000;
		mx[i] = 0;
		dfs(i);
		//cout<<all_up<<endl;
		ans = min(ans, all_up + best);
	}

	cout<<ans;
}