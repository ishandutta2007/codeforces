/*
I'm not one to say
Where my feelings are going when they wither away
I pray to see another day
My heart's feeling like a needle lost in the hay
Restrained to meet again
My friend do you think that we ever will
I know we are free...

The games are played with your life on the line
Some lose, you win if you keep on trying
I don't mind doing the time, I'm happier being alive
Now I know the means to my opression were all lies
The only truth is your own most sacred lesson I've ever learned
I know we are free...

Yeah,
Don't go,
No,
Don't look back,
Just realize

I've been robbed, I've been fooled
I intent now to make my own rules
Dagger's edge cut the life, I've been down that road too many times

What's to fear, fear no more,
Show my conscience what fear's for
Now I know this is so real
What's done is done so do as you will!

I'm keeping alive! Go on, no don't look back
Just realise where you've gone.
Where are you going to, no life's not done wit you
You're only just begun, to live your life, for you...
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
	  int ptr=n;
	  while (ptr>1&&ar[ptr]<=ar[ptr-1])
		  --ptr;
	  while (ptr>1&&ar[ptr]>=ar[ptr-1])
		  --ptr;
	  cout<<ptr-1<<endl;
  }
  cin.get(); cin.get();
  return 0;
}