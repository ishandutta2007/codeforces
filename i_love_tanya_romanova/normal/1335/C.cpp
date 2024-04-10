/*
In the bunker suppressing fire
Burning heat of hot desire
Ammo box and bullet belt
Automatic weapon how it felt
Assume position and take the mound
Spitting shells, we're victory bound

Barrage of shrapnel, a shower of lead
The taking of the beach head
Metal fatigue so grease the barrel
Evasive action and deadly peril
Fire at will
In for the kill
Kill or be killed

Shoot your machine gun
Machine gun

Spring loaded, trigger happy firing cap
Blow the beach right off of the map
Pull the fire pin - ready to go
Squeeze the trigger and watch it blow

Machine gun
Shoot your machine gun
Take aim and fire

Machine gun
Shoot your machine gun

Powder burned form rapid fire
Magazine did so expire
Discharge recoil when it's spent
Objective achieved withdraw with intent
Now the fortress was taken by force
A warring intercourse

Machine gun
Shoot your machine gun
Machine gun
Shoot your machine gun
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
map<int,int> mapp;
int n;
vector<int> order;
map<int,int> ::iterator it;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  mapp.clear();
	  cin>>n;
	  for (int i=1;i<=n;i++){
		  int val;
		  cin>>val;
		  mapp[val]++;
	  }
	  order.clear();
	  for (it=mapp.begin();it!=mapp.end();it++){
		  int id=(*it).first;
		  int val=(*it).second;
		  order.push_back(val);
	  }
	  sort(order.begin(),order.end());
	  reverse(order.begin(),order.end());
	  int v1=0;
	  int v2=0;
	  v1=min((int)order.size()-1,order[0]);
	  v2=min((int)order.size(),order[0]-1);
	  cout<<max(v1,v2)<<endl;
  }

  // cin.get(); cin.get();
  return 0;
}