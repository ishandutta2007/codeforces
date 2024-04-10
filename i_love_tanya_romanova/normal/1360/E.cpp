/*
And my words will be here when Im gone
As Im fading away against the wind
And the words you left me linger on
As Im failing again now, never to change this

And Im sympathetic,
never letting on I feel the way I do
As Im falling apart again at the seam

And it seems Im alone here, hollow again
As Im flailing again against the wind
And the scars I am left with swallow again
As Im failing again now, never to change this

And Im sympathetic,
never letting on I feel the way I do
As Im falling apart again at the seam
And Im sympathetic,
never letting on I feel the way I do
As Im falling apart again at the seam

The same old feelings are taking over
and I cant seem to make them go away
And I cant take all the pressure sober,
but I cant seem to make it go away
The same old feelings are taking over
and I cant seem to make them go away
And I cant take all the pressure sober
(I cant make it go away. I cant make it go away)

And Im sympathetic,
never letting on I feel the way I do
As Im falling apart again at the seam
And Im sympathetic,
never letting on I feel the way I do
As Im falling apart again at the seam
And Im falling, falling, falling,
falling, falling, falling, falling
Apart again at the seam.
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

int tests,n,board[131][131];

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;

	  for (int i=0;i<n;i++){
		  string st;
		  cin>>st;
		  for (int j=0;j<n;j++){
			  board[i][j]=st[j];
		  }
	  }

	  int ok=1;
	  for (int i=0;i<n;i++){
		  for (int j=0;j<n;j++){
			  if (board[i][j]=='0')
				  continue;
			  if (i==n-1||j==n-1)
				  continue;
			  if (board[i+1][j]=='1'||board[i][j+1]=='1')
				  continue;
			  ok=0;
		  }
	  }
	  if (ok)
		  cout<<"YES"<<endl;
	  else
		  cout<<"NO"<<endl;
  }

  // cin.get(); cin.get();
  return 0;
}