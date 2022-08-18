/*
I miss the warm embrace I felt
First time you touched me
Secure and safe in open arms
I should have known you'd crush me
A snake you were when we met
I loved you anyway
Pulling out your poisoned fangs
The venom never goes away
Serpent swims free in my blood
Dragons sleeping in my veins
Jackyl speaking with tongue
Roach egg laying in my brain
Once stalked beneath your shadow
Sleepwalking to the gallows
I'm the sun that beats your brow in
'til I finally threw the towel in
Never knowing if I'd wake up in a
Whirlpool got redundant
My brain was just some driftwood
In a cesspool I became dead
From a rock star to a desk fool
Was my destiny someone said
Love's a tide pool
Taste the waters life's abundant
Taste me
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

int tests;
long long n,m,cnt;
long long should_be_below;
vector<long long> banned;

long long eval(string st){
	long long res=0;
	for (int i=0;i<st.size();i++){
		res=res*2+st[i]-48;
	}
	return res;
}

bool bad(long long x){
	for (int i=0;i<banned.size();i++){
		if (banned[i]==x)
			return true;
	}
	long long count_below=x;
	for (int i=0;i<banned.size();i++){
		if (banned[i]<x)
			count_below--;
	}
	return (count_below!=should_be_below);
}

void show_it(long long x){
	for (int i=m-1;i>=0;--i){
		if (x&(1ll<<i))
			cout<<1;
		else
			cout<<0;
	}
	cout<<endl;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>m;
	  cnt=(1ll<<m)-n;
	  should_be_below=(cnt-1)/2;
	  banned.clear();
	  for (int i=1;i<=n;i++){
		  string st;
		  cin>>st;
		  banned.push_back(eval(st));
	  }

	  long long start=(1ll<<m)/2-150;
	  if (start<0)
		  start=0;
	  while (bad(start))
		  ++start;

//	  cout<<"!"<<should_be_below<<endl;

	  show_it(start);
  }

  // cin.get(); cin.get();
  return 0;
}