/*
Warriors of Satan's wrath
Come from across the sky
Bring terror and destruction
The son of God must die
Devastation of your gods
The heavens are on fire
Unholy blasphemy from hell
Satan our new messiah

Burn the church to the ground
Hear the helpless dying sounds
Of the Christians who scream and writhe in pain
Feeling the wrath of Satan's reign

Final war has come to an end
Blood fills the land where you lie
Sacrifice on the altar of death
Satan laughs as you die

Legions of doom will rid the world
Of all it's sanity
Your feeble prayers are all in vain
In this insanity
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

int n,k,ans;

int solve(int one,int need){
	int really_need=need*n;
	return really_need/one+(really_need%one>0);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>k;
	ans=solve(k,2)+solve(k,5)+solve(k,8);
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}