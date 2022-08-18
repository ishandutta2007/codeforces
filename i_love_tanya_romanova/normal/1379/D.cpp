/*
Look at you all clutching your guitars
As if it makes a difference to who you really are
Does the picking of a string stop the ticking of the clock?
When will this curtain fall?
 
How did you carve that psalms?
I'm sorry but your intellect is really not that sharp
You're drowning so you plagiarize what you wish to become
A stone masquerade so cold
 
What's real about this story?
What's real?
 
Am I safe? Am I safe to be alone?
When all around are lost
Comsumed by my indifference and left to count the cost
Of all the bleeding hearts who suffered you because you told them...
You told them you were someone
 
What's real about this story?
What's real about this picture?
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
 
long long n,h,k,m,trash,V,train[N];
vector<pair<long long, long long> > events;
long long baseline,best_time,best_ans;
 
int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);
 
  cin>>n>>h>>m>>k;
 
  for (int i=1;i<=n;i++){
	 cin>>trash>>V;
	 if (V>=m/2)
		 V-=m/2;
	 train[i]=V;
	 if (V>m/2-k) // initially bad
	 {
		 events.push_back(make_pair(V+k-m/2,1));
		 events.push_back(make_pair(V+1,-1));
	 }
	 else // initially good
	 {
		 baseline++;
		 events.push_back(make_pair(V+1,-1));
		 events.push_back(make_pair(V+k,1));
	 }
  }
 
  //cout<<baseline<<endl;
 
  best_time=0;
  best_ans=baseline;
 
  sort(events.begin(),events.end());
 
  for (int i=0;i<events.size();i++){
	  if (events[i].second==-1)
		  baseline--;
	  else
		  baseline++;
	  if (baseline>best_ans){
		  best_ans=baseline;
		  best_time=events[i].first;
	  }
  }
 
//  cout<<best_time<<" "<<best_ans<<endl;
 
  cout<<n-best_ans<<" "<<best_time<<endl;
 
  vector<int> ans;
 
  for (int i=1;i<=n;i++){
	 int ok=1;
	 if (train[i]>best_time-k&&train[i]<best_time)
		 ok=0;
	 if (train[i]>best_time+m/2-k&&train[i]<best_time+m/2)
		 ok=0;
	 if (!ok){
		 ans.push_back(i);
	 }
  }
 
  for (int i=0;i<ans.size();i++){
	  if (i)
		  cout<<" ";
	  cout<<ans[i];
  }
  cout<<endl;
 
  cin.get(); cin.get();
  return 0;
}