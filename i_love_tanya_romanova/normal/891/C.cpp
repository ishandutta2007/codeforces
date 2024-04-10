/*
And then I found out how hard
It is to really change, even hell
Can get comfy once you've settled in.
I just wanted the numb inside me to leave.
No matter how fucked you get,
The sun will return and you come back down!
The funny thing is all I ever wanted i already had..
There's glimpses of heaven in every day!!
In the friends that I have, the music I made,
The love that I feel, I just had to start again..

The days are a death wish
A witch hunt for an exit
I am powerless...

The fragile, the broken
Sit in circles and stay unspoken
We are powerless...

Because we all walk alone on an empty staircase
Idle in the halls and nameless faces
I am powerless...

Everybody wants to go to Heaven
But nobody wants to die
I can fear death no longer
I've died a thousand times

A wasteful universe
And we don't know our soul was
Emptiness inside our heads
But no one dares to dwell...

Throw me to the flames
Watch me burn!
Set my world ablaze
Watch me burn!

How are we on a scale of one to ten?
You can tell me, what do you say?
Do you wanna talk about it?
How does that make you feel?

Have you ever took a blade to your wrists
Have you've been skipping meals
We're gonna try something new today
How does that make you feel?

Hold me close, don't let go
Watch me
Hold me close, don't let go
Watch me
Hold me close, don't let go
Watch me
In this hospital for souls

Hold me close, don't let go
Watch me
Hold me close, don't let go
Watch me
Hold me close, don't let go
Watch me
In this hospital for souls

Hold me close, don't let go
Watch me
Hold me close, don't let go
Watch me
Hold me close, don't let go
Watch me
In this hospital for souls

Hold me close, don't let go
Watch me burn...
Hold me close, tell me "go"
Watch me burn...
Hold me close, don't let go
Watch me burn...
In this hospital for souls

Hold me close, don't let go
Watch me burn...
Hold me close, tell me "go"
Watch me burn...
Hold me close, don't let go
Watch me burn...
In this hospital for souls
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

const int N = 500031;

int n,m,u[N],v[N],d[N];
vector<int> entries[N];
int tests;
int test_sz[N];

vector<pair<int,int> > e_list[N];
vector<int> interesting[N];
int w[N],h[N];
int SHIT;

int get(int x){
	if (x==w[x])
		return x;
	return get(w[x]);
}

int is_bad[N];

vector<pair<int,int> > changes;

void merge(int a,int b){
	a=get(a);
	b=get(b);
	if (a==b){
		SHIT=1;
		return ;
	}
	if (h[a]>h[b])
		swap(a,b);
	changes.push_back(make_pair(0,a));
	w[a]=b;
	if (h[a]==h[b]){
		changes.push_back(make_pair(1,b));
		h[b]++;
	}
}

void run_merge(int e_id){
	int a=u[e_id];
	int b=v[e_id];
	merge(a,b);
}

void unroll(){
	pair<int,int> p=changes.back();
	if (p.first==0) // w[a]=b
		w[p.second]=p.second;
	else // h[b]++
		h[p.second]--;
	changes.pop_back();
}


int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=m;i++){
		scanf("%d",&u[i]);
		scanf("%d",&v[i]);
		scanf("%d",&d[i]);
		entries[d[i]].push_back(i);
	}

	cin>>tests;
	for (int test=1;test<=tests;test++){
		scanf("%d",&test_sz[test]);
		for (int j=1;j<=test_sz[test];j++){
			int id;
			scanf("%d",&id);
			e_list[test].push_back(make_pair(d[id],id));
			interesting[d[id]].push_back(test);
		}
	}

	for (int i=1;i<=tests;i++){
		sort(e_list[i].begin(),e_list[i].end());
	}

	for (int i=1;i<=n;i++){
		w[i]=i;
		h[i]=1;
	}

	for (int i=1;i<=500000;i++){
		sort(interesting[i].begin(),interesting[i].end());
		for (int j=0;j<interesting[i].size();j++){
			if (j>0&&interesting[i][j]==interesting[i][j-1])
				continue;
			int id=interesting[i][j];
			changes.clear();
			SHIT=0;
			int ps=lower_bound(e_list[id].begin(),e_list[id].end(),make_pair(i,-1))-e_list[id].begin();
			for (int j=ps;j<e_list[id].size();j++){
				if (e_list[id][j].first!=i)
					break;
				int e_id=e_list[id][j].second;
				run_merge(e_id);
			}
			while (changes.size())
				unroll();
			if (SHIT)
				is_bad[id]=1;
		}
		for (int j=0;j<entries[i].size();j++){
			int e_id=entries[i][j];
			run_merge(e_id);
		}
	}

	for (int i=1;i<=tests;i++){
		if (is_bad[i])
			puts("NO");
		else
			puts("YES");
	}

	cin.get(); cin.get();
	return 0;
}