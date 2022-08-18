/*
Viscerated bodies
planted deep beneath the earth
They fertilize the soil
and feed for all theyre worth
Within the garden
of unearthly delights
True meaning of horrors found
and hells within our sights

[Chorus:]
He plants the seeds
The germinate
Black misdeeds, they pollinate
Within the garden of bleedings
where the devil waits
to introduce you to your fate

Endless orchards dot the land
of corpses up on spikes
Beautys in the eye of the
beheaded on a pike
Bathed in lakes of fire
until a cinders what remains
The stench of death it makes
the flowers bloom in his domain

[Chorus]

Bodies hang from branches
like grapes hang from the vine
Garlands made of human flesh
they decorate his shrine
On the wind and through the trees,
the cries of suffering
For this is the garden
of the king of the unclean
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

const int N = 300031;

int cnt[N];
long long pw[N];
int n;

int main() {
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  pw[0]=1;
  for (int i=1;i<N;i++){
	  pw[i]=pw[i-1]*10%bs;
  }

  cin>>n;
  for (int len=1;len<=n;len++){
	  long long ways_fi=10;
	  if (len!=n)
		  ways_fi=ways_fi*9*pw[n-len-1]%bs;

	  long long ways_la=10;

	  if (len!=n)
	  {
		  ways_la=ways_la*9*pw[n-len-1]%bs;
	  }
	  else
		  ways_la=0;


	  long long ways_mid;
	  if (len>=n-1)
		  ways_mid=0;
	  else
		  ways_mid=10*(n-len-1)*9*9*pw[n-len-2]%bs;


	  cout<<(ways_fi+ways_la+ways_mid)%bs<<endl;
//	  cout<<ways_fi<<" "<<ways_mid<<" "<<ways_la<<endl;

  }


  //    cin.get(); cin.get();
  return 0;
}