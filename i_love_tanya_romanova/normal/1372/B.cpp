/*
Twisting and turning unable to sleep
Do the voices ever stop
My thoughts speak louder the more I resist
And they're driving me insane
Do they ever go?

Inside
I'm a danger to myself
(I'm a danger to myself)
Inside
I'm a prisoner of my own hell
(Of my own hell)

Losing the battle I waged on myself
Lock me up and toss the key
Toys in the attic it's all getting worse
Why won't I let me be
Oh god make it stop

Inside
I'm a danger to myself
(I'm a danger to myself)
Inside
I'm a prisoner of my own hell
(Of my own hell)

Fit me for a strait jacket
Put me in a padded cell
I'm a danger to you all
And I'm a danger to myself

Inside
I'm a danger to myself
(I'm a danger to myself)
Inside
I'm a prisoner of my own hell
(Of my own hell)
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

const int N = 100031;

int tests,n,ans;

long long gcd(long long a,long long b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	 cin>>n;
	 int ans=n-1;

	 for (int i=2;i*i<=n;i++){
		 if (n%i)
			 continue;
		 if (lcm(i,n-i)<lcm(ans,n-ans))
			 ans=i;
		 if (lcm(n/i,n-n/i)<lcm(ans,n-ans))
			 ans=n/i;
	 }

	 cout<<ans<<" "<<n-ans<<endl;

  }

  cin.get(); cin.get();
  return 0;
}