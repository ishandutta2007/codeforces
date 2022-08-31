/*
Hey (hey)
I'm your life
I'm the one who takes you there
Hey (hey)
I'm your life
I'm the one who cares
They (they)
They betray
I'm your only true friend now
They (they)
They'll betray
I'm forever there

I'm your dream, make you real
I'm your eyes when you must steal
I'm your pain when you can't feel
Sad but true

I'm your dream, mind astray
I'm your eyes while you're away
I'm your pain while you repay
You know it's sad but true
Sad but true

You (you)
You're my mask
You're my cover, my shelter
You (you)
You're my mask
You're the one who's blamed
Do (do)
Do my work
Do my dirty work, scapegoat
Do (do)
Do my deeds
For you're the one who's shamed

I'm your dream, make you real
I'm your eyes when you must steal
I'm your pain when you can't feel
Sad but true

I'm your dream, mind astray
I'm your eyes while you're away
I'm your pain while you repay
You know it's sad but true
Sad but true

I'm your dream
I'm your eyes
I'm your pain

I'm your dream (I'm your dream)
I'm your eyes (I'm your eyes)
I'm your pain (I'm your pain)
You know it's sad but true

Hate (hate)
I'm your hate
I'm your hate when you want love
Pay (pay)
Pay the price
Pay, for nothing's fair

Hey (hey)
I'm your life
I'm the one who took you there
Hey (hey)
I'm your life
And I no longer care

I'm your dream, make you real
I'm your eyes when you must steal
I'm your pain when you can't feel
Sad but true

I'm your truth, telling lies
I'm your reason, alibis
I'm inside, open your eyes
I'm you

Sad but true
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
long long A[N];
set<pair<long long, long long> > by_A;
long long cur_best;
long long x[N],y[N],W[N];
vector<long long> G[N];
long long ans;
set<pair<long long, long long> > S;
set<pair<long long, long long> > ::iterator it;
long long best_special[N];
long long cheapest;
int used[N];

void mark_used(int v){
	used[v]=1;
	cheapest=min(cheapest,A[v]);
	S.erase(make_pair(best_special[v],v));
	by_A.erase(make_pair(A[v],v));
	for (int i=0;i<G[v].size();i++){
		int id=G[v][i];
		int to=x[id]+y[id]-v;
		if (used[to])
			continue;
		if (W[id]<best_special[to]){
			S.erase(make_pair(best_special[to],to));
			best_special[to]=W[id];
			S.insert(make_pair(best_special[to],to));
		}
	}
}

long long COST;

int get_best(){
	int ret;
	int v1;
	int v2;
	long long cost1;
	long long cost2;
	it=by_A.begin();
	cost1=(*it).first+cheapest;
	v1=(*it).second;
	it=S.begin();
	cost2=(*it).first;
	v2=(*it).second;
	COST=min(cost1,cost2);
	if (cost1<cost2)
		return v1;
	return v2;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	cin>>A[i];
    	by_A.insert(make_pair(A[i],i));
    }

    for (int i=1;i<=m;i++){
    	cin>>x[i]>>y[i]>>W[i];
    	G[x[i]].push_back(i);
    	G[y[i]].push_back(i);
    }

    for (int i=1;i<=n;i++){
    	best_special[i]=1e18;
    	S.insert(make_pair(best_special[i],i));
    }

    cheapest=1e18;

    mark_used(1);

    for (int i=2;i<=n;i++){
    	long long V=get_best();
    	mark_used(V);
    	ans+=COST;
    }

    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}