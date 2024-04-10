/*
Bring the violence
It's significant
To the life
If you've ever known anyone

Bring the violence
It's significant
To the life
Can you feel it?

How do you sleep
When you live with your lies
Out of your mouth
Up from your mind
That kind of thinking
Starts a chain reaction
You are a time bomb ticking away

You need to release
What you're feeling inside
Let out the beast
That you're trying to hide
Step right up and be a part of the action
Go get your game face on
Because it's time to play

You're pushing and fighting your way
You're ripping it up

Bring the violence
It's significant
To the life
If you've ever known anyone

Bring the violence
It's significant
To the life
Can you feel it?

How do you live without playing the game
Sit on the side and expect to keep sane
Step right up and be a part of the action
Come get a piece of it before it's too late

Take a look around
You can't deny what you see
We're living in a violent society
Well my brother let me show you a better way
Get your game face on because it's time to play

You're pushing and fighting your way
You're ripping it up

Bring the violence
It's significant
To the life
If you've ever known anyone

Bring the violence
It's significant
To the life
Can you feel it?

Bring the violence
It's significant
To the life
If you've ever known anyone

Bring the violence
It's significant
To the life
Can you feel it?

Tell me what am I supposed to be
Another goddamn drone
Tell me what am I supposed to be
Should I leave it on the inside

Tell me what am I supposed to be
Another goddamn drone
Tell me what am I supposed to be
Should I get ready to play

You're pushing and fighting your way
You're ripping it up

Bring the violence
It's significant
To the life
If you've ever known anyone

Bring the violence
It's significant
To the life
Can you feel it?
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
int ans;

int solve(int x1,int y1,int x2,int y2){
	int ret=max(x1+x2,max(y1,y2));
	ret=min(ret,max(y1+y2,min(x1,x2)));
	return ret;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  int a,b;
	  cin>>a>>b;
	  ans=solve(a,b,a,b);
	  ans=min(ans,solve(a,b,b,a));
	  cout<<ans*ans<<endl;
  }
  // cin.get(); cin.get();
  return 0;
}