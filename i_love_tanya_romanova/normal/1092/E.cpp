/*
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

int n,m;
vector<int> g[N];
int used[N];
vector<int> cur_comp;

void dfs(int v){
	used[v]=1;
	cur_comp.push_back(v);
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		dfs(to);
	}
}

vector<pair<int,vector<int> > > comps;
vector<pair<int,int> > ans;
int answ;

int get_mid(vector<int> v){
	return v[v.size()/2];
}

int par[N];

void trace(int v){
	if (used[v]==0)
		used[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		used[to]=used[v]+1;
		par[to]=v;
		trace(to);
	}
}

vector<int> get_diam(){
	for (int i=0;i<cur_comp.size();i++){
		int id=cur_comp[i];
		used[id]=0;
	}
	trace(cur_comp[0]);
	int root=cur_comp[0];
	for (int i=0;i<cur_comp.size();i++){
		if (used[cur_comp[i]]>used[root])
			root=cur_comp[i];
	}
	for (int i=0;i<cur_comp.size();i++){
		used[cur_comp[i]]=0;
	}
	trace(root);
	int root2=cur_comp[0];
	for (int i=0;i<cur_comp.size();i++){
		if (used[cur_comp[i]]>used[root2])
			root2=cur_comp[i];
	}
	vector<int> ret;
	while (root2!=root){
		ret.push_back(root2);
		root2=par[root2];
	}
	ret.push_back(root);
	return ret;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	while (true){
		comps.clear();
		for (int i=1;i<=n;i++){
			used[i]=0;
		}

		for (int i=1;i<=n;i++){
			if (used[i])
				continue;
			cur_comp.clear();
			dfs(i);
			comps.push_back(make_pair(get_diam().size()-1,get_diam()));
		}
		sort(comps.begin(),comps.end());
		answ=comps[0].first;
		if (comps.size()==1)
			break;
		ans.push_back(make_pair(get_mid(comps[comps.size()-1].second),get_mid(comps[comps.size()-2].second)));
		pair<int,int> new_edge=ans.back();
		g[new_edge.first].push_back(new_edge.second);
		g[new_edge.second].push_back(new_edge.first);
	}

	cout<<answ<<endl;
	for (int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}

//    cin.get(); cin.get();
    return 0;
}