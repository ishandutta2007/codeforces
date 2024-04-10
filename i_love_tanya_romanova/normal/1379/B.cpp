/*
Immersed in light, broken in flight,
Here comes that scene again,
Not another sleepless night.
Scripted yet stuck on every line,
Upon my face a look of pure surprise,
I thought I'd be fighting fire.

How it's changed from my dream,
Did I stray from the path laid out for me?
How it's changed,
Did I fail in some way?

Easy to plot a course divine,
A simple graph cant cover ever line,
And I don't see what I don't know.
Some truths are harder to perceive,
The color has been drained now from my eyes,
Staring into endless time...
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

const int N = 200031;

long long tests,l,r,m,low,hi,ans_a,ans_b,ans_c;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>l>>r>>m;
	  low=m-r+l;
	  hi=m+r-l;
	  for (int a=l;a<=r;a++){
		  long long V=low/a+(low%a>0);
		  if (V==0)
			  ++V;
		  V*=a;
		  //cout<<a<<"@"<<V<<" "<<low<<" "<<hi<<endl;
		  if (V>=low&&V<=hi){
			  ans_a=a;
			  if (m>V){
				  ans_c=l;
				  ans_b=l+(m-V);
			  }
			  else
			  {
				  ans_c=r;
				  ans_b=r-(V-m);
			  }
		  }
	  }
	  cout<<ans_a<<" "<<ans_b<<" "<<ans_c<<endl;

  }
  cin.get(); cin.get();
  return 0;
}