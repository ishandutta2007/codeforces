/*
Drones since the dawn of time
Compelled to live your sheltered lives
Not once has anyone ever seen
Such a rise of pure hypocrisy
I'll instigate I'll free your mind
I'll show you what I've known all this time

God Hates Us All, God Hates Us All
You know it's true God hates this place
You know it's true he hates this race

Homicide-Suicide
Hate heals, you should try it sometime
Strive for Peace with acts of war
The beauty of death we all adore
I have no faith distracting me
I know why your prayers will never be answered

God Hates Us All; God Hates Us All
He Fuckin' hates me

Pessimist, Terrorist targeting the next mark
Global chaos feeding on hysteria
Cut throat, slit your wrist, shoot you in the back fair game
Drug abuse, self abuse searching for the next high
Sounds a lot like hell is spreading all the time
I'm waiting for the day the whole world fucking dies

I never said I wanted to be God's disciple
I'll never be the one to blindly follow

Man made virus infecting the world
Self-destruct human time bomb
What if there is no God would you think the fuckin' same
Wasting your life in a leap of blind faith
Wake the fuck up can't ignore what I say
I got my own philosophy

I hate everyone equally
You can't tear that out of me
No segregation -separation
Just me in my world of enemies

I never said I wanted to be God's disciple
I'll never be the one to blindly follow
I'll never be the one to bear the cross-disciple

I reject this fuckin' race
I despise this fuckin' place
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

int n1,n2,m,deg1[N],deg2[N],A[N],B[N],min_deg;

struct edge {
	int a, b, cap, flow;
};

const int MAXN = 300031;

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

bool bfs(){
	queue<int> qu;
	for (int i=0;i<=n;i++){
		d[i]=-1;
	}
	qu.push(s);
	d[s]=0;
	while (qu.size()){
		int v=qu.front();
		qu.pop();
		for (int i=0;i<g[v].size();i++){
			int id=g[v][i];
			int to=e[id].b;
			if (d[to]!=-1)
				continue;
			if (e[id].flow==e[id].cap)
				continue;
			d[to]=d[v]+1;
			qu.push(to);
		}
	}
	return (d[t]!=-1);
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
		for (int i=0;i<=n;i++){
			ptr[i]=0;
		}
		while (true){
			int pushed = dfs (s, 111);
			if (pushed==0)
				break;
			flow+=pushed;
		}
	}
	return flow;
}

int is_used[N],taken1[N],taken2[N];
vector<int> ans_list;

void add_some_edges(){
	for (int i=1;i<=n1;i++){
		add_edge(0,i,1);
	}
	for (int i=1;i<=n2;i++){
		add_edge(n1+i,t,1);
	}
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cout<<0<<endl;

	cin>>n1>>n2>>m;
	for (int i=1;i<=m;i++){
		cin>>A[i]>>B[i];
		deg1[A[i]]++;
		deg2[B[i]]++;
	}

	for (int i=1;i<=m;i++){
		add_edge(A[i],B[i]+n1,1);
	}

	min_deg=1e9;
	for (int i=1;i<=n1;i++){
		min_deg=min(min_deg,deg1[i]);
	}

	for (int i=1;i<=n2;i++){
		min_deg=min(min_deg,deg2[i]);
	}

	s=0;
	t=n1+n2+1;
	n=t+1;

	for (int iter=1;iter<=min_deg;iter++){
		add_some_edges();
		int here=dinic();
		//cout<<dinic()<<endl;
		/*for (int i=0;i<2*m;i++){
			cout<<e[i].a<<" "<<e[i].b<<" "<<e[i].cap<<" "<<e[i].flow<<endl;
		}
*/
		for (int i=1;i<=m;i++){
			is_used[i]=(e[i*2-2].flow>0);
		}
		for (int i=1;i<=n1;i++){
			taken1[i]=0;
		}
		for (int i=1;i<=n2;i++){
			taken2[i]=0;
		}

		for (int i=1;i<=m;i++){
			if (is_used[i])
			{
				taken1[A[i]]++;
				taken2[B[i]]++;
			}
		}

		ans_list.clear();

		for (int i=1;i<=m;i++){
			if (is_used[i]){
			}
			else
			{
				if (taken1[A[i]]<iter||taken2[B[i]]<iter){
					taken1[A[i]]++;
					taken2[B[i]]++;
					is_used[i]=1;
				}
			}
			if (is_used[i])
				ans_list.push_back(i);
		}
		cout<<ans_list.size();
		for (int i=0;i<ans_list.size();i++){
			cout<<" "<<ans_list[i];
		}
		cout<<endl;
	}
//	cin.get(); cin.get();
	return 0;
}