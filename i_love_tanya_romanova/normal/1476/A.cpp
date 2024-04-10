/*
Battle hymns did sound the call.
You came to our side.
You heard true metal
Into glory ride.
Come on yea

You stood beside us,
The false ones cries.
Your love is judgment,
You gave us life.
You wait in the rain, you walk through the snow.
We give you our blood, we want you to know.

In our eyes you're immortal
In our hearts you'll live forever
In our eyes you're immortal
In our hearts you'll live forever more.

We have read your letters, we have heard your call.
We were brought together 'cause we've got the balls
To play the loudest metal, so hard and wild and mean.
You'll live forever, we were born from your belief.

Metal makes us strong
Together we belong
Forever here's your song

We want you to know

In our eyes you're immortal
In our hearts you'll live forever
In our eyes you're immortal
In our hearts you'll live forever more

Metal makes us strong
Together we belong
Forever here's your song

We want you to know

In our eyes you're immortal
In our hearts you'll live forever
In our eyes you're immortal
In our hearts you'll live forever more

Metal makes us strong
It makes us
Metal makes us strong
It makes us stronger, stronger, stronger, stronger...
Stronger, metal makes us strong
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

const long long bs = 1000000007;

const long long N = 200031;

long long tests,n,k,low;
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>k;
    	low=n;
    	if (low%k)
    		low-=low%k,
			low+=k;
    	ans=low/n+(low%n>0);
    	cout<<ans<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}