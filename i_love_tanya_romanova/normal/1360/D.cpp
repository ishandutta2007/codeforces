/*
So nice to meet you, the pleasure's mine
Not very often I'm feeling left behind
Don't speak the language as many do
The sound takes me far

Fighting the silence of chosen sanctity
A choice I made alone
Am I misled by the selfish blinding need
My dreams all meet again
Once again
Once again

The star is burning but the flame is gone
I'll take a new look as I'm hanging on
As the world keeps turning, the faith is gone
The crimes of my age

Fighting the silence of chosen sanctity
A choice I made alone
Am I misled by the selfish blinding need
My dreams all meet again
Once again
Once again

Fighting the silence of chosen sanctity
A choice I made alone
Am I misled by the selfish blinding need
My dreams all meet again

Fighting the silence of chosen sanctity
A choice I made alone
Am I misled by the selfish blinding need
My dreams all meet again
Once again
Oh, once again
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

const int N = 110031;

int tests,n,k;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>k;
	  int ans=1;

	  for (int i=1;i*i<=n;i++){
		  if (n%i)
			  continue;
		  if (i<=k)
			  ans=max(ans,i);
		  if (n/i<=k)
			  ans=max(ans,n/i);
	  }
	  cout<<n/ans<<endl;
  }

  // cin.get(); cin.get();
  return 0;
}