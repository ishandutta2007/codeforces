/*
All see light in oceans black
Go seek find the red seas fire
Blow ship by those sail blind
Choosing one loosing blood
You try exchanging
No I don't think so
Cannot escape me
No sound reason
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

int n,ar[N];
long long total_d[N],d_up[N],total_w[N],w_up[N];

vector<int> g[N];
int used[N];
int par[N];

void dfs(int v){
	used[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		par[to]=v;
		dfs(to);
		total_d[v]+=total_d[to];
		total_w[v]+=total_w[to];
		total_d[v]+=total_w[to];
	}
	total_w[v]+=ar[v];
}

void solve(int v){
	used[v]=1;

	if (v!=1){
		d_up[v]+=d_up[par[v]];
		w_up[v]+=w_up[par[v]];
		d_up[v]+=w_up[par[v]];

//		w_up[v]+=ar[par[v]];
//		d_up[v]+=ar[par[v]];

		long long d_minused=total_d[par[v]]-total_d[v]-total_w[v];
		long long w_minused=total_w[par[v]]-total_w[v];
		d_up[v]+=d_minused;
		w_up[v]+=w_minused;
		d_up[v]+=w_minused;
	}

	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		solve(to);
	}
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
	}
	for (int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1);

	for (int i=1;i<=n;i++){
		used[i]=0;
	}

	solve(1);

	long long ans=0;
	for (int i=1;i<=n;i++){
		ans=max(ans,total_d[i]+d_up[i]);
	//	cout<<i<<" "<<total_w[i]<<" "<<total_d[i]<<" "<<w_up[i]<<" "<<d_up[i]<<endl;
	}

	cout<<ans<<endl;
//    cin.get(); cin.get();
    return 0;
}