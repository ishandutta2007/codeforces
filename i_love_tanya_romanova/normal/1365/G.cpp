/*
I'm lonely and abandoned
Washed up, left for dead
I'm lost inside the desert
Of every word you said

Like a nuclear reactor
Or TNT
I'm thinking about the times
When you lied to me

All the innuendo
Caught up on your hook
I was just a name
In your little black book

Ah, I'll get even with you

I'm bitter and I'm twisted
I haven't slept in days
I'm lonely and I'm angry
I can't make it go away

I'm like a bomb that's ticking
I got voices in my head
I got a doll with needles in
Wishing you were dead

I'll get you back somehow
That's what I'm gonna do
I'll get you back somehow
Your nightmare coming true

Ah, I'll get even with you
Ah, that's what I'm gonna do
Gonna get even with you

You better look behind you
'Cause there I'm gonna be
I'll be standing in the shadows
With who I used to be

He's slightly schizophrenic
Me and me and me and me agree
That you are gonna pay
For what you did to me

Ah, I'll get even with you
Gonna get even with you
Ah, that's what I'm gonna do
I'm gonna do
Ah, I'll get even with you
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

int pcount(int x){
	if (x==0)
		return 0;
	return pcount(x/2)+x%2;
}

vector<int> candidates;

int n;
vector<int> query[20];
long long or_value[N];

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  //ios_base::sync_with_stdio(0);
  // cin.tie(0);

  for (int i=0;i<(1<<13);i++){
	  if (pcount(i)==6){
		  candidates.push_back(i);
	  }
  }

  cin>>n;

  for (int i=0;i<13;i++){
	  for (int j=0;j<n;j++){
		  if (candidates[j]&(1<<i)){
			  query[i].push_back(j);
		  }
	  }
  }

  for (int i=0;i<13;i++){
	  if (query[i].size()==0)
		  continue;
	  cout<<"? ";
	  cout<<query[i].size();
	  for (int j=0;j<query[i].size();j++){
		  cout<<" "<<query[i][j]+1;
	  }
	  cout<<endl;
	  cin>>or_value[i];
  }

  cout<<"!";
  for (int i=0;i<n;i++){
	  long long res=0;
	  for (int j=0;j<13;j++){
		  if (candidates[i]&(1<<j))
			  continue;
		  res|=or_value[j];
	  }
	  cout<<" "<<res;
  }
  cout<<endl;


  cin.get(); cin.get();
  return 0;
}