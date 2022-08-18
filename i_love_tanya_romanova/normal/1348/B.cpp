/*
Hey, man now did you hear
Your final days are near?
In a free fall of fire and ice
And explosions in the sky

A fate that we deserve
There's no escape. No
Now it's your turn
Now it's your turn

It's been years
Since our luck ran out and left us here
Like broken mirrors
Ten million shards of glass and tears
But now we are
Awake enough to shatter what we hate
Like broken mirrors
Reflections of an unfamiliar face

Hey, hey!

Hey, man, you got the time?
Hey, can I trouble you for a light?
Who, me? No, I'm not the old town crier
I'm the one who sets it all on fire

A fate, yeah, that we deserve
And there's no escape. No
Now it's your turn
Now it's your turn

It's been years
Since our luck ran out and left us here
Like broken mirrors
Ten million shards of glass and tears
But now we are
Awake enough to shatter what we hate
Like broken mirrors
Reflections of an unfamiliar face

We hide from the mirrors
They might show our scars
And there is
(Don't hide your scars)
The person that we want to be
The people we are (the people we are)
Confront your reflection
Smash what you see
And let's restart
'Cause mirrors can't see your heart

It's been years
Since our luck ran out and left us here
Like broken mirrors
Ten million shards of glass and tears
But now we are
Awake enough to shatter what we hate
Like broken mirrors
Like broken mirrors
Like broken mirrors
Like broken mirrors
Like broken mirrors
Reflections of an unfamiliar face
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

int tests,n,k;
set<int> S;
int at_pos[N];
vector<int> ret;
int ar[N];

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>k;
	  S.clear();
	  for (int i=1;i<=n;i++){
		  cin>>ar[i];
		  if (S.find(ar[i])!=S.end())
			  continue;
		  S.insert(ar[i]);
		  at_pos[S.size()-1]=ar[i];
	  }

	  if (S.size()>k)
	  {
		  cout<<-1<<endl;
		  continue;
	  }
	  for (int i=S.size();i<k;i++){
		  at_pos[i]=1;
	  }

	  int ptr=1;
	  vector<int> ret;
	  while (ptr<=n){
		  int nxt=at_pos[ret.size()%k];
		  if (nxt==ar[ptr])
			  ++ptr;
		  ret.push_back(nxt);
	  }
	  cout<<ret.size()<<endl;
	  for (int i=0;i<ret.size();i++){
		  if (i)
			  cout<<" ";
		  cout<<ret[i];
	  }
	  cout<<endl;
  }

  // cin.get(); cin.get();
  return 0;
}