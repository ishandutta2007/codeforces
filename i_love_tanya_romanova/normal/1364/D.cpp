/*
Fear in my subconscious
Terror invades my speech
Faith in my own words
No one knows the nameless

Warm winds and burning tears
Spirits outside bodies

Endless repression by majority
A master without command
Strange new dimension disturbing my brain
Censored ideas, counterfeit answers

Shining blast, no perception
Altered state, no reaction
Shining blast
Altered state

Slow talk, fast thoughts
Ancient scriptures
Controversial lines
Knowledge changes

Running in the wrong direction
Crossing with blind eyes
I'm closer to myself
Sanity can't invade
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

int n,m,k;
vector<int> g[N];
int used[N];
bool have_cycle;
vector<int> comp[3];
int clr[N];
int KK;
vector<int> cycle;

set<pair<int,int> > banned;

void dfs(int v){
	used[v]=1;
	//cout<<v<<"@@@"<<KK<<endl;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		if (KK==k)
			continue;
		banned.insert(make_pair(v,to));
		banned.insert(make_pair(to,v));
		clr[to]=(1^clr[v]);
		++KK;
		dfs(to);
	}
}

int shade[N];
vector<int> stck;

void restore_cycle(int v1,int v2){
	/*for (int i=0;i<stck.size();i++){
		cout<<"@@@"<<stck[i];
	}
	cout<<endl;
	cout<<"@@"<<v1<<" "<<v2<<endl;
*/
	while (stck.back()!=v2){
		cycle.push_back(stck.back());
		stck.pop_back();
	}
	cycle.push_back(v2);
}

void trace(int v,int p=-1){
	if (have_cycle)
		return;
	shade[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to]==0)
			continue;
		if (to==p)
			continue;
		if (shade[to]==2)
			continue;
		if (shade[to]==1&&have_cycle==0){
			have_cycle=1;
			restore_cycle(v,to);
			return;
		}
		stck.push_back(to);
		trace(to,v);
		if (stck.size())
			stck.pop_back();
	}
	shade[v]=2;
}

void solve_cycle(int v){
	//cout<<"!!"<<endl;
	stck.push_back(v);
	trace(v);
//	stck.pop_back();
}


int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n>>m>>k;
  for (int i=1;i<=m;i++){
	  int a,b;
	  cin>>a>>b;
	  g[a].push_back(b);
	  g[b].push_back(a);
  }

  KK=1;
  dfs(1);

  for (int i=1;i<=n;i++){
	  if (used[i]==1){
		  for (int j=0;j<g[i].size();j++){
			  int to=g[i][j];
			  if (used[to]==1&&banned.find(make_pair(i,to))==banned.end()){
				  solve_cycle(i);
			  }
		  }
	  }
  }

  if (!have_cycle){
	  for (int i=1;i<=n;i++){
		  if (used[i]==0)
			  continue;
		  comp[clr[i]].push_back(i);
	  }
	  //cout<<comp[0].size()<<" "<<comp[1].size()<<endl;

	  if (comp[0].size()<comp[1].size()){
		  swap(comp[0],comp[1]);
	  }
	  while (comp[0].size()>(k+1)/2)
		  comp[0].pop_back();
	  cout<<1<<endl;
	  for (int i=0;i<comp[0].size();i++){
		  if (i)
			  cout<<" ";
		  cout<<comp[0][i];
	  }
	  cout<<endl;
  }
  else
  {
	  cout<<2<<endl;
	  cout<<cycle.size()<<endl;
	  for (int i=0;i<cycle.size();i++){
		  if (i)
			  cout<<" ";
		  cout<<cycle[i];
	  }
	  cout<<endl;
  }

  cin.get(); cin.get();
  return 0;
}