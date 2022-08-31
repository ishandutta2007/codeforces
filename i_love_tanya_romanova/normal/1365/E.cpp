/*
Help me - save me
I've just crossed the line
Where reason might betray me
Wake me - shake me
Send a message to my brain
Before they take me
How can I get through to you
That wishes just come true
In dreams

Don't go - don't dare
Cause the journey drives you made
Before you get there
Help me - save me
I'll be glad to give you back
The hand you gave me
How can I get through to you
That wishes do come true
In dreams

If I'm a river - then you're the sea
Somewhere you'll find me
Alone and swimming here in ecstasy

If I am silence - you must be scream
But I don't hear you
I'm in a place that I've just never seen before

Don't go - you'll never save me
I've just slapped away
That helping hand you gave me
Don't wake me - Don't shake me
Here's a message from my brain
You'll never take me
How can I get through to you
That wishes do come true in dreams
In my dreams
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

const int N = 610031;

long long n,ar[N],ans;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n;
  for (int i=1;i<=n;i++){
	  cin>>ar[i];
	  ans=max(ans,ar[i]);
  }

  for (int i=1;i<=n;i++){
	  for (int j=i+1;j<=n;j++){
		  ans=max(ans,ar[i]|ar[j]);
	  }
  }

  for (int i=1;i<=n;i++){
	  for (int j=i+1;j<=n;j++){
		  for (int q=j+1;q<=n;q++){
			  ans=max(ans,ar[i]|ar[j]|ar[q]);
		  }
	  }
  }
  cout<<ans<<endl;

  cin.get(); cin.get();
  return 0;
}