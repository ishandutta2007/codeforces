/*
As the pages burn, secrets can't be unlearned
Silence can't be unheard
Knowledge is burden, power is upon us
As the pages burn
Your memories fade
Freed from the grip of reality
Rejecting cognition
As the pages burn
Sinking in a pool of ether
the past is washed clean

Rip apart the world
word by word
inch by inch

Sever your time line
silence your conscience

Sweet amnesia
Here to free you
As the pages burn
All your trials
Solved by fire
as the pages burn

As smoke fills the room
Soon to pass, heavy gloom
The wind will whisk away the past
a blank page stares at you
Nothing left, where to start?
A second chance carries expectation
The books you'd written no longer exist
The future is in your pen
Ink to paper, now begin

Rewriting history starting now
Erase the misery
Let the flames eat your doubts
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
int cnt[N];
string st;

int gcd(int a,int b){
	while(a&&b)a>b?a%=b:b%=a;
	return a+b;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>k;
	  for (int i='a';i<='z';i++){
		  cnt[i]=0;
	  }
	  cin>>st;
	  for (int i=0;i<st.size();i++){
		  cnt[st[i]]++;
	  }
	  int ans=0;
	  for (int len=1;len<=n;len++){
		  int blocks=gcd(len,k);
		  int per_block=len/blocks;
		  int TTL=0;
		  for (int i='a';i<='z';i++){
			  TTL+=cnt[i]/per_block;
		  }
		  if (TTL>=blocks)
			  ans=len;
	  }
	  cout<<ans<<endl;
  }

  cin.get(); cin.get();
  return 0;
}