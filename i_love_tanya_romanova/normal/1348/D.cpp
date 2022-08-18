/*
Settling in here for the long haul
Cant hide forever is what they say
In with the wind, out with a bang
Meanwhile nothing has changed

With each word slowly uttered
A storm brews in her eyes
A missed shot at the buzzard
Time, whether wasted
Or well-spent, is still time

We are not brave, we are not wise
We stand at the end of the longest lines
But we stand here all together
We have been damned, we have survived
We came back to homes we dont recognize
But we return here all together

Moments of clarity here are short-lived
Bled through the bandages again
When is a lie no longer white
But black as a day without sun

Passed out in a gutter
Woke up in your arms
Nursed back and recovered
The same touch that heals me
Left a scar

We are not brave, we are not wise
We stand at the end of the longest lines
But we stand here all together
We have been damned, we have survived
We came back to homes we dont recognize
But we return here all together

And the world works in ways that I never have claimed to know
We got out in front of the weather but it followed
The view from here isnt better but its all we know
Its all we know

We are not brave, we are not wise
We stand at the edge of the border lines
But we stand here all together
We have been damned, we have survived
Who we've become you wont recognize
But we became them all together
All together
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

int tests,n;
vector<int> moves;

bool solver(int days){
	moves.clear();
	long long cur,need;

	cur=1;
	need=n-days;
	for (int i=1;i<days;i++){
		long long need_here=need/(days-i);
		long long take_here=min(need_here,cur);
		moves.push_back(take_here);
		cur+=take_here;
		need-=take_here*(days-i);
	}
/*	cout<<days<<endl;
	for (int i=0;i<moves.size();i++){
		cout<<moves[i]<<" ";
	}
	cout<<endl;
	cout<<need<<endl;*/
	return (need==0);
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  for (int ans=2;;ans++){
		  if (solver(ans)){
			  cout<<ans-1<<endl;
			  for (int i=0;i<moves.size();i++){
				  if (i)
					  cout<<" ";
				  cout<<moves[i];
			  }
			  cout<<endl;
			  break;
		  }
	  }
  }

  // cin.get(); cin.get();
  return 0;
}