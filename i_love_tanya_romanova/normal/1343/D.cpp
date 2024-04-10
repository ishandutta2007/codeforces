/*
Rip out my heart and put it on the table
Read my life in the blood
I am waiting to answer your suffering pleas
As a deathly silence does curtail my remains

In the river of tears ruins blood from my eyes
Yet another morning is emptying my veins
Alone I seek, a tiny groove I stalk
In the river Lethe I slowly drown

Empty screams
To fill a new world
A place I've missed

Bodies are courses where maggots are turning
Souls are flames that are forever burning

Raging flames cover my corpse
Far from identity and remembrance
But the shades of my mind are still carrying
Colours of most beautiful kind

Around the cenotaph I am scattered
I am in the air you breathe
Let us forget me for awhile
And I bet you'll remember me no more...

Empty screams
To fill a new world
A place I've missed

Bodies are courses where maggots are turning
Souls are flames that are forever burning
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

int tests,n,k;
int ar[N];
int cnt_min[N],cnt_max[N],cnt_sum[N],pref_cnt_max[N],suf_cnt_min[N];

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>k;
	  for (int i=1;i<=n;i++){
		  cin>>ar[i];
	  }

	  for (int i=1;i<=k*2;i++){
		  cnt_min[i]=cnt_max[i]=cnt_sum[i]=pref_cnt_max[i]=suf_cnt_min[i]=0;
	  }

	  for (int i=1;i<=n/2;i++){
		  int othr=n-i+1;
		  cnt_sum[ar[i]+ar[othr]]++;
		  cnt_min[min(ar[i],ar[othr])]++;
		  cnt_max[max(ar[i],ar[othr])]++;
	  }

	  suf_cnt_min[2*k+1]=0;

	  for (int i=1;i<=k*2;i++){
		  pref_cnt_max[i]=cnt_max[i]+pref_cnt_max[i-1];
	  }
	  for (int i=k*2;i>=1;--i){
		  suf_cnt_min[i]=suf_cnt_min[i+1]+cnt_min[i];
	  }

	  int ret=n;
	  for (int new_sum=2;new_sum<=k*2;new_sum++){
		 int good_pairs=cnt_sum[new_sum];
		 int bad_pairs=pref_cnt_max[max(new_sum-k-1,0)]+suf_cnt_min[new_sum];
		 int ans=bad_pairs*2+(n/2-good_pairs-bad_pairs);
		 //cout<<new_sum<<"@"<<ans<<" "<<good_pairs<<" "<<bad_pairs<<endl;
		 ret=min(ret,ans);
	  }
	  cout<<ret<<endl;
  }
  // cin.get(); cin.get();
  return 0;
}