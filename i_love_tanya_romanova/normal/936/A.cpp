/*
Greedy for blood
Paralysed by power
The decision to die
Tales of terror
Deep in the corner
Passion to kill
Corpse on the ground
Minds starts to chill

A man lies in the corner, covered with blood
Bloody wounds on his body, praying to his god
People pass him by, but they say
Why should we care about him? he will die today

Riot of violence

Find your own way
You must go alone
Kill all next to you
They want the throne
The infectious disease
Is the only life
You're scared to death
Die by their knife

A man lies in the corner, covered with blood
Bloody wounds on his body, praying to his god
People pass him by, but they say
Why should we care about him? he will die today

Brutality and mighty wars, warriors start to fight
With bombs and guns, the troops have come to extinguish the light
I'd rather not go wild tonight, but I must save myself

On a field littered with corpses
Stands a lonely flower
It reminds the world how it was
But we kicked it away with power
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

const int N = 400031;

long long k,d,t;

long long one_block;
long double per_block;

long double eval(long double T){
	long long full_blocks=T/one_block;
	long double rem=T-full_blocks*one_block;
	long double from_full=full_blocks*per_block;
	long double good=min(rem,(long double)k);
	from_full+=good;
	rem-=good;
	from_full+=rem/2;
	return from_full;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>k>>d>>t;

	one_block=k/d+(k%d>0);
	one_block*=d;

	per_block=k+(one_block-k)*.5;

	long double l,r;
	l=0;
	r=5e18;

	for (int iter=1;iter<=500;iter++){
		long double mid=l+r;
		mid/=2;
		long double here=eval(mid);
		if (here>t)
			r=mid;
		else
			l=mid;
	}

	cout.precision(15);
	cout<<fixed<<l<<endl;

//	cin.get(); cin.get();
	return 0;
}