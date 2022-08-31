/*
Trading life for life
It all must fall
It must end with us
It must end with me

Insinuations of what might be
Fight through depriviation
There will be no sleep

Heed my cry

Because of greed and hatred
To dust we return
They will see the strength in our numbers
Only then will the self-righteous learn

Insinuations of what might be

To the masses, we mean nothing
But it starts in the hearts of the few
Witness the birth of a people
Unite. Renew.

There is no forever, just today
Don't let your sacrifice waste away

Through change and purity, turn the shadows to light
Buried beneath the ashes is a passion for life

There is no forever, just today
Don't let your sacrifice waste away

Let there be no more of this bloodshed

Heed my cry.

There is no forever, just today
Don't let your sacrifice waste away
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1200031;

int ts;
long long S[N];
int m,x[N],y[N];

const int MAXN = 400031;

map<pair<int,int>,int > maps;
long long res;


struct edge {
	int a, b, cap, flow;
};

int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}

bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (true){
			int pushed=dfs(s,1000000000);
			if (pushed==0)
				break;
			flow += pushed;
		}
	}
	return flow;
}

int ans[N];

int bal[N];
int used[N];
int in_tree[N];

void dfs(int v){
	bal[v]=S[v];
	used[v]=1;
	for (int i=0;i<g[v].size();i++){
		int id=g[v][i];
		int to=x[id]+y[id]-v;
		if (used[to])
			continue;
		if (to==y[id])
			in_tree[id]=1;
		else
			in_tree[id]=-1;
		dfs(to);
		bal[v]+=bal[to];
	}
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>S[i];
		ts+=S[i];
	}

	if (ts!=0){
		cout<<"Impossible"<<endl;
		return 0;
	}

	cout<<"Possible"<<endl;

	cin>>m;

	for (int i=1;i<=m;i++){
		cin>>x[i]>>y[i];
		g[x[i]].push_back(i);
		g[y[i]].push_back(i);
	}

	dfs(1);

	for (int i=1;i<=m;i++){
		if (in_tree[i]==0){
			cout<<0<<endl;
			continue;
		}
		if (in_tree[i]==1)
			cout<<bal[y[i]]<<endl;
		else
			cout<<-bal[x[i]]<<endl;
	}

//	cin.get(); cin.get();
	return 0;
}