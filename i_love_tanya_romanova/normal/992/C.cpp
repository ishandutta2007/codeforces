/*
I'm going to Chicago that's the last place my baby stayed
I'm packing up my bags I'm gonna leave this town right away
I'm gonna find that girl if I have to hitch hike around the world
"Chicago City" that's what the sign on the freeway read
I'm gonna keep on going 'til I get to that street's called 6th and Main
I've gotta find that girl if i have to hitch hike around the world
C'mon hitch hike
Hitch hike children
Hitch hike
Hitch hike baby
Hitch hike
Hitch hike baby
C'mon hitch hike
Hitch hike darling
I'm going to St. Louis but my next stop just might be L.A., that's what I say
I got no money in my pocket so i'm going to have to hitch hike all the way
I'm gonna find that girl if i have to hitch hike around the world
C'mon hitch hike
Hitch hike children
Hitch hike
Hitch hike baby
Hitch hike
Hitch hike baby
C'mon hitch hike
Hitch hike children
Now c'mon c'mon hitch hike
Hitch hike children
Hitch hike
Hitch hike darling
C'mon hitch hike
Hitch hike children
Hitch hike hitch hike
Hitch hike baby
Mmmmm...
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1200031;

long long x,k;

long long pw(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>x>>k;
;

	if (k==0){
		cout<<x*2%bs<<endl;
		return 0;
	}

	if (x==0){
		cout<<0<<endl;
		return 0;
	}

	long long q=pw(2,k-1);

	x=x*2-1;
	x%=bs;
	x=x*q;
	x%=bs;
	cout<<(x*2+1)%bs<<endl;

//	cin.get(); cin.get();
	return 0;
}