/*
At a certain point it happens
Life becomes to real
And nothing can hold back
What is about to be
I don't know how close we need to get
To blind out the surroundings and focus on the real
I know you're gone
But this reality is crashing down on me
Crashing down to defeat all purpose
I know you're gone
I'm just not ready I'm just not done
I am ever in resistant disbelief
When raw emotion gets in
The way of our throughts and words
We pass so far beyond our breaking point
I don't know how far we need to be
From all that we don't want to see
To regain perspective
I know you're gone
But this reality is crashing down on me
Crashing down to defeat all purpose
I know you're gone
I'm just not ready I'm just not done
I am ever in resistant disbelief
I know, yet I fail to find purpose and form
I know, but the truth just makes it harder
I know you're gone
But this reality is crashing down on me
Crashing down to defeat all purpose
I know you're gone
I'm just not ready I'm just not done
I am ever in resistant disbelief
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

#define bs 998244353

const int N = 610031;

int n,k;
long long ans;
long long fact[N];
long long invf[N];

long long pw(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

long long inv(long long x){
	return pw(x,bs-2);
}

long long C(long long n,long long m){
	if (n<m)
		return 0;
	long long res=fact[n];
	res*=invf[m];
	res%=bs;
	res*=invf[n-m];
	return res%bs;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n>>k;

  fact[0]=1;
  for (int i=1;i<N;i++){
	  fact[i]=fact[i-1]*i%bs;
  }

  invf[N-1]=inv(fact[N-1]);
  for (int i=N-2;i>=0;--i){
	  invf[i]=invf[i+1]*(i+1)%bs;
  }

  for (int smallest=1;smallest<=n;smallest++){
	  int rem=n/smallest-1;
	  ans+=C(rem,k-1);
	  ans%=bs;
  }
  cout<<ans<<endl;

  // cin.get(); cin.get();
  return 0;
}