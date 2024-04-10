/*
Leeches.
Like leeches
"In ignorance we trust"
If you say this way, I'll take that way
Fuel for the fire on which I thrive

Spit me out
I'm glad I don't belong
Save me the speech (I know)
You'll be forgotten and gone

It burns, it rips, it hurts

Leeches, they preach to us
Words of wisdom from blocked minds

Spit me out
I'm glad I don't belong
Save me the speech (I know)
You'll be forgotten and gone

It burns, it rips, it hurts

They make you believe your turn
The chance of a lifetime,
How does it feel to be alive?

A tear for the poet that can't be heard
(And) praise the artist that steals
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

const int bs = 1000000007;

const long long N = 200031;

long long tests,n,w,h,ttl;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>w>>h>>n;
    	ttl=1;
    	while (w%2==0){
    		ttl*=2;
    		w/=2;
    	}
    	while (h%2==0){
    		ttl*=2;
    		h/=2;
    	}
    	if (ttl>=n){
    		cout<<"YES"<<endl;
    	}
    	else
    		cout<<"NO"<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}