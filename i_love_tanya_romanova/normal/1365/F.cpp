/*
Me and my old lady
Lay in bed all day
And when I say I love her
Well she rolls the other way
But really she don't mean it
Everything she says
Still if I believe in love
There's nothing wrong
There's nothing wrong with my head

Me and my old lady
Sit and sip on wine
And when she says she loves me
Will I say that love is blind
But really I don't mean it
Everything I say
Still if she believes in love
There's nothing wrong
There's nothing wrong with her head

So what if we're making a scene now
You know she don't give a shit
When she's pawin' and grabbin' on me now
You know I don't mind a bit
It's all good and we
Ain't gonna change now
The world is unaware
So if you want to go on and stare
Cause we don't care

She ain't no ball and chain
Me and my old lady
Suck each other dry
And when in that position
I'm the luckiest man alive
Quenching our libidos
Passing time away
Now that I believe in love
There's nothing wrong
There's nothing wrong with my head
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

const int N = 610031;

int n;
set<vector<int> > used;
set<vector<int> > ::iterator it;

void dfs(vector<int> v){
	used.insert(v);
	for (int i=1;i<=v.size()/2;i++){
		vector<int> v2=v;
		for (int j=0;j<i;j++){
			swap(v2[j],v2[v2.size()-i+j]);
		}
		if (used.find(v2)!=used.end())
			continue;
		dfs(v2);
	}
}

int tests;
int a[N],b[N];
vector<pair<int,int> > pairs0,pairs1;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

 /* cin>>n;
  vector<int> v;
  for (int i=1;i<=n;i++){
	  v.push_back(i);
  }
  dfs(v);

  for (it=used.begin();it!=used.end();it++){
	  v=(*it);
	  for (int i=0;i<v.size();i++){
		  cout<<v[i]<<" ";
	  }
	  cout<<endl;
  }*/

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  for (int i=1;i<=n;i++){
		  cin>>a[i];
	  }
	  for (int i=1;i<=n;i++){
		  cin>>b[i];
	  }

	  if (n%2==1&&a[n/2+1]!=b[n/2+1])
	  {
		  cout<<"No"<<endl;
		  continue;
	  }

	  pairs0.clear();
	  pairs1.clear();
	  for (int i=1;i<=n/2;i++){
		  int v1=a[i];
		  int v2=a[n-i+1];
		  if (v1>v2)
			  swap(v1,v2);
		  pairs0.push_back(make_pair(v1,v2));
		  v1=b[i];
		  v2=b[n-i+1];
		  if (v1>v2)
			  swap(v1,v2);
		  pairs1.push_back(make_pair(v1,v2));
	  }

	  sort(pairs0.begin(),pairs0.end());
	  sort(pairs1.begin(),pairs1.end());
	  int ok=1;
	  for (int i=0;i<pairs0.size();i++){
		  if (pairs0[i]!=pairs1[i])
			  ok=0;
	  }

	  if (ok)
		  cout<<"Yes"<<endl;
	  else
		  cout<<"No"<<endl;
  }

  cin.get(); cin.get();
  return 0;
}