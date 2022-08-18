/*
There is this face in the still water
I can't remember ever wearing
Like fingerprints on your heart
Reading out the last lines of code
To the untrained eye a secret
I bled away the last of you

Sought trust in shapes of combined results
That trickles from a less than solid case
Fought off attacks of resurfaced lust
Burn the gracing grounds

No, what will give in first?
The body or the lash
Monochromatic stains
No, who will cave in first?
The leader or the fake
Monochromatic stains, oh!

This pile of ashes of a soul
Informant pokes abound
These sickly little fingers
Get away from me

Tread not the path of least restraint
Each piece of evidence a lie, a lie
The body, the face all items in place
I don't remember a thing

No, what will give in first?
The body or the lash
Monochromatic stains
No, who will cave in first?
The leader or the fake
Monochromatic stains

A sacrifice made to the loss of mind
Folly a man's demise

Track now the stains that allow my fall
Sickening, the sight of it all
Never shall I claim my innocence
I just was not there

No, what will give in first?
The body or the lash
Monochromatic stains
No, who will cave in first?
The leader or the fake
Monochromatic stains
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

const int N = 600031;

int tests;
int a,b,c,d,x,y,x1,y1,x2,y2;

int solver(int d,int u,int start,int l,int r){
	l-=start;
	r-=start;
	if (d+u==0)
		return true;
	if (l==0&&r==0)
		return false;
	int final=-d+u;
	return (final>=l&&final<=r);
}

int main() {
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>a>>b>>c>>d;
	  cin>>x>>y>>x1>>y1>>x2>>y2;
	  if (solver(a,b,x,x1,x2)&&solver(c,d,y,y1,y2))
		  cout<<"YES"<<endl;
	  else
		  cout<<"NO"<<endl;
  }


  //    cin.get(); cin.get();
  return 0;
}