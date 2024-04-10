/*
The men in the black forces
Listen to your conscience
Stopping the evolution
The books are the essence

United to burn anything that can make a stand
The church is an empire, the no way direction
No matter what you say
They run completely blind

No matter what you wrote
Shut up you lie!
And the books are burning hard

Your mind is running slow
Your mind is running slow
Your mind is running slow

Light up a fire in the middle of the city
Burning all the thoughts
Of those who got some ideas
The mission will continue throughout time

Manipulation of all fragile minds
Burn! Burn! Burn! Burn!...
Down! Down! Down! Down!...
Don't want to endure it anymore

Much too radical
The future intelligence falls into enemy hands
Don't want to hear it anymore
Much too political

Spending the time in ignorance
Computers blow up
By the shock of the present

The blackguards control
The blackguards control
The blackguards control
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

const int N = 200031;

int n;
vector<int> g[N];
int deg[N];
vector<int> sons[N];
int used[N];
int dep[N];
int have[10];
int leaves[N];

void trace(int v){
	used[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		dep[to]=dep[v]+1;
		sons[v].push_back(to);
		trace(to);
		if (sons[to].size()==0)
			leaves[v]++;
	}
}

int ans_max;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n;
  for (int i=1;i<n;i++){
	  int a,b;
	  cin>>a>>b;
	  g[a].push_back(b);
	  g[b].push_back(a);
	  deg[a]++;
	  deg[b]++;
  }

  int root=1;
  while (deg[root]==1)
	  ++root;

  trace(root);

  for (int i=1;i<=n;i++){
	 // cout<<i<<" @"<<sons[i].size()<<" "<<used[i]<<endl;
	  if (i==root)
		  continue;
	  if (sons[i].size()==0){
		  have[dep[i]%2]=1;
	  }
  }

  ans_max=n-1;

  for (int i=1;i<=n;i++){
	  if (sons[i].size()==0)
		  continue;
	  if (leaves[i]>0)
		  ans_max-=(leaves[i]-1);
  }
  if (have[0]>0&&have[1]>0)
	  cout<<3;
  else
	  cout<<1;
  cout<<" ";
  cout<<ans_max<<endl;

  // cin.get(); cin.get();
  return 0;
}