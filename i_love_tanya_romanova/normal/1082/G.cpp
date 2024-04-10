/*
I'm just a man and I am what I am, yeah
Nobody will ever change my ways
I don't need money and I don't need no lies, yeah
I only need to live for today
But I'd like to talk things over with you
I want to hear the things you say, today
Although you won't change me anyway, oh no way

I wish you'd come and see me, I'd like to hold you
I want to set my mind all free
You understand me woman, you give me time, yeah
But I don't need no sympathy
Still I wonder what it's like to be loved
Instead of hiding in myself
Nobody will change me anyway, no no way

Nobody's gonna change my world
That's something too unreal
Nobody will change the way I feel

So listen to me now, hear what I say, yeah
Please give me time and maybe love
If there's a God up there, well I hope he helps me
I need him now to set me free
'Cause it may be that it's over for me
If you don't hear the things that I say, today
Nobody will change me anyway, no no way

Nobody's gonna change my world
That's something too unreal
Nobody will change the way I feel
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

long long n,m,s,t;

struct edge {
	int a, b;
	long long cap, flow;
};

const int MAXN = N;

long long d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, long long cap) {
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

long long dfs (int v, long long flow) {
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

long long dinic() {
	long long flow = 0;
	for (;;) {
		if (!bfs())  break;
		for (int i=0;i<=n;i++)
			ptr[i]=0;
		while (true){
			long long pushed = dfs (s, 1000000000000000ll);
			if (pushed==0)
				break;
			flow += pushed;
		}
	}
	return flow;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	s=0;
	t=n+m+1;
	for (int i=1;i<=n;i++){
		int val;
		cin>>val;
		add_edge(s,i,val);
	}

	long long ttl=0;

	for (int i=1;i<=m;i++){
		int a,b;
		int val;
		cin>>a>>b>>val;
		add_edge(a,i+n,1e15);
		add_edge(b,i+n,1e15);
		add_edge(i+n,t,val);
		ttl+=val;
	}

	// some magic shit happens.
	n=t+1;
	long long here=dinic();

	cout<<ttl-here<<endl;

//	cin.get(); cin.get();
	return 0;
}