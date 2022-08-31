/*
Grace - in a perfect world
On shines the light
Praise - an angelic song
but there's another side you'll see
Now hide
salvation easily denied

Reigns - Down with misery
Life's not always what it seems
False hope
written in the testament of old
Take heed
stop believing every word you read
Truth inconsistencies
Distorts the lie
False imprisonment
Forever lost inside your mind
Fates door
Just be careful what you wish for
Death's door
Just be careful what you wish for

Peace of mind I can't find
Don't be blind take the ride

Hey... we live in a fucked up world
Walking on through the demise
We step into the unknown
Your better save yourself...

Hey... we live in a fucked up world
Hiding behind the disguise
Never let your feelings show
Why can't you be yourself...
We live in a fucked up world
Walking on through the demise
We step into the unknown
Your better save yourself...
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

int tests,n,k;
set<int> g[N];
int deg[N];
set<int> ::iterator it;
int leaf_count[N];
set<pair<int,int> > by_leaves;
set<pair<int,int> > ::iterator it2;
int is_leaf[N];
vector<int> nei_leaves[N];
int ans;

void mark_as_leaf(int v){
	is_leaf[v]=1;
	if (g[v].size()){
		it=g[v].begin();
		int othr=(*it);
		nei_leaves[othr].push_back(v);
		by_leaves.erase(make_pair(leaf_count[othr],othr));
		leaf_count[othr]++;
		by_leaves.insert(make_pair(leaf_count[othr],othr));
	}
}

void kill_leaf(int v){
	by_leaves.erase(make_pair(leaf_count[v],v));
	//cout<<"@@@@"<<v<<endl;
	it=g[v].begin();
	int othr=(*it);
	g[v].erase(othr);
	g[othr].erase(v);
	by_leaves.erase(make_pair(leaf_count[othr],othr));
	leaf_count[othr]--;
	by_leaves.insert(make_pair(leaf_count[othr],othr));
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>k;

	  by_leaves.clear();
	  for (int i=1;i<=n;i++){
		  nei_leaves[i].clear();
		  is_leaf[i]=0;
		  leaf_count[i]=0;
	  }
	  for (int i=1;i<=n;i++){
		  g[i].clear();
		  deg[i]=0;
	  }
	  for (int i=1;i<n;i++){
		  int a,b;
		  cin>>a>>b;
		  g[a].insert(b);
		  g[b].insert(a);
		  deg[a]++;
		  deg[b]++;
	  }

	  for (int i=1;i<=n;i++){
		  if (g[i].size()==1){
			  mark_as_leaf(i);
		  }
	  }

	  for (int i=1;i<=n;i++){
		  by_leaves.insert(make_pair(leaf_count[i],i));
	  }
	  ans=0;

	  while (true){
		  //cout<<by_leaves.size()<<"@@"<<endl;
		  if (by_leaves.size()==0)
			  break;
		  it2=by_leaves.end();
		  --it2;
		  int v=(*it2).second;
		//  cout<<v<<"@"<<leaf_count[v]<<endl;
		  if (leaf_count[v]<k)
			  break;
		  ++ans;
		  for (int i=0;i<k;i++){
			  int leaf_v=nei_leaves[v].back();
			  nei_leaves[v].pop_back();
			  kill_leaf(leaf_v);
		  }
		  if (g[v].size()==1&&is_leaf[v]==0){
			  mark_as_leaf(v);
		  }
	  }
	  cout<<ans<<endl;
  }

  cin.get(); cin.get();
  return 0;
}