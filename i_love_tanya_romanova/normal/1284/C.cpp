/*
The slayer's arrived
On a black horse of steel
Trouble is coming
Hell on two wheels

Hide in the shadows
Awaiting defeat
Or live by the sword
And choose to be free

We say retribution
We say vengeance is bliss
We say revolution
With a cast iron fist

Coming down the road
Watching every move
Kicking in the doors
Taking what we choose

Anarchy's coming to town
A fiery invader
Burning it down to the ground
The Disintegrators

Anarchy's coming
Here it comes
Burning it down to the ground
The Disintegrators
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

//#define bs 1000000007

const int N = 510031;

int bs;

long long fact[N],n,invf[N];

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
	if (m>n)
		return 0;
	long long ret=fact[n];
	ret*=invf[m];
	ret%=bs;
	ret*=invf[n-m];
	return ret%bs;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    fact[0]=1;

    cin>>n>>bs;
    for (int i=1;i<N;i++){
    	fact[i]=fact[i-1]*i%bs;
    }

   /* for (int i=0;i<N;i++){
    	invf[i]=inv(fact[i]);
    }*/

    long long ans=0;

    for (int len=1;len<=n;len++){
    	long long ways=1;
    	ways*=n-len+1; // what does it contain
    	ways*=n-len+1; // where do we place it
    	ways%=bs;
    	ways*=fact[len]; // how do we order it
    	ways%=bs;
    	ways*=fact[n-len]; // how do we order the rest
    	ways%=bs;
    	ans+=ways;
    	ans%=bs;
    }

    cout<<ans<<endl;

    //    cin.get(); cin.get();
    return 0;
}