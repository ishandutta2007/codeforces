/*
Confront me unholy ones
Bastard saints scorn of the earth
I summon thee now poison me
Death under will burn in my soul

Exalt me enemies of the lamb
Intrude - We are of one
Under will, I walk the path of sin
With your spells I die again

Raise me from mortal
My will be your will
My words speak your words
Your pains raise me to bliss

What of this anger now
Received to lance your enemy
I feel the energy
The poison moves in me
I spill blood

Scorn of the earth, I witness
In rapture I'm born again
Scorn of the light, I bear scorn
In rapture I'm reborn
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

int tests,n,ar[N];

set<pair<int,int> > allowed,all_kinds;
set<pair<int,int> > ::iterator it;
int cnt[N];
int ans[N];

int solve(int span){
	for (int i=1;i<=n;i++){
		cnt[i]=0;
	}
	for (int i=1;i<=n;i++){
		cnt[ar[i]]++;
	}
	allowed.clear();

	for (int i=1;i<=n;i++){
		allowed.insert(make_pair(cnt[i],i));
	}
	for (int i=1;i<=n;i++){
		if (i>span){
			allowed.insert(make_pair(cnt[ans[i-span]],ans[i-span]));
		}

		it=allowed.end();
		if (it==allowed.begin())
			return false;
		--it;
		int id=(*it).second;
		if (cnt[id]==0)
			return false;
		allowed.erase(make_pair(cnt[id],id));
		cnt[id]--;
		ans[i]=id;
	}
	return true;
}

int main() {
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  for (int i=1;i<=n;i++){
		  cin>>ar[i];
	  }
	  int l,r;
	  l=1;
	  r=n;
	  while (l<r){
		  int mid=l+r+1;
		  mid/=2;
		  if (solve(mid))
			  l=mid;
		  else
			  r=mid-1;
	  }
	  cout<<l-1<<endl;
  }

  cin.get(); cin.get();
  return 0;
}