/*
You never told me where you came from
You never told me your name
I didn't know if you were legal tender
But I spent you just the same
And I didn't know it could happen to me
But I fell in love in the first degree

It was love at first feel
Love at first feel
Love at first feel
I was touched with too much

They told me it was disgustin'
They told me it was a sin
They saw me knocking on your front door
Saw me smile when you let me in
You and me baby we're all alone
Let's get something goin'
While your mum and dad ain't home

Love at first feel
It was love at first feel, just like a sin
Love at first feel
Feel good just like I knew it would, ah ah

Love at first feel
It was love at first feel
Love at first feel
It was love at first feel
Love at first feel, lightning bolts in my fingertips
Love at first feel
Love, whoo
Love at first feel
Love at first feel
Love at first feel
Love at first feel
Love at first feel
Love at first feel
Love at first feel
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

const int N = 210031;

int tests,n,m,k;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>m>>k;
	  int we_got=min(n/k,m);
	  m-=we_got;
	  --k;
	  int othr=m/k+(m%k>0);
	  cout<<we_got-othr<<endl;
  }

  // cin.get(); cin.get();
  return 0;
}