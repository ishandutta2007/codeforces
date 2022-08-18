/*
Evil imaginations of a time to come
Dreamly dead - Almost gone
Nocturnal visits from the beyond
I will travel down the Mountain of Doom

At the highest point visible
I behold the sun for the very last time
I see an awful sight with awful beings
As the sun goes down behind the Mountain of Doom

The Mountain of Doom
Has taken my life

Almost there
Trying to seize my mind
Still aware
Of their seek and find

I have lost hold of myself
Taken to the extent of my life
Eternal sleep in a dreamworld's coffin
Entombed beneath the Mountain of Doom

The Mountain of Doom
Has taken my life

Almost there
Trying to seize my mind
Still aware
Of their seek and find

Now I'm there
Enjoying my peace of mind
In this lair
Death is what you'll find
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

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  int P=2;
	  int sum=3;
	  int n;
	  cin>>n;
	  while (n%sum!=0){
		  P*=2;
		  sum+=P;
	  }
	  cout<<n/sum<<endl;
  }
  // cin.get(); cin.get();
  return 0;
}