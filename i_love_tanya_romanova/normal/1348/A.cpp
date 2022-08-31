/*
Do you see the world in different colors?
Do you see the world in black and gray?
Alone in your thoughts
How many others have stood where you stand
Where you stand today?
Have stood where you stand
But, oh, can you

Wait for me now?
To take off this crown
To break all these vows
Don't you know?
Wait for me now
The air's running out
Wait for me, wait for me
Wait for me, wait for me now

A promise of safe return I delivered
But the ocean is wider than I first guessed
When roads disappeared, I followed the rivers
But somehow got in over my head
So a deep breath I'm taking

Wait for me now
To take off this crown
To break all these vows
Don't you know?
Wait for me now
The air's running out
Wait for me, wait for me
Wait for me, wait for me now

A lost dream of what could have been
A house on fire, a tangled web
The key turns to find the locks all changed
In time to hear the back door slam
A sound that to this day I can't forget
The colors drain to black and gray

Wait for me now
Take off this crown
To break all these vows
Don't you know?
Wait for me now
The air's running out
Wait for me, wait for me
Wait for me, wait for me now
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

long long tests,n;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  long long lo=0;
	  long long hi=0;
	  for (int i=1;i<=n;i++){
		  if (i<n/2||i==n)
			  lo+=(1ll<<i);
		  else
			  hi+=(1ll<<i);
	  }
	  cout<<abs(lo-hi)<<endl;
  }

  // cin.get(); cin.get();
  return 0;
}