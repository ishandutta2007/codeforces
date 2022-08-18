/*
A currency of heartache and sorrow
The air we breathe is stale with mold
To shadows we are slaves digging deeper every day
But emptiness is growing so old

Headlamps light the tunnels we wander
They shimmer and they dance on the walls
We're lost inside these caves as the chances of escape
Grow slimmer 'til there's no chance at all

This ink, it travels from the page
Up my hand and to my veins
Choking on those stories I've told
If there are words here left to say
I just want to let you know

I'm falling on my knees right now
I'm covered in the mess I made
These colors used to wash right out
But now they are a part of me
And I've been searching for a remedy
When all along it's been in front of me
I need you here, I need you now
Right now

We traffic in the blackest of markets
Trade misery like diamonds and gold
The angst that we exchange for applause or petty praise
Is finally now taking its toll

But there's a world above the ground
A life that we can lead
We're washing off the dirt from our clothes
I don't want to live without
I just wanna let you know

I'm falling on my knees right now
I'm covered in the mess I made
These colors used to wash right out
But now they are a part of me
And I've been searching for a remedy
When all along it's been in front of me
I need you here, I need you now
Right now
Right now

(Black stains) they mark me like a letter
(Won't fade) cracking under the pressure
(Black stains) nothing stays gold

There's a world above the ground
A life that we can lead
But we're lost deep down in these holes
And I've seen the way out
Now I just want to let you know

I'm falling on my knees right now (black stains)
I'm covered in the mess I made (wont fade)
These colors used to wash right out (black stains)
But now they are a part of me
And I've been searching for a remedy
When all along it's been in front of me
Your voice it washes the stains away
(Wash the stains away)
Woo oh oh oh
(Wash the stains away)
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
string st;

int get_lo(int ps){
	return st[ps];
}

int get_hi(int ps){
	if (ps+k>=st.size())
		return st[st.size()-1];
	return st[ps+k-1];
}


int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>k;
	  cin>>st;
	  sort(st.begin(),st.end());
	  string ret;
	  ret="";
	  ret=st[k-1];
	  if (st[k-1]!=st[0]){
		  cout<<st[k-1]<<endl;
		  continue;
	  }
	  if (st[k]==st[st.size()-1]){
		  for (int i=k;i<st.size();i+=k){
			  ret+=st[i];
		  }
		  cout<<ret<<endl;
		  continue;
	  }
	  for (int i=k;i<st.size();i++){
		  ret+=st[i];
	  }
	  cout<<ret<<endl;
  }
  // cin.get(); cin.get();
  return 0;
}