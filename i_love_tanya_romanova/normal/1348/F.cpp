/*
How many walls can you put up?
How many guns 'til you feel safe?
How many times can we watch this story
Over and over and over again?
And how many years have we wasted
Counting the lies that we've been fed?
For something to change we have waited
Over and over and over again

I'm entertained by the monkey on your back
But can we still call it a joke if no one laughs?
It's either going up in smoke around me or according to plan
A bittersweet disaster mounting over and over again

How many walls can you put up?
How many guns 'til you feel safe?
How many times can we watch this story
Over and over and over again?
How many years have we wasted
Counting the lies that we've been fed?
For something to change we have waited
Over and over and over again

Chasing our own tail, the more we learn the less we know
As the monsters lost in history are now making their return
As we bow down, roll out the carpet red as rose
We should have known

How many walls can you put up?
How many guns 'til you feel safe?
How many times can we watch this story
Over and over and over again?
How many years have we wasted
Counting the lies that we've been fed?
For something to change we have waited
Over and over and over and over again

How many walls?
How many guns?
How many times?
Over and over and over again
Over and over and over again

And how many lives have been wasted?
How many bodies laid to rest?
Sick of the lies, the same old story
All over and over and over and over
Over and over and over and over again
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

const int N = 500031;

int n;
int l[N],r[N];
vector<pair<int,int> > order;

pair<int,int> t[N*4];
int found;
int id1,id2;

pair<int,int> combine(pair<int,int> p1,pair<int,int> p2){
	if (p1.first>p2.first)
		return p1;
	return p2;
}

void build(int v,int tl,int tr){
	if (tl==tr){
		t[v]=make_pair(order[tl].first,tl);
		return;
	}
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	t[v]=combine(t[v*2],t[v*2+1]);
}

pair<int,int> get(int v,int tl,int tr,int l,int r){
	if (l>r)
		return make_pair(-1,-1);
	if (tl==l&&tr==r)
		return t[v];
	int tm=tl+tr;
	tm/=2;
	return combine(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}

vector<int> starters[N];
set<pair<int,int> > S;
set<pair<int,int> > ::iterator it;
int whr[N];

vector<int> get_inv(vector<pair<int,int> > v){
	for (int i=0;i<v.size();i++){
		whr[v[i].second]=i;
	}
	vector<int> ret;
	for (int i=0;i<v.size();i++){
		ret.push_back(whr[i]);
	}
	return ret;
}

void show(vector<int> v){
	  for (int i=0;i<v.size();i++){
		  if (i)
			  cout<<" ";
		  cout<<v[i]+1;
	  }
	  cout<<endl;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n;
  for (int i=0;i<n;i++){
	  cin>>l[i]>>r[i];
	  --l[i];
	  --r[i];
	  starters[l[i]].push_back(i);
  }

  for (int i=0;i<n;i++){
	  for (int j=0;j<starters[i].size();j++){
		  int id=starters[i][j];
		  S.insert(make_pair(r[id],id));
	  }
	  it=S.begin();
	  int fi=(*it).second;
	  order.push_back(make_pair(r[fi],fi));
	  S.erase(it);
  }

  build(1,0,n-1);

  for (int i=1;i<order.size();i++){
	  int id=order[i].second;
	  int le=l[id];
	  int ri=i-1;
	  pair<int,int> P=get(1,0,n-1,le,ri);
	//  cout<<P.first<<" "<<P.second<<" "<<le<<" "<<ri<<" "<<id<<endl;
	  if (P.first>=i){
		  id1=id;
		  id2=order[P.second].second;
		  found=1;
	  }
  }

  if (!found){
	  cout<<"YES"<<endl;
	  show(get_inv(order));
	  return 0;
  }

  cout<<"NO"<<endl;
  show(get_inv(order));
  for (int i=0;i<order.size();i++){
	  if (order[i].second==id1)
		  order[i].second=id2;
	  else if (order[i].second==id2)
		  order[i].second=id1;
  }
  show(get_inv(order));


  // cin.get(); cin.get();
  return 0;
}