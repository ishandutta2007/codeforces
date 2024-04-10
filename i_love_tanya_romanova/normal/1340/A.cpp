/*
Blisters on my fingers, blisters on my brain
Blisters on the voices, crazy makes insane
There's an angry sea, an ocean in my eyes
The waves are rolling, I'm becoming blind

I won't be taken, won't take myself
Kicking and screaming, have to knock me off the shelf
Feels like illusion, is this taking place?
Disease of confusion, stripped of our grace

Don't wanna believe it, these endless miles
Never destination, just more denial
More denial!

Some resolution, some justice tied
To this collusion hiding in plain sight
Say see-ya later, never say goodbye
This is a little trick I play on my own mind

I am a recluse in search of new friends
How they gonna find me? That's where the road ends
Off in the distance, leviathans
50 foot and breaking on our innocence

Don't wanna believe it, these endless miles
Never destination, just more denial
More denial!

I can't believe it, these endless lies
Never destination, just more denial
More denial

When you make the drop, the gaping maw
When you make the drop, the gaping maw
Keeps us alive, should we survive
When you make the drop, the gaping maw
Keeps us alive, should we survive
When you make the drop, the gaping maw

Thank you Bob Honey, thanks Paul Theroux
If I ever did, to this place let me go
Off in the distance, leviathans
50 foot and breaking on my innocence

I won't be taken, won't take myself
Kicking and screaming, have to knock my off the shelf
Say see-ya later, never say goodbye
This is a little trick I play on my own mind

Don't wanna believe it, these endless miles
Never destination, just more denial

She was a singer in a rock-n-roll band
Had command of all her voices
Turned herself into a hologram
It all came down to choices

So I say til then, never say goodbye
A little trick I play, on my mind
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

const int N = 500031;

int tests,n,ar[N],used[N],where[N];

bool valid(){
	int cur=1;
	while (cur<=n){
		int ps=where[cur];
		for (int i=ps;;i++){
			if (used[i])
				break;
			used[i]=1;
			if (ar[i]-ar[ps]!=i-ps)
				return false;
			cur++;
		}
	}
	return true;
}

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
		  where[ar[i]]=i;
	  }
	  for (int i=1;i<=n;i++)
	  {
		  used[i]=0;
	  }
	  used[n+1]=1;
	  if (valid()){
		  cout<<"Yes"<<endl;
	  }
	  else
	  {
		  cout<<"No"<<endl;
	  }
  }

  // cin.get(); cin.get();
  return 0;
}