/*
It's coming over you!
Can you see the phosphorescence of the factory
Moving away, out of this territory
The systems became overload
The warning lights were on that night
Nobody knew what was going on
But it will be here for months
Or even years
It's coming over me!
The ugly underside of the nuclear energy
Brings us today this atomic calamity
The malfunction of the instruments
For this blunders we have to go to hell
It's coming over us
Don't be scared, the engines exploded
But it's just a technological risk
And this thing will continue throughout the ages
The evolution can't run without damage
Mother nature can't hear you
The China Syndrome will die much later than you...
The China Syndrome...
In the air, it smells bad
Feel the disease, the nuclearchy
We're lucky, we'll die young
It's hard to endure, to be a mutant
The transformation, is almost complete
Research has no end, containing the power
The dangerous results, it's not our fault
Create the force, we got no fear
Lock the doors, we're engineers
Awaiting to suffocate, purchasing the program
Vomiting the pollution, of energy games
Create the force, we got no fear
Lock the doors, we're engineers
Welcome to the China Syndrome
It's an over... overreaction!
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
long long mx;
long long required_increase;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  for (int i=1;i<=n;i++){
		  cin>>ar[i];
	  }
	  mx=ar[1];
	  required_increase=0;
	  for (int i=2;i<=n;i++){
		  required_increase=max(required_increase,mx-ar[i]);
		  mx=max(mx,0ll+ar[i]);
	  }
	  int ans=0;
	  long long can_add=0;
	  for (int i=1;i<=35;i++){
		  if (can_add>=required_increase)
			  break;
		  ans++;
		  can_add+=(1ll<<(i-1));
	  }
	  cout<<ans<<endl;

  }

  // cin.get(); cin.get();
  return 0;
}