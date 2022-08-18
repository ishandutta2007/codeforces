/*
There is no afterlife
We all just decompose
No Heaven's pearly gates
Just tags upon our toes
A slow putrescence
From the time the life is shorn
Feast for the maggots
Reborn
Wet and adipocerous
Our flesh turns in to wax
Enter hypostasis
Pale skin discolored black
Regeneration
When life has adjourned
Insect infestation
Our favors are returned

When from this world we are unbound
We're food for the worms
When they plant me in the ground I'm
Food for the worms

The reaper beats at the gate of every man
Lies fill the Bible, Tanakh and Quran
It matters not which dogma you believe
Our bodies are left to rot like fallen leaves
The circle of life it marches on
We fertilize the ground we walk upon
Feast for the vultures' all that's left
While hope spring eternal for the bereft

The throes of rigor mortis
Forensic certainty
Heaven, Olam Ha-Ba
Fairy tales of lunacy
We're vessels for the larvae
Not vessels for the soul
Transform to liquefaction
Make all nature whole
Food for the worms
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

const int N = 100031;

int tests;
int n;
vector<long long> positive,negative;

long long min_strategy(long long from1,long long from2){
	if (from1>positive.size()||from2>negative.size())
		return -1e18;
	long long prod=1;
	for (int i=0;i<from1;i++){
		prod*=positive[i];
	}
	for (int i=0;i<from2;i++){
		prod*=negative[i];
	}
	return prod;
}

long long max_strategy(long long from1,long long from2){
	if (from1>positive.size()||from2>negative.size())
		return -1e18;
	long long prod=1;
	for (int i=0;i<from1;i++){
		prod*=positive[positive.size()-i-1];
	}
	for (int i=0;i<from2;i++){
		prod*=negative[negative.size()-i-1];
	}
	return prod;
}
int main() {
  //freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  positive.clear();
	  negative.clear();
	  for (int i=1;i<=n;i++){
		  int val;
		  cin>>val;
		  if (val>=0)
			  positive.push_back(val);
		  if (val<0)
			  negative.push_back(val);
	  }
	  sort(positive.begin(),positive.end());
	  sort(negative.begin(),negative.end());

	  reverse(negative.begin(),negative.end());

	  long long ans=-1e18;

	  for (int cnt_pos=0;cnt_pos<=5;cnt_pos++){
		  int sig=(cnt_pos%2==1);
		  long long here;
		  if (sig==0)
			  here=min_strategy(cnt_pos,5-cnt_pos);
		  else
			  here=max_strategy(cnt_pos,5-cnt_pos);
		  ans=max(ans,here);
	  }
	  cout<<ans<<endl;
  }

  cin.get(); cin.get();
  return 0;
}