/*
The sullen man before me turns a head and demonstrates
The power of a weak mind can't conceal or captivate

It's lost in a bleak scope of fragmented ways
Eternal non-events occur throughout its poor days
You're lost forever unable to see yourself
The thoughts arising, there's
no disguising where you've been...

Reveal to me, your mind's identity

You'll pay, pay for the feelings that you feed me
Don't hold on to what you call a life...

Anger compels a force of weakness or fear
I'll promise no forgiveness for the rest of my years
A negative release, subliminal urge
Unwish declining, grey thoughts reviving all the way...

Your fallen prey, a loser pays

You'll pay for the feelings that you feed me
Don't hold on to what you call a life...
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

const int bs = 998244353;

const int N = 600031;

int tests;
long long n;

bool bad(long long val){
	long long r=val;
	while(r){
		int di=r%10;
		if (di>0&&val%di>0)
			return true;
		r/=10;
	}
	return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	while (bad(n))++n;
    	cout<<n<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}