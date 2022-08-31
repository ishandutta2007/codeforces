/*
Maybe life is like a ride on a freeway
Dodging bullets while you're trying to find your way
Everyone's around, but no one does a damn thing
It brings me down, but I won't let them

If I seem bleak
Well you'd be correct
And if I don't speak
It's cause I can't disconnect
But I won't be burned by the reflection
Of the fire in your eyes
As you're staring at the sun

As you're staring at the sun
As you're staring at the sun
As you're staring at the sun
As you're staring at the sun

When I ran I didn't feel like a runaway
When I escaped I didn't feel like I got away
There's more to living than only surviving
Maybe I'm not there, but I'm still trying

Though you hear me
I don't think that you relate
My will is something
That you can't confiscate
So forgive me, but I won't be frustrated
By destruction in your eyes
As you're staring at the sun
As you're staring at the sun

When I ran I didn't feel like a runaway
When I escaped I didn't feel like I got away
There's more to living than only surviving
Maybe I'm not there, but I'm still trying

Though you hear me
I don't think that you relate
My will is something
That you can't confiscate
So forgive me, but I won't be frustrated
By destruction in your eyes
As you're staring at the sun
As you're staring at the sun

Maybe life is like a ride on a freeway
Dodging bullets while you're trying to find your way
Everyone's around, but no one does a damn thing
It brings me down, but I won't let them

If I seem bleak
Well you'd be correct
And if I don't speak
It's cause I can't disconnect
But I won't be burned by the reflection
Of the fire in your eyes
As you're staring at the sun

As you're staring at the sun
As you're staring at the sun
As you're staring at the sun
As you're staring at the sun
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 510031;

int tests;
long long n,k;

string Z="What are you doing at the end of the world? Are you busy? Will you save us?";

string pref="What are you doing while sending \"";
string mid="\"? Are you busy? Will you send \"";
string suf="\"?";

long long len[N];

char solve(int n,long long x){
	if (n==0){
		if (x<Z.size())
			return Z[x];
		return '.';
	}
	// n!=0
	if (x<pref.size())
		return pref[x];
	x-=pref.size();
	if (x<len[n-1])
		return solve(n-1,x);
	x-=len[n-1];
	if (x<mid.size()){
		return mid[x];
	}
	x-=mid.size();
	if (x<len[n-1]){
		return solve(n-1,x);
	}
	x-=len[n-1];
	if (x<suf.size())
		return suf[x];
	return '.';
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	len[0]=Z.size();
	for (int i=1;i<=100000;i++){
		len[i]=pref.size()+len[i-1]+mid.size()+len[i-1]+suf.size();
		if (len[i]>2e18)
			len[i]=2e18;
	}

	cin>>tests;
	for (;tests;--tests){
		cin>>n>>k;
		--k;
		cout<<solve(n,k);
	}

	cin.get(); cin.get();
	return 0;
}