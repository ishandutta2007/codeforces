/*
This world in sin, of plagues and pain
We fall, we crawl
No war, no more
Them eyes, they bled for a thousand days
Them eyes, they bled in a thousand ways

This war was heard around the world
It made our ways insane again
Their mouths were shut
They blot out the sun
They fought this war like never before

Today i wake, the wall has fallen
They worship no more
And the temple is gone
Them eyes will bleed the tears of sin
All ears will hear, unleash within

Hearts of darkness
Where madness is endless
Hearts of darkness
Where badness is endless
Hearts of darkness
Where hate is endless
Hearts of darkness
Where hope is hopeless...

Hearts of darkness
Where madness is endless
Hearts of darkness
Where badness is endless
Hearts of darkness
Where agony is endless
Hearts of darkness
Where hearts are heartless...
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

const int N = 10000031;

int pr[N];
int n,ar[500031],ans1[500031],ans2[500031];

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  pr[1]=1;
  for (int i=2;i<N;i++){
	  if (pr[i]==0){
		  for (int j=i;j<N;j+=i){
			  pr[j]=i;
		  }
	  }
  }
  cin>>n;
  for (int i=1;i<=n;i++){
	  cin>>ar[i];
	  ans1[i]=ans2[i]=-1;

	  int x=pr[ar[i]];
	  if (ar[i]==1)
		  continue;
	  int prod=1;
	  while (ar[i]%x==0){
		  ar[i]/=x,
		  prod*=x;}
	  if (ar[i]!=1){
		  ans1[i]=prod;
		  ans2[i]=ar[i];
	  }
  }

  for (int i=1;i<=n;i++){
	  if (i>1)
		  cout<<" ";
	  cout<<ans1[i];
  }
  cout<<endl;
  for (int i=1;i<=n;i++){
	  if (i>1)
		  cout<<" ";
	  cout<<ans2[i];
  }
  cout<<endl;

  cin.get(); cin.get();
  return 0;
}