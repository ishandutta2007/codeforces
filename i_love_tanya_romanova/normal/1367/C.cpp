/*
The light dwindles down to nothing
As the candle sputters out
Just beyond the ebb and flow
Of a dark and restless heart

Alone again  facing the demons
In this hell of my own making
I will not let this moment define who I am
Now you see me, now you dont
I am strong, eternal
Now you see me, now you dont

Aching the wound now
I shelter in the melody
My ink runs from black to red
Screaming into the void

Alone again  facing the demons
In this hell of my own making
I will not let this moment define who I am
Now you see me, now you dont
I am strong, eternal
Now you see me, now you dont

Seemingly endless...
Like the wind, the stormy seas
I held the poison, I had the power
I will return...

Seemingly endless...
Like the wind, the stormy seas
I held the poison, I had the power
I will return...
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

#define bs 1020202009

const int N = 100031;

int tests,n,k;
string st;
set<int> ones;
set<int>::iterator it;

int get_prev(int x){
	it=ones.lower_bound(x);
	if (it==ones.begin())
		return -1e9;
	--it;
	return *it;
}

int get_next(int x){
	it=ones.lower_bound(x);
	if (it==ones.end())
		return 1e9;
	return *it;
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
	  ones.clear();
	  for (int i=0;i<st.size();i++){
		  if (st[i]=='1')
			  ones.insert(i);
	  }
	  int ans=0;
	  for (int i=0;i<st.size();i++){
		  if (get_prev(i)<i-k&&get_next(i)>i+k){
			  ans++;
			  ones.insert(i);
		  }
	  }
	  cout<<ans<<endl;
  }

  cin.get(); cin.get();
  return 0;
}