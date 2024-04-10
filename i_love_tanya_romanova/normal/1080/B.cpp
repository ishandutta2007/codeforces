/*
You're dying but you're still alive
Slow gradual decay
Doused with chemicals forever your cursed
To walk the earth as undead

Eating the brains the way to endure
The painfulness of death
Stiffening of your muscles
But you cannot die

Rigor mortis, settles in
Rotting corpse, blackened skin
Decayed bones, rotten flesh
Rigor Mortis, after death

But you are still a corpse beneath the earth
Rancid souls await rebirth
Acid rain brings them to life
destiny of strife

Lurking in the streets
Your flesh they need to eat
Feel the horrid chill
Knowing they can't be killed
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
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

int tests;

long long solve(int r){
	int full=r/2;
	if (r%2==1)
		full-=r;
	return full;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>tests;
	for (;tests;--tests){
		int l,r;
		cin>>l>>r;
		cout<<solve(r)-solve(l-1)<<endl;
	}

//	cin.get(); cin.get();
	return 0;
}