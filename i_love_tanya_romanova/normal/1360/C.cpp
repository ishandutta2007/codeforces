/*
Circusmaximus
Was a time, in a land, at a place faraway,
In a place we know as Rome
Many years, torn away, fades the distant memory

Try to think, what was life, when you knew one thing,
that was please your king or die
Was a way, as a slave that you could become free,

Masses will bet on his name,
Women lust after his fame

The gladiators face is masked by pain
His wife and child will be slain
Promises someday he'll take revenge
Against the one who's to blame

The one who's to blame

Was a time, that he led, many men through the mud
All in honor of thier king
Counts the days, till he's done, where he wants to go is home

Then he's called to the tent, where he finds he is dead
That was murdered by his son
In his grief, then he turns and announces he is free

There is a price on his head
He then escapes with tears shed

The gladiators face is ripped by pain
His wife and child have been slain
Vows that someday he will take revenge
Against the one who's to blame

The ones who's to blame

We will live if we work as one
He must stay alive to meet them

The gladiators face is ripped by pain
He is well on his way
Falls beside the one, he has revenged
Strength and honor, no shame

Honor No shame
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

int tests,n,cnt[N];
int ar[N];

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  cnt[0]=cnt[1]=0;
	  for (int i=0;i<n;i++){
		  cin>>ar[i];
		  cnt[ar[i]%2]++;
	  }
	  int ok=0;
	  if (cnt[0]%2==0)
		  ok=1;
	  for (int i=0;i<n;i++){
		  for (int j=i+1;j<n;j++){
			  if (abs(ar[i]-ar[j])==1)
				  ok=1;
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