/*
Towards the rich archaic heavens; towards the lack diorama
you are the artist and the texture
that plays with the mantle of the Earth

When the bleakest of powders
lie rooted to the starched stones
and roots that feed the peaking trees
embrace the sleeping shores

Archaic pearls of sleep and death
the voice of December losing its breath
and the floweryard of whit and grey is haunted

White as the down of flaking snow,
the heroic emblems of life

Green is the color of my death
as the winter-guise I swoop towards teh ground
Green is the landscape of my sorrowfilled passing

We are In Flames,
towards the dead archaic heavens
We are the mantle and the texture
the alters the mantle of the Earth
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

const int N = 1000031;

map<long long,long long> memo;
int n,k,z,a[N];
int tests;

long long solve(int ps,int dep, int last_left,int ttl_left){
	if (ps<1||ttl_left>z||last_left>1)
		return -1e18;
	if (dep==k)
		return 0;
	long long ID=1ll*ps*(1ll<<40)+1ll*dep*(1ll<<20)+last_left*8+ttl_left;
	if (memo.find(ID)!=memo.end())
		return memo[ID];
	long long best_res=-1e18;
	best_res=max(best_res,a[ps-1]+solve(ps-1,dep+1,last_left+1,ttl_left+1));
	best_res=max(best_res,a[ps+1]+solve(ps+1,dep+1,0,ttl_left));
	memo[ID]=best_res;
	return best_res;

}
int main() {
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>k>>z;
	  for (int i=1;i<=n;i++){
		  cin>>a[i];
	  }
	  memo.clear();
	  cout<<solve(1,0,0,0)+a[1]<<endl;
  }

  cin.get(); cin.get();
  return 0;
}