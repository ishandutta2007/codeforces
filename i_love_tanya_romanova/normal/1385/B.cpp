/*
Fools the ones who stray, the rain forest burns away
Know what to believe, this is the air we breathe
So the world we know is dying slow in South America
Flames are burning down, all the trees to the ground

Time is running low, we can't stay no more
Wealth these people see, fight for eternity
Lies they televise paid by their government
There on! It's lingers on
And they don't even care in they...

Seal the Planet's fate
Crimes they perpetrate
Wasting precious land
It's time to take a stand

Our only hope to breathe again
To stop the madness closing in
What will we do when all is lost?
Environmental holocaust... repeat

Foes, these people go, someone destroyed their home
Plagued with disease, left praying on their knees
Laws protect the land, social justice in demand
Smoke it fills the air into the atmosphere
Now it's time to see a cycle of a tragedy
On! It lingers on, and they don't even care if they

Seal the Planet's fate
Crimes they perpetrate
Wasting precious land
It's time to take a stand

Our only hope to breathe again
To stop the madness closing in
What will we do when all is lost?
Environmental holocaust... repeat
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

int tests;
int last_entry[N];
vector<pair<int,int> > order;
int n;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  for (int i=1;i<=n*2;i++){
		  int x;
		  cin>>x;
		  last_entry[x]=i;
	  }
	  order.clear();
	  for (int i=1;i<=n;i++){
		  order.push_back(make_pair(last_entry[i],i));
	  }
	  sort(order.begin(),order.end());
	  for (int i=0;i<order.size();i++){
		  if (i)
			  cout<<" ";
		  cout<<order[i].second;
	  }
	  cout<<endl;
  }
  cin.get(); cin.get();
  return 0;
}