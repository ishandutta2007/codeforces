/*
Great
Into Satans armpit I will crawl to seek my vengeance
The ressurection of his evil world
The sailor lost at sea, look for the sun and moon to guide me
I am that sailor I am his vengeance

The great the great will always be
Great the great will always be
Great the great will always stand
We will hunt you down

A timebomb set to blow, destroy all that you know
The decadence of the western world

So walk with me on the brink of time
I will liberate you from sin and your life of crime
Walk with me on the sands of time
Roll the heads of vanity roll it out of line
How will you live your life, sweet sister
How will you live it now
Who will you run to now dear brother
Who will you run to now

Into Satans armpit I will crawl to seek my vengeance
A simple way of thinking a simple way of life
Now we can conquer all the world
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

int tests,n;
int ar[N];
int S;

int solve(int S){
	int cnt=0;
	int cur=0;
	for (int i=1;i<=n;i++){
		cur+=ar[i];
		if (cur>S)
			return n;
		if (cur==S){
			cur=0;
			++cnt;
		}
	}
	if (cur)
		return n;
	return n-cnt;
}

int ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    	}
    	S=0;
    	ans=n-1;

    	for (int i=1;i<=n;i++){
    		S+=ar[i];
    		ans=min(ans,solve(S));
    	}
    	cout<<ans<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}