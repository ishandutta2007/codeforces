/*
Oh no - they're at it again
Looking inside my secrets
Coming through cracks before I mend the wall

Get out - cause you're breaking the law
How did you ever find me
Places where I can hide can't get much smaller

I have invisible dreams
Where no one can touch me
Maybe I'll find a way to disappear

No one moves - and no one dies
Just the eyes

I've run as fast as I can
Thinking they'll never catch me
What a waste of breath a waste of time

Feel like digging a hole
Going in even deeper
Maybe they just can't see what just can't shine

I'll be lost - so no goddbyes
If no one moves then nothing dies
Just the eyes

Oh no - they've done it again
Sending out the detectives
Searching for signs of life and that means me

In my invisible dreams
When no one is watching
I'd make the whole world blind and I'd be free

I'll be lost - so no replies
If no one looks then no one dies
Just the eyes
Those eyes

Magic numbers
Even sacrifice
I can't find a way
Cause nothing stops the eyes
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

int n,a[N],w1[N],w2[N];
int cnt[N];
int b[N];
int ans;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n;
  for (int i=1;i<=n;i++){
	  cin>>a[i];
	  w1[a[i]]=i;
  }
  for (int i=1;i<=n;i++){
	  cin>>b[i];
	  w2[b[i]]=i;
  }

  for (int i=1;i<=n;i++){
	  int dif=w1[i]-w2[i];
	  if (dif<0)
		  dif+=n;
	  cnt[dif]++;
  }

  for (int i=0;i<=n;i++){
	  ans=max(ans,cnt[i]);
  }
  cout<<ans<<endl;


  cin.get(); cin.get();
  return 0;
}