/*
You think your life's so grad
You don't believe a word you say
Your feet aren't on the ground
You let your life just slip away
Just so uncertain of your body and your soul
The promises you make, your mind so blank
And then you lose control, then you lose control!

I never was the one, the one to say the things you say
Never seem to wonder what you say
You think you've got your life completely in control
You've got a lot to learn,
The bridge you burn is gonna take its toll!!!
Pay the burnt bridge toll!!!

So practice what you preach!
Practice what you preach!
Preach!
Practice what you preach!
Practice what you preach!
Preach!
Practice what you preach!

You think your life's so grad
You don't believe a word you say
Your feet aren't on the ground
You let your life just slip away
Just so uncertain of your body and your soul
The promises you make, your mind so blank
And then you lose control, then you lose control!

Pay the burnt bridge toll, then you lose control
Pay the burnt bridge toll, so practice what you preach

So practice what you preach!
Preach!
Practice what you preach!
Practice what you preach!
Preach!
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

int tests,n,m;
vector<int> g[N],gr[N];
vector<pair<int,int> > memo,all_edges;
int tin[N],tout[N],timer,used[N];
int found_cycle;

void dfs(int v){
	if (found_cycle)
		return;
	++timer;
	tin[v]=timer;
	used[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to]==1){
			found_cycle=1;
			break;
		}
		if (used[to]==2)
			continue;
		dfs(to);
	}

	++timer;
	tout[v]=timer;
	used[v]=2;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>m;
	  for (int i=1;i<=n;i++){
		  g[i].clear();
		  gr[i].clear();
	  }
	  memo.clear();
	  all_edges.clear();

	  for (int i=1;i<=m;i++){
		  int tp;
		  cin>>tp;
		  int a,b;
		  cin>>a>>b;
		  if (tp==1){
			  g[a].push_back(b);
			  gr[b].push_back(a);
			  all_edges.push_back(make_pair(a,b));
		  }
		  else
		  {
			  memo.push_back(make_pair(a,b));
		  }
	  }

	  for (int i=1;i<=n;i++){
		  used[i]=0;
	  }

	  timer=0;

	  found_cycle=0;

	  for (int i=1;i<=n;i++){
		  if (used[i])
			  continue;
		  dfs(i);
	  }

	  if (found_cycle){
		  cout<<"NO"<<endl;
		  continue;
	  }
	  for (int i=0;i<memo.size();i++){
		  int v1=memo[i].first;
		  int v2=memo[i].second;
		  if (tout[v1]>tout[v2])
			  all_edges.push_back(make_pair(v1,v2));
		  else
			  all_edges.push_back(make_pair(v2,v1));
	  }
	  cout<<"YES"<<endl;
	  for (int i=0;i<all_edges.size();i++){
		  cout<<all_edges[i].first<<" "<<all_edges[i].second<<endl;
	  }

  }

  cin.get(); cin.get();
  return 0;
}