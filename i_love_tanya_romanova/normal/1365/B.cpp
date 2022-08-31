/*
Bless me father I must go away
To save us from the one's who don't believe
Confess me father I have sin but maybe
Angels really sing
Fot the man who would be king

We laugh at your religion
You people of the sand
We have no superstition
You can read it in our hands

Forgive me father for the change we bring
But it's all for the man who would be king

Don't leave a body standing
Not the holy not the small
Deliver us from evil
If it's yours we want it all

Lately father I've been wondering
Is the devil just the man who would be king

How can right be ever wrong
We are glory we are stronger than you

We never got an answer
But it's just too late to ask
The bloody flag was waving
And our hearts just ran too fast

Curse me father for the chains we bring
And don't believe the man who would be king

We never got an answer
Cause the question slipped my mind
I've been so busy killing
That I haven't found the right time
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

const int N = 610031;

int tests,n,a[N];
int c[N];
int ok;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  for (int i=1;i<=n;i++){
		  cin>>a[i];
	  }
	  c[0]=c[1]=0;
	  for (int i=1;i<=n;i++){
		  int val;
		  cin>>val;
		  c[val]++;
	  }
	  int ok=1;
	  for (int i=2;i<=n;i++){
		  if (a[i]<a[i-1])
			  ok=0;
	  }
	  if (c[0]>0&&c[1]>0)
		  ok=1;

	  if (ok)
		  cout<<"Yes"<<endl;
	  else
		  cout<<"No"<<endl;
  }

  cin.get(); cin.get();
  return 0;
}