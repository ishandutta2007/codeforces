/*
There's a light in you
That tears me down to nothing
There's an angel in your eyes
There's a hope inside
That you can make it better
You see right through my disguise

When it rains it pours
And everybody stumbles
I won't let them bring you down

I won't let you down
When the seasons change
I won't go down
I'll fight through the pain
I'll be there right by your side
I'll never let them bring you down
When the seasons change

There's a hope in me
That I will die for something
Was there fire in my eyes
All this pain inside
Will it be this way forever
I can run but I can't hide

When it rains it pours
And everybody stumbles
I won't let them bring me down

I won't let you down
When the seasons change
I won't go down
I'll fight through the pain
I'll be there right by your side
I'll never let them bring you down
When the seasons change

When the seasons change
And we're in for colder weather
Look for me on the divide

I won't let you down
When the seasons change
I won't go down
I'll fight through the pain
I'll be there right by your side
I'll never let them bring you down
I won't let you down
When the seasons change
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 100031;

long long up[N][20];
int par[N][20];

int n;
long long lab[N];
vector<int> g[N];
int dep[N];

long long gcd(long long a,long long b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

long long ANS;
int ans;

long long get(int v,int hi){
	long long res=lab[v];
	int dif=dep[v]-hi+1;
	for (int i=19;i>=0;--i){
		if (dif&(1<<i)){
			res=gcd(res,up[v][i]);
			v=par[v][i];
		}
	}
	return res;
}
bool higher(long long a,long long b){
	if (a==0)
		return true;
	if (b==0)
		return false;
	return a>=b;
}

void solve(int v,int bound){
	if (bound==0)
		return;

	long long Q=get(v,bound-1);

	int last_full=0;

	int total_len=0;

	for (int i=0;i<20;i++){
		if (higher(up[v][i],Q))
			last_full=i,
			total_len=(1<<i);
	}

	long long my_val=up[v][last_full];
	long long cur=par[v][last_full];

	for (int i=last_full-1;i>=0;--i){
		long long here=gcd(my_val,up[cur][i]);
		if (higher(here,Q)){
			my_val=here;
			cur=par[cur][i];
			total_len+=(1<<i);
		}
	}

	int l=dep[v]-total_len+1;
	if (l<0)
		l=0;

//	cout<<v<<" "<<l<<" "<<bound<<" "<<Q<<endl;
	ANS+=Q*(bound-l);
	bound=l;
	solve(v,bound);
	ANS%=bs;
}
void dfs(int v,int p){
	par[v][0]=p;
	up[v][0]=lab[v];

	for (int i=1;i<20;i++){
		par[v][i]=par[par[v][i-1]][i-1];
		up[v][i]=gcd(up[v][i-1],up[par[v][i-1]][i-1]);
	}
	solve(v,dep[v]+1);

	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (to==p)
			continue;
		dep[to]=dep[v]+1;
		dfs(to,v);
	}
}


int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;

    for (int i=1;i<=n;i++){
    	cin>>lab[i];
    }

    for (int i=1;i<n;i++){
    	int a,b;
    	cin>>a>>b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }

    dfs(1,1);

    cout<<ANS<<endl;

//    cin.get(); cin.get();
    return 0;
}