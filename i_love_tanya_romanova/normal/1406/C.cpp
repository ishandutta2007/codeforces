/*
Sadistic soldiers of the rising sun
1937's when the rape had begun
The ancient city fell under imperial rule
By an engine of war and lust, savage and cruel

Assembly line efficiency of killing machines
Unbridled fury of the sick and obscene
Systematic sexual degradation
The more perverse the greater exaltation

Nowhere to hide, nowhere to run
They turned the waters of the Yangtze red with blood
Cast aside and brutalized
Terrific horror made to terrorize

Bestial and violent, six weeks of suffering
So black was the day they marched through the gates
Their fate was beckoning

Tanks ran over men nailed to boards
Decapitations with an officer's sword
Gang rape of women, both the young and the old
Frozen to death in waters ice cold

Disembowelment, some are buried alive
Suicide's preferred for those who survive
The stench of corpses everywhere in the streets
Dogs feast on the rotting meat

Nowhere to hide, nowhere to run
They turned the waters of the Yangtze red with blood
Cast aside and brutalized
Terrific horror made to terrorize

Bestial and violent, six weeks of suffering
So black was the day they marched through the gates
Their fate was beckoning
It was the rape of Nanking

Thousands forced into prostitution
So many years and still no restitution
The carnage of Carthage so easily outdone
Add all the blood you get 1200 tons

Massacre removed from history books
No mention of men hung from iron hooks
All counter to the rules of war
They made a city an army's whore

Nowhere to hide, nowhere to run
They turned the waters of the Yangtze red with blood
Cast aside and brutalized
Terrific horror made to terrorize

Bestial and violent, six weeks of suffering
So black was the day, they marched through the gates
Their fate was beckoning
It was the rape of Nanking
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

int tests,n;
vector<int> g[N];
int used[N];
int cent_value[N];
vector<pair<int,int> > order;

void show_any_edge(){
	int to=g[1][0];
	cout<<1<<" "<<to<<endl;
	cout<<1<<" "<<to<<endl;
}

int find_leaf(int v){
	used[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		return find_leaf(to);
	}
	return v;
}

int subsize[N];

void dfs(int v){
	used[v]=1;
	subsize[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		dfs(to);
		cent_value[v]=max(cent_value[v],subsize[to]);
		subsize[v]+=subsize[to];
	}
	cent_value[v]=max(cent_value[v],n-subsize[v]);
}

int main() {
  //freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  for (int i=1;i<=n;i++){
		  g[i].clear();
	  }
	  for (int i=1;i<n;i++){
		  int a,b;
		  cin>>a>>b;
		  g[a].push_back(b);
		  g[b].push_back(a);
	  }
	  for (int i=1;i<=n;i++){
		  used[i]=0;
		  cent_value[i]=0;
	  }

	  dfs(1);
	  order.clear();
	  for (int i=1;i<=n;i++){
		  order.push_back(make_pair(cent_value[i],i));
	  }
	  sort(order.begin(),order.end());
//	  reverse(order.begin(),order.end());

	 /* for (int i=1;i<=n;i++){
		  cout<<i<<" "<<cent_value[i]<<endl;
	  }*/

	  // already good
	  if (order[0].first!=order[1].first){
		  show_any_edge();
	  }
	  else
	  {
		  for (int i=1;i<=n;i++){
			  used[i]=0;
		  }
		  used[order[1].second]=1;
		  int v=find_leaf(order[0].second);
		  int to=g[v][0];
		  cout<<v<<" "<<to<<endl;
		  cout<<v<<" "<<order[1].second<<endl;
	  }
  }

  cin.get(); cin.get();
  return 0;
}