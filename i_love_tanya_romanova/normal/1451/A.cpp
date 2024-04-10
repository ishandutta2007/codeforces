/*
Convalescent livid we succumb
Stagnation now complete
This is the new plague called
Unconsciousness
We're selfcaged in defeat
Clotted minds coagulate we are trapped
Inside the tears we obey resignate to our
Self-inflected fears

Voices calm will be never heard
In this mode who will change
Bantised in our minds so absurd
Is this the world sublime
Into pools of paranoia we're fading with
Reality drained by lies we are al inhuman
Introspective vanishing

Sterile thoughts now upraised in subhuman
Majesty bodies numb still enchained
Where am i in hell of our dreams
Wrong wrong i'm in the now the vain reality

So it seems we're dying yet content
Worship our chrysalis stage since when are
Lies devine

Since when

This is now degrade indulge
This is us servile obliging

Swallowed by our hunger for mendacity
As this dance whirls deeper into hate

We're vanishing

In down deep cold where am i caught cage
Trapped not in dreams now time has killed
Our eyes fall fade gone dead away
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

int tests;
int n;

int solve(int x)
{
	if (x==1)
		return 0;
	if (x==2)
		return 1;
	if (x%2==0)
		return 2;
	if (x==3)
		return 2;
	return 3;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	cout<<solve(n)<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}