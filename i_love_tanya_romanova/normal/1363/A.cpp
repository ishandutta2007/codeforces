/*
And here the air that I breathe isn't dead
Enter life of what's still here
Close the door away from near
Shrouded in autumn's graven ascension
Thought the bridge was over now
Lost the track astray somehow
Who's painting my life in sorrow blue

A relief for a dislocated mind
Shelter for thoughts
Asylum for my soul
This place is the only I need to know

And here the air that I breathe isn't dead
Enter life of what's still here
Close the door away from near
Shrouded in autumn's graven ascension
Thought the bridge was over now
Lost the track astray somehow
Who's painting my life in sorrow blue

Salvation for a lonely sinking kind
All my duties be done
A few years of take
Never leaving again you're forever

And here the air that I breathe isn't dead
Enter life of what's still here
Close the door away from near
Shrouded in autumn's graven ascension
Thought the bridge was over now
Lost the track astray somehow
Who's painting my life in sorrow blue
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

#define bs 998244353

const int N = 610031;

int tests,n,x,cnt[N];
int val;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for(;tests;--tests){
	  cin>>n>>x;
	  cnt[0]=cnt[1]=0;
	  for (int i=1;i<=n;i++)
	  {
		  cin>>val;
		  cnt[val%2]++;
	  }
	  int found=0;
	  for (int i=0;i<=x;i++){
		  int j=x-i;
		  int rem=j%2;
		  if (rem==1&&i<=cnt[0]&&j<=cnt[1])
			  found=1;
	  }
	  if (found)
		  cout<<"Yes"<<endl;
	  else
		  cout<<"No"<<endl;
  }

  cin.get(); cin.get();
  return 0;
}