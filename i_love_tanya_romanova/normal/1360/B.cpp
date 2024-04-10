/*
Yeah
Bringing you another disturbing creation
From the mind of one sick animal
Who can't tell the difference
And gets stupefied

I've been waiting my whole life for just one fuck
And all I needed was just one fuck
How can you say that you don't give a fuck?
I find myself stupefied, coming back again

All I wanted was just one fuck
One tiny, little, innocent fuck
And when I feel like I'm shit out of luck
I find myself stupefied, coming back again

Why do you like playing around with
My narrow scope of reality?
I can feel it all start slipping
I think I'm breaking down

Why do you like playing around with
My narrow scope of reality?
I can feel it all start slipping away

See, but I don't get it
Don't you think maybe we could put it on credit?
Don't you think it can take control when I don't let it?
I get stupefied! "It's all the same", you say

Live with it, but I don't get it
Don't you think maybe we could put it on credit?
Don't you think it can take control when I don't let it?
I get stupefied! I get stupefied!

All the people in the left wing, rock
And all the people in the right wing, rock
And all the people in the underground, rock
I find myself stupefied, coming back again

All the people in the high-rise, rock
And all the people in the projects, rock
And all "La Gente" in the barrio, rock
I find myself stupefied, coming back again

Why do you like playing around with
My narrow scope of reality?
I can feel it all start slipping
I think I'm breaking down

Why do you like playing around with
My narrow scope of reality?
I can feel it all start slipping away

See, but I don't get it
Don't you think maybe we could put it on credit?
Don't you think it can take control when I don't let it?
I get stupefied! "It's all the same", you say

Live with it, but I don't get it
Don't you think maybe we could put it on credit?
Don't you think it can take control when I don't let it?
I get stupefied! I get stupefied!

Tefached...
Tefached...

And don't deny me
No, baby now, don't deny me
And darling, don't be afraid

But I don't get it
Don't you think maybe we could put it on credit?
Don't you think it can take control when I don't let it?
I get stupefied!

Look in my face, stare in my soul, I begin to stupify!
Look in my face, stare in my soul, I begin to stupify!
Look in my face, stare in my soul, I begin to stupify!
Look in my face, stare in my soul, I begin to stupify!

Look in my face, step in my soul
Look in my face, step in my soul
Look in my face, step in my soul
Look in my face, step in my soul

Look in my face! (Step in my soul)
Look in my face! (Step in my soul)
Look in my face! (Step in my soul)
I begin to stupify!
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

int tests,n,ar[N];
int ans;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  for (int i=0;i<n;i++){
		  cin>>ar[i];
	  }
	  sort(ar,ar+n);
	  int ans=ar[1]-ar[0];
	  for (int i=2;i<n;i++){
		  ans=min(ans,ar[i]-ar[i-1]);
	  }
	  cout<<ans<<endl;

  }
  // cin.get(); cin.get();
  return 0;
}