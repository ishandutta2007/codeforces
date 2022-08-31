/*
Toronto to Chicago down to New Orleans
Cross the Atlantic wind up in Aberdeen
Spain to Australia a daze in the heat
Then hack to Alaska sled dogs race to compete
Taxi the tarmac let's go
Leaving the ground the engine's groan
Into the blue sky we go
Flying, flying around the world
Flying, flying around the world
Brussels to Warsaw then down to Italy
Cross the Mediterranean gone to Galilee
Taxi the tarmac lets go
Leaving the ground the engine's groan
Into the blue sky we go
Flying, flying around the world
Flying, flying around the world
London to Paris then to Taipei
Down through the Philippines all in one day
Tel Aviv to Turkey then down through Greece
Back home to Canada to see our famous geese
Taxi the tarmac let's go
Leaving the ground the engine's groan
Into the blue sky we go
Flying, flying around the world
Flying, flying around the world
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

int tests,n;
int ar[N];
vector<int> entries[N];
int pref[N][202];
int here,ans;

int query(int val,int l,int r){
	return pref[r][val]-pref[l-1][val];
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	 cin>>n;

	 for (int i=1;i<=200;i++){
		 entries[i].clear();
	 }
	 ans=0;

	 for (int i=1;i<=n;i++){
		 cin>>ar[i];
		 entries[ar[i]].push_back(i);
	 }

	 for (int i=1;i<=n;i++){
		 for (int j=1;j<=200;j++){
			 pref[i][j]=pref[i-1][j];
		 }
		 pref[i][ar[i]]++;
	 }

	 for (int i=1;i<=200;i++){
		 int cnt=entries[i].size();
		 for (int side=0;side*2<=cnt;side++){
			 int fi,la;
			 if (side==0)
				 fi=1;
			 else
				 fi=entries[i][side-1]+1;
			 if (side==0)
				 la=n;
			 else
				 la=entries[i][cnt-side]-1;
			 for (int q=1;q<=200;q++){
				 here=query(q,fi,la);
				 ans=max(ans,side*2+here);
			 }
		 }
	 }
	 cout<<ans<<endl;
  }

  // cin.get(); cin.get();
  return 0;
}