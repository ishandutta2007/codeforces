/*
When I take your flesh and lacerate you
Exposing all your hate
There's nothing left but lies to throw away

Eviscerate you
Reduce you to your fate
Deleted and erased all your decay

When I think of all the hell
You tried to put me through
It can't compare to what's already done
It's time to say farewell
And leave you black and blue
When I rip you open all I'll do
Is salt the wound

The bane of my existence cancerous
A tumor on my soul
Unnecessary wart upon my skin

Full of puss
You're a Judas and a troll
Lance the boil rooted deep within

When I think of all the hell
You tried to put me through
It can't compare to what's already done
It's time to say farewell
And leave you black and blue
When I rip you open all I'll do
Is salt the wound

Rest assured when I pollute you
Your disease I will correct
My contagion
Only now I know the source

I uproot you
Lance the boil disinfect
Pestilence of ruin's run its course

When I think of all the hell
You tried to put me through
It can't compare to what's already done
It's time to say farewell
And leave you black and blue
When I rip you open all I'll do
Is salt the wound
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

int tests,n,cnt[N];
int ans;

int main() {
  //freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  for (int i=0;i<=100;i++){
		  cnt[i]=0;
	  }
	  for (int i=0;i<n;i++){
		  int val;
		  cin>>val;
		  cnt[val]++;
	  }
	  int ptr=0;
	  while (cnt[ptr]>1)
		  ++ptr;
	  ans=ptr;
	  while (cnt[ptr]>0)
		  ++ptr;
	  ans+=ptr;
	  cout<<ans<<endl;
  }

  cin.get(); cin.get();
  return 0;
}