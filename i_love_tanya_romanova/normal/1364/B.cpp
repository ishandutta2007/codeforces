/*
Death comes from the unknown
Darkened by its own existence
The end no longer exists when the spirit leaves the body
Phenomenon that mankind would rather forgot

Shadows and cries
Are found together trapped inside the world
Hateful was your life in the past
To torment someone is your present destiny

I feel pleasure seeing your agony
It burst my insane subconscious
From life I took nothin' but insults
From death I got irrational pleasure

Is it possible to feel satisfied after death?
Yeah, life has marked you with despair and takedown
Death welcomes you as a seed lost in oblivion
As a bastard son the world has rejected

Life betrays you on each step
On each body that faces you

On each soul that meets you
On each tomb that is closed
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
vector<int> ans;
int ar[N];

bool is_extreme(int ps){
	if (ar[ps]>ar[ps-1]&&ar[ps]>ar[ps+1])
		return true;
	if (ar[ps]<ar[ps-1]&&ar[ps]<ar[ps+1])
		return true;
	return false;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  ans.clear();
	  for (int i=1;i<=n;i++){
		  cin>>ar[i];
	  }
	  for (int i=1;i<=n;i++){
		  if (i==1||i==n||is_extreme(i))
			  ans.push_back(i);
	  }
	  cout<<ans.size()<<endl;
	  for(int i=0;i<ans.size();i++){
		  if (i)
			  cout<<" ";
		  cout<<ar[ans[i]];
	  }
	  cout<<endl;
  }
  cin.get(); cin.get();
  return 0;
}