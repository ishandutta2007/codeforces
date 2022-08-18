/*
Running my way towards oblivion
Inside my head electric insomnia
In your mind i'm fed with distrust
Heading for anything better than this

I want to be forgotten
I want you to forgive
How i'm losing all this
It's just the way i live

Running my way towards oblivion
Inside my head smokescreen's gone
Leaving all this to be undone
Heading for anything better than this

Running my way towards oblivion
Outside my head only the dark
In your mind i'm the end of it all
Heading for anything better than this
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

const int N = 610031;

int n,a[N],b[N],c[N];
int s0,s1;
long long ans;
set<pair<int,int> > S01,S10;
set<pair<int,int> >::iterator it1,it2;
vector<pair<int,int> > order;
int tin[N],tout[N];
int v1,v2;
int used[N];
int timer;
vector<int> g[N];

void dfs(int v){
	++timer;
	tin[v]=timer;
	used[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		dfs(to);
	}
	++timer;
	tout[v]=timer;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n;
  for (int i=1;i<=n;i++){
	  cin>>a[i]>>b[i]>>c[i];
	  s0+=b[i];
	  s1+=c[i];
  }

  if (s0!=s1){
	  cout<<-1<<endl;
	  return 0;
  }

  for (int i=1;i<n;i++){
	 cin>>v1>>v2;
	 g[v1].push_back(v2);
	 g[v2].push_back(v1);
  }

  dfs(1);

  for (int i=1;i<=n;i++){
	  if (b[i]==c[i])
		  continue;
	  if (b[i]==1)
		  S10.insert(make_pair(tin[i],i));
	  else
		  S01.insert(make_pair(tin[i],i));
  }

  for (int i=1;i<=n;i++){
	 order.push_back(make_pair(a[i],i));
  }

  sort(order.begin(),order.end());

  for (int i=0;i<order.size();i++){
	  int id=order[i].second;
	  while (true){
		  it1=S01.lower_bound(make_pair(tin[id],-1));
		  it2=S10.lower_bound(make_pair(tin[id],-1));
		  if (it1==S01.end()||it2==S10.end())
			  break;
		  int v1=(*it1).second;
		  int v2=(*it2).second;
		//  cout<<v1<<"@"<<v2<<endl;
		  if (tin[v1]>tout[id]||tin[v2]>tout[id])
			  break;
		  ans+=order[i].first;
		  S01.erase(it1);
		  S10.erase(it2);
	  }
  }

  cout<<ans*1ll*2<<endl;

  cin.get(); cin.get();
  return 0;
}