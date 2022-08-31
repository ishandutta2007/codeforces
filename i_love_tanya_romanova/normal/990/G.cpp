/*
Run the race that will lead to nowhere fast
Trapped in the haze of this mindless false reality
Wandering a path laid out by fools
That they call "progression" where chaos rules

There is more to life than this
We are more than just this flesh
We are alive and our time has come
For a new awakening

Come death, come suffering, I will not live in fear
In this fleeting life where time escapes us
The path of least resistance is a slow, quiet death
I'd rather burn out than fade away

There is more to life than this
We are more than just this flesh
We are alive and our time has come
For a new awakening

I would rather die than live my life in fear
Out of step, no regrets in the new awakening

I will not live in fear
Live life with no regrets
I will not live in fear

There is more to life than this
We are more than just this flesh
We are alive and our time has come
For a new awakening

I'd rather burn out than fade away
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 1200031;

int n,ar[N],w[N];

int gcd(int a,int b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

vector<pair<int,int> > edges;
vector<int> entries[N];

int sz[N];
long long ANS[N];
vector<int> interesting;

long long cur_pairs;

void run_cleanup()
{
	for (int i=0;i<interesting.size();i++){
		int id=interesting[i];
		sz[id]=1;
		w[id]=id;
	}
}

int get(int x){
	interesting.push_back(x);
	if (x==w[x])
		return x;
	return w[x]=get(w[x]);
}

long long F(int x){
	return 1ll*x*(x-1)/2;
}

void merge(int a,int b){
	a=get(a);
	b=get(b);
	if (a==b)
		return;
	cur_pairs-=F(sz[a]);
	cur_pairs-=F(sz[b]);
	w[a]=b;
	sz[b]+=sz[a];
	cur_pairs+=F(sz[b]);
}

vector<int> divs[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;

	for (int i=1;i<=n;i++){
		cin>>ar[i];
	}
	for (int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		edges.push_back(make_pair(a,b));
	}

	for (int i=0;i<edges.size();i++){
		int here=gcd(ar[edges[i].first],ar[edges[i].second]);
		entries[here].push_back(i);
	}

	for (int i=1;i<=n;i++){
		w[i]=i;
		sz[i]=1;
	}

	for (int i=1;i<=200000;i++){
		interesting.clear();
		cur_pairs=0;
		for (int j=i;j<=200000;j+=i){
			for (int q=0;q<entries[j].size();q++){
				int id=entries[j][q];
				merge(edges[id].first,edges[id].second);
			}
		}
		ANS[i]=cur_pairs;
		run_cleanup();
	}

	for (int i=1;i<=200000;i++){
		for (int j=i*2;j<=200000;j+=i)
			divs[j].push_back(i);
	}

	for (int i=200000;i;--i){
		for (int j=0;j<divs[i].size();j++){
			int p=divs[i][j];
			ANS[p]-=ANS[i];
		}
	}

	for (int i=1;i<=n;i++){
		ANS[ar[i]]++;
	}

	for (int i=1;i<=200000;i++){
		if (ANS[i])
			cout<<i<<" "<<ANS[i]<<endl;
	}

//	cin.get(); cin.get();
	return 0;
}