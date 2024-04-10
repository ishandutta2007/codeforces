/*
Everything they do and say
Might even fool a clever mind
Just won't forget their price to pay
As silk betrays and truth unwinds

Cling, cling to your mind, my words
Never trust a foreign race
All the sweetness you have heard
Has put our soul in carbon haze

Everything they do and say
Might even fool a clever mind
Just won't forget their price to pay
As silk betrays and truth unwinds

Cling, cling shattered nerves
To the queen you did adore
Has turned to stiff ebonite cures
In scarlet waves on distant shore

Everything they do and say
Might even fool a clever mind
Just won't forget their price to pay
As silk betrays and truth unwinds
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

#define bs 1000000007

const int N = 500031;

int tests,n,m,a,b,c,P[N];
vector<int> g[N];
int DA[N],DB[N],DC[N];
int used[N];
queue<int> qu;
long long pref[N];

void run_bfs(int root){
	for (int i=1;i<=n;i++){
		used[i]=0;
	}
	used[root]=1;
	qu.push(root);
	while (qu.size()){
		int v=qu.front();
		qu.pop();
		for (int i=0;i<g[v].size();i++){
			int to=g[v][i];
			if (used[to])
				continue;
			used[to]=used[v]+1;
			qu.push(to);
		}
	}
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>m>>a>>b>>c;
	  for (int i=1;i<=m;i++){
		  cin>>P[i];
	  }
	  for (int i=1;i<=n;i++){
		  g[i].clear();
	  }
	  for (int i=1;i<=m;i++){
		  int a,b;
		  cin>>a>>b;
		  g[a].push_back(b);
		  g[b].push_back(a);
	  }

	  run_bfs(a);
	  for (int i=1;i<=n;i++){
		  DA[i]=used[i]-1;
	  }
	  run_bfs(b);
	  for (int i=1;i<=n;i++){
		  DB[i]=used[i]-1;
	  }
	  run_bfs(c);
	  for (int i=1;i<=n;i++){
		  DC[i]=used[i]-1;
	  }

	  sort(P+1,P+m+1);

	  for (int i=1;i<=m;i++){
		  pref[i]=pref[i-1]+P[i];
	  }

	  long long ans=1e18;

	  for (int ans_v=1;ans_v<=n;ans_v++){
		  int common=DB[ans_v];
		  int othr=DA[ans_v]+DC[ans_v];
		  if (common+othr>m)
			  continue;
		  long long here=pref[common]*2+(pref[common+othr]-pref[common]);
		  ans=min(ans,here);
	  }
	  cout<<ans<<endl;
  }

  // cin.get(); cin.get();
  return 0;
}