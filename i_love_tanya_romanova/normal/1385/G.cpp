/*
I'm gonna take you
To a place far from here
No one will see us
Watch the pain as it disappears
No time for anger
No time for despair
Won't you come with me
There's a room for us there
This innocent beauty
My words can't describe
This rebirth purity
Brings a sullen tear right to your eyes
No time for anger
No time for despair
Please let me take you
'Cause I'm already there

I'm so alone
My head's my home
I'll return to serenity

Rhyme without reason is why children cry
They see through the system
That's breeding them just so they die
So please let me take you
And I'll show you the truth
Inside my reality
We shared in our youth

[Chorus:]
I'm so alone
My head's my home
And I feel
So alone
You know
At last
I'll return to serenity

Now that I've taken you
To a place far from here
I really must go back
Close your eyes and we'll disappear
Won't you come with me
Salvation we'll share
Inside of my head now
There's a room for us there

[Chorus]
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

int tests,ar1[N],ar2[N];
vector<pair<int,int> > g[N];
vector<pair<int,int> > entries[N];
int cnt[N];
int shit;
int n;
vector<int> ans;
int used[N];
vector<int> comp[10];

void dfs(int v,int c){
	used[v]=c;
	comp[c].push_back(v);
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i].first;
		int should_be=c;
		if (g[v][i].second==1)
			should_be=3-c;
		if (used[to]==should_be)
			continue;
		if (used[to]>0&&used[to]!=should_be){
			shit=1;
			continue;
		}
		dfs(to,should_be);
	}
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  for (int i=1;i<=n;i++){
		  cin>>ar1[i];
	  }
	  for (int i=1;i<=n;i++){
		  cin>>ar2[i];
	  }
	  for (int i=1;i<=n;i++){
		  g[i].clear();
		  entries[i].clear();
		  cnt[i]=0;
	  }
	  for (int i=1;i<=n;i++){
		  cnt[ar1[i]]++;
		  cnt[ar2[i]]++;
		  entries[ar1[i]].push_back(make_pair(i,1));
		  entries[ar2[i]].push_back(make_pair(i,2));
	  }

	  shit=0;
	  for (int i=1;i<=n;i++){
		  if (cnt[i]!=2){
			  shit=1;
		  }
	  }

	  if (shit)
	  {
		  cout<<"-1"<<endl;
		  continue;
	  }

	  for (int i=1;i<=n;i++){
		  int c1=entries[i][0].first;
		  int c2=entries[i][1].first;
		  if (entries[i][0].second==entries[i][1].second){
			  g[c1].push_back(make_pair(c2,1));
			  g[c2].push_back(make_pair(c1,1));
		  }
		  else
		  {
			  g[c1].push_back(make_pair(c2,0));
			  g[c2].push_back(make_pair(c1,0));
		  }
	  }

	  for (int i=1;i<=n;i++){
		  used[i]=0;
	  }
	  shit=0;

	  ans.clear();
	  for (int i=1;i<=n;i++){
		  if (used[i])
			  continue;
		  comp[1].clear();
		  comp[2].clear();
		  dfs(i,1);
		  if (comp[1].size()>comp[2].size())
			  swap(comp[1],comp[2]);
		  for (int j=0;j<comp[1].size();j++){
			  ans.push_back(comp[1][j]);
		  }
	  }

	  if (shit){
		  cout<<-1<<endl;
		  continue;
	  }
	  cout<<ans.size()<<endl;
	  for (int i=0;i<ans.size();i++){
		  if (i)
			  cout<<" ";
		  cout<<ans[i];
	  }
	  cout<<endl;
  }

  cin.get(); cin.get();
  return 0;
}