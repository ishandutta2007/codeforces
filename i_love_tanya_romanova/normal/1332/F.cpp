/*
What if some things are destined to failure?
What if some things are never meant to be?
What if someone never sees?
What if someone never opens?
What if somehow we are different?

Though I never claimed to be right
Give to me the benefit of doubt

I brought you fires
All that you put out
I brought you fires
For I cannot be without
I came with sadness
But this my shattered heart can't bear

What of the times in exile?
What of the hours passed?
What if touches seem too trivial?
You can never tell me I'm wrong
A song I've heard so long

I brought you fires
All that you put out
I brought you fires
For I cannot be without
I came with sadness
But this my shattered heart can't bear

When I came in madness
So this my shattered heart can't bear!
My shattered heart won't bear!

So what if healing takes forever?
So what if time is meant for others?
So what is left is but a shatter?
And what is broken can't be whole
What is broken can't be whole again

I brought you fires
All that you put out
I brought you fires
For I cannot be without
I came with sadness
But this my shattered heart can't bear
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 600031;

int n;
vector<int> g[N];
int used[N];

// dp : v, in indep.set, in subgraph

// knap: ps, has indep v from below, has edge from below

int sz;
vector<int> sons[N];

long long dp[N][2][2];
long long knap[N][2][2];

void knapsack(int v){
	int sz=sons[v].size();

	for (int i=0;i<=sz;i++){
		knap[i][0][0]=knap[i][0][1]=knap[i][1][0]=knap[i][1][1]=0;
	}

	knap[0][0][0]=1;
	for (int i=0;i<sons[v].size();i++){
		int to=sons[v][i];
		for (int old_ind=0;old_ind<=1;old_ind++){
			for (int old_sub=0;old_sub<=1;old_sub++){
				for (int this_ind=0;this_ind<=1;this_ind++){
					for (int this_sub=0;this_sub<=1;this_sub++){
						for (int take_edge=0;take_edge<=1;take_edge++){
							// I must take the edge if this sub is still 0 yet this ind already 1
							if (this_sub==0&&this_ind==1&&take_edge==0)
								continue;
							int new_sub=(old_sub|take_edge);
							int new_ind=(old_ind|(take_edge&this_ind));
							knap[i+1][new_ind][new_sub]=(knap[i+1][new_ind][new_sub]+
									knap[i][old_ind][old_sub]*1ll*dp[to][this_ind][this_sub])%bs;
						}
					}
				}
			}
		}
	}
}

void dfs(int v){
	used[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		dfs(to);
		sons[v].push_back(to);
	}
	knapsack(v);

	int sz=sons[v].size();
	dp[v][0][0]=(knap[sz][1][0]+knap[sz][0][0])%bs;
	dp[v][0][1]=(knap[sz][1][1]+knap[sz][0][1])%bs;
	dp[v][1][0]=(knap[sz][0][0])%bs;
	dp[v][1][1]=(knap[sz][0][1])%bs;
}

int main() {
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n;
  for (int i=1;i<n;i++){
	  int a,b;
	  cin>>a>>b;
	  g[a].push_back(b);
	  g[b].push_back(a);
  }

  dfs(1);

  cout<<(dp[1][0][0]+dp[1][0][1]+dp[1][1][1]+bs-1)%bs<<endl;

  //    cin.get(); cin.get();
  return 0;
}