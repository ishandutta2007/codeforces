/*
There's just so much God damned weight on my shoulders
All I'm trying to do is live my motherfucking life
Supposed to be happy, but I'm only getting colder
Wear a smile on my face, but there's a demon inside
There's just so much God damned weight on my shoulders
All I'm trying to do is live my motherfucking life
Supposed to be happy, but I'm only getting colder
Wear a smile on my face, but there's a demon inside

Oh, yo, yo, there's a demon inside
Oh, yo, yo, just like Jekyll and Hyde
Oh, yo, yo, all this anger inside
Oh, yo, yo, I feel like Jekyll and Hyde

There's just so much God damned weight on your shoulders
That you can't just live your motherfucking life
The story's getting old and my heart is getting colder
I just wanna be Jekyll, but I'm always fighting Hyde
You've got rocks in your head, I can hear them rolling 'round
You can say that you're above it, but you're always falling down
Is there a method to your madness? Is it all about pride?
Everyone I know, they've got a demon inside

Oh, yo, yo, there's a demon inside
Oh, yo, yo, just like Jekyll and Hyde
Oh, yo, yo, all this anger inside
Oh, yo, yo, I feel like Jekyll and Hyde

If I wasn't so deranged, could I ever face the pain?
If I ever want to change, would this all remain the same?
Oh, yo, yo
All I'm trying to do is live my motherfucking life
Oh, yo, yo
Wear a smile on my face, but there's a demon inside
Oh, yo, yo
All I'm trying to do is live my motherfucking life
Oh, yo, yo
Wear a smile on my face, but there's a demon inside

Oh, yo, yo, there's a demon inside
Oh, yo, yo, just like Jekyll and Hyde
Oh, yo, yo, all this anger inside
Oh, yo, yo, I feel like Jekyll and Hyde
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

long long n,ar[N],pref[N],suf[N],ans;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  long long sum_all=0;

  cin>>n;
  for (int i=1;i<=n;i++){
	  cin>>ar[i];
	  sum_all+=ar[i];
  }

  // first case

  for (int i=1;i<=n;i++){
	 pref[i]=pref[i-1];
	 if (i%2==1)
		 pref[i]+=ar[i];
  }

  for (int i=n;i;--i){
	  suf[i]=suf[i+1];
	  if (i%2==0)
		  suf[i]+=ar[i];
  }

  ans=1e18;

  for (int i=1;i<n;i+=2){
	  long long here=pref[i];
	  if (i+3<=n)
		  here+=suf[i+3];
	  ans=min(ans,here);
  }

  for (int i=1;i<=n;i++){
	  pref[i]=suf[i]=0;
  }

  // 2nd case

  for (int i=1;i<=n;i++){
	  pref[i]=pref[i-1];
	  if (i%2==0)
		  pref[i]+=ar[i];
  }

  for (int i=n;i;--i){
	  suf[i]=suf[i+1];
	  if (i%2==1)
		  suf[i]+=ar[i];
  }

  for (int i=0;i<=n;i+=2){
	  long long here=pref[i];
	  if (i+3<=n)
		  here+=suf[i+3];
	  ans=min(ans,here);
  }

  cout<<sum_all-ans<<endl;

  cin.get(); cin.get();
  return 0;
}