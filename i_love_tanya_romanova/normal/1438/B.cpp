/*
Threw you the obvious and you flew with it on your back,
A name in your recollection, down among a million same.
Difficult not to feel a little bit disappointed, and passed over
When I've looked right through, see you naked but oblivious.

And you don't see me.

But I threw you the obvious, just to see if there's more behind the
Eyes of a fallen angel, eyes of a tragedy.
Here I am expecting just a little bit too much from the wounded
But I see, see through it all, see through, see you.

'Cause I threw you the obvious, to see what occurs behind the
Eyes of a fallen angel, eyes of a tragedy, oh well.

Oh well, apparently nothing.
Apparently nothing, at all.

You don't, you don't, you don't, see me.
You don't, you don't, you don't, see me.
You don't, you don't, you don't, see me.
You don't see me.
You don't, you don't, you don't see me at all.
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

const int N = 600031;

int tests,n,ar[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    	}
    	int ok=1;
    	for (int i=1;i<=n;i++){
    		for (int j=i+1;j<=n;j++){
    			if (ar[i]==ar[j])
    				ok=0;
    		}
    	}
    	if (ok)
    		cout<<"NO"<<endl;
    	else
    		cout<<"YES"<<endl;
    }
    //cin.get(); cin.get();
    return 0;
}