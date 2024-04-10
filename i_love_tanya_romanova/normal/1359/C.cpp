/*
Let the weakness set in this world I know
Days cannot hold me, I blur in between
Never fully engaged, the mind races between words
As far as I can get, away from it all
When indecision ends can life begin again

I am silence when the world screams out
I am escape when you reach out to me
I am panic
I am fear behind these walls that protect me
I am failure and resistance
I am lost where I belong
I am silence when the world screams
My insecurity extends to others talking about themselves
Fed with this poison of self righteous false confidence
It's in their eyes, it's in our lives

Set to the tune of darkness, this is one to hold
I cannot stop insanity from chasing down my thoughts
Linger in the mind for what now seems indefinite time
My mind is holding me down
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

long long tests,h,c,t;
long long ans;

long double my_abs(long double x){
	if (x<0)
		return -x;
	return x;
}

long double eval_temp(long long n){
	long long hot=(n+1)/2;
	long long cold=n-hot;
	return (hot*h+cold*c)*1.0/n;
}

void try_it(long long l){
	  long double here=eval_temp(l);
	 // cout<<my_abs(here-t)<<" "<<my_abs(eval_temp(ans)-t)<<endl;
	  if (my_abs(here-t)<my_abs(eval_temp(ans)-t))
		  ans=l;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>h>>c>>t;
	  ans=1;
	  try_it(2);

	  long long l,r;
	  l=1;
	  r=1e10;
	  while (l<r){
		  long long mid=l+r+1;
		  mid/=2;
		  long double here=eval_temp(mid*2-1);
		  if (here>=t)
			  l=mid;
		  else
			  r=mid-1;
	  }
	//  cout<<l<<" "<<eval_temp(l)<<" "<<eval_temp(ans)<<" "<<ans<<endl;
	  try_it(l*2-1);
	  try_it(l*2+1);
	  cout<<ans<<endl;
  }

  cin.get(); cin.get();
  return 0;
}