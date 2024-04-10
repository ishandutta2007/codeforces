/*
Land of enchantment and fake reality
Where they put in vitro breeding machines
On the cover of a magazine
Trailer trash and human freaks
They grab their minute of fame
And still the puppets watch
And everybody knows the names
That's why I say

Burn, hollywood, burn
When it's dead and gone we'll never miss a thing
Burn, hollywood, burn
No more rotten to the core little sweet sixteens
Burn. hollywood, burn
Time's running out on their minute of fame
Let's douse the fire by pissing on the flames

So young, bitch and famous
Hotel heiress, glamour queen
The only reason we know your name
Is bad night vision pornography
From the "real" housewives of botox hills
To the cunts of Bel-Aire
You can't look away from the cathode ray
Why does anybody fucking care

Burn, hollywood, burn
When it's dead and gone we'll never miss a thing
Burn, hollywood, burn
No more rotten to the core little sweet sixteens
Burn. hollywood, burn
Time's running out on their minute of fame
Let's douse the fire by pissing on the flames
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

const int N = 300031;

vector<int> divs[N];
int tests,n,good[N];
int p[N],c[N];
int used[N];
vector<int> comp;
int ans;

void trace(int v){
	if (used[v])
		return;
	used[v]=1;
	comp.push_back(c[v]);
	trace(p[v]);
}

void check_it(vector<int> v,int block){
	for (int i=0;i<block;i++){
		int ok=1;
		for (int j=i;j+block<v.size();j+=block){
			if (v[j]!=v[j+block])
				ok=0;
		}
		if (ok)
			good[block]=1;
	}
}

void validate(vector<int> comp)
{
	for (int i=0;i<divs[comp.size()].size();i++){
		int candidate=divs[comp.size()][i];
		check_it(comp,candidate);
	}
}

int main() {
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  for (int i=1;i<=200000;i++){
	  for (int j=i;j<=200000;j+=i){
		  divs[j].push_back(i);
	  }
  }

  cin>>tests;
  for (;tests;--tests){
	 cin>>n;
	 for (int i=1;i<=n;i++){
		 good[i]=0;
	 }
	 for (int i=1;i<=n;i++){
		 cin>>p[i];
	 }
	 for (int i=1;i<=n;i++){
		 cin>>c[i];
	 }
	 for (int i=1;i<=n;i++){
		 used[i]=0;
	 }
	 for (int i=1;i<=n;i++){
		 if (used[i])
			 continue;
		 comp.clear();
		 trace(i);
		 validate(comp);
	 }
	 for (int i=1;i<=n;i++){
		 if (good[i])
		 {
			 ans=i;
			 break;
		 }
	 }
	 cout<<ans<<endl;

  }

  //    cin.get(); cin.get();
  return 0;
}