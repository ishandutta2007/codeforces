/*
I hear your voice in the wind
It follows me, it cuts right through the noise
As we spin on dance floors made of ice
So rest your hand in mine
Steady now, ignore the sound
The breaking lines
The crack beneath our feet as time runs out
Each night like a white noise frequency
Broadcast the waves, I tune them out
Clear signs outlined
But I couldn't see what I see now

I should've said something to you
When I saw you walk away, instead I did nothing
And now you're gone and it's too late
We board up the windows we used to look through
I should've said something, I should've said something to you

Like buried seeds in the ground
Invisible but growing
Underneath pushing out
Now tangled in the vine, I hear the sound
Heartbeats from a world so far away
The distant drums, I tune them out
Each night right before I fall asleep
I hear them now

I should've said something to you
When I saw you walk away, instead I did nothing
And now you're gone and it's too late
So we board up the windows we used to look through
I should've said something, yeah, I should've said something to you
I should've said something, yeah, I should've said something
So we board up the windows we used to look through
I should've said something, I should've said something, I should've said something
Yeah, I should've said something to you
To you
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

long long n,k,ttl[N],a[N],b[N];
int used[531][531];
long long S;
long long overall_ans;

void dfs(int ps,int rem){
	//cout<<ps<<" "<<rem<<endl;
	if (used[ps][rem])
		return;
	used[ps][rem]=1;
	if (ps==n)
		return;
	// we can always ignore this bush
	dfs(ps+1,(rem+a[ps+1])%k);
	if (a[ps+1]+b[ps+1]>=k){
		for (int i=0;i<k&&i<=a[ps+1];i++){
			if (b[ps+1]+i<k)
				continue;
			int new_rem=(rem+a[ps+1]-i)%k;
			dfs(ps+1,new_rem);
		}
	}
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n>>k;
  for (int i=1;i<=n;i++){
	  cin>>a[i]>>b[i];
	  ttl[i]=ttl[i-1]+a[i]+b[i];
  }

  dfs(0,0);

  for (int rem=0;rem<k;rem++){
	  if (used[n][rem]==0)
		  continue;
	  S=ttl[n]%k;
	  S=(S+k-rem)%k;
	  long long wasted=rem+S;
	  long long ans_here=(ttl[n]-wasted)/k;
	  overall_ans=max(overall_ans,ans_here);
  }

  cout<<overall_ans<<endl;

  // cin.get(); cin.get();
  return 0;
}