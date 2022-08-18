/*
Hey (hey)
I'm your life
I'm the one who takes you there
Hey (hey)
I'm your life
I'm the one who cares
They (they)
They betray
I'm your only true friend now
They (they)
They'll betray
I'm forever there

I'm your dream, make you real
I'm your eyes when you must steal
I'm your pain when you can't feel
Sad but true

I'm your dream, mind astray
I'm your eyes while you're away
I'm your pain while you repay
You know it's sad but true
Sad but true

You (you)
You're my mask
You're my cover, my shelter
You (you)
You're my mask
You're the one who's blamed
Do (do)
Do my work
Do my dirty work, scapegoat
Do (do)
Do my deeds
For you're the one who's shamed

I'm your dream, make you real
I'm your eyes when you must steal
I'm your pain when you can't feel
Sad but true

I'm your dream, mind astray
I'm your eyes while you're away
I'm your pain while you repay
You know it's sad but true
Sad but true

I'm your dream
I'm your eyes
I'm your pain

I'm your dream (I'm your dream)
I'm your eyes (I'm your eyes)
I'm your pain (I'm your pain)
You know it's sad but true

Hate (hate)
I'm your hate
I'm your hate when you want love
Pay (pay)
Pay the price
Pay, for nothing's fair

Hey (hey)
I'm your life
I'm the one who took you there
Hey (hey)
I'm your life
And I no longer care

I'm your dream, make you real
I'm your eyes when you must steal
I'm your pain when you can't feel
Sad but true

I'm your truth, telling lies
I'm your reason, alibis
I'm inside, open your eyes
I'm you

Sad but true
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 100031;

long long ts,tf,t,ariv[N];
int n;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>ts>>tf>>t;
	cin>>n;

	if (n==0)
	{
		cout<<ts<<endl;
		return 0;
	}

	for (int i=0;i<n;i++)
	{
		cin>>ariv[i];
	}

	ariv[n]=tf;

	long long cur_done=ts;

	long long best_t=1e18;
	long long ans=-1;

	long long in_qu=0;

	if (ariv[0]>0)
	{
		long long P=ariv[0]-1;
		P=min(P,tf-t);

		//cout<<P<<endl;
		long long hr=max(ts-P,0ll)+t;
		best_t=hr;
		ans=P;
	}

//	cout<<best_t<<endl;

	for (int i=0;i<n;i++)
	{
		while (in_qu>0&&cur_done+t<=ariv[i])
		{
			cur_done+=t;
			in_qu--;
		}
		if (in_qu==0)
		{
			cur_done=max(ariv[i],cur_done);
		}
		in_qu++;

		long long f_this=cur_done+1ll*t*in_qu+t;
		if (f_this>tf)continue;
		if (ariv[i+1]==ariv[i])
			continue;
		long long should_start=min(ariv[i+1]-1,f_this-t);
		should_start=min(should_start,tf-t);
		//cout<<i<<" "<<should_start<<endl;
		if (should_start<ariv[i])
			continue;
		long long here=f_this-should_start;
		if (here<best_t)
		{
			best_t=here;
			ans=should_start;
		}
	}

	cout<<ans<<endl;//" "<<best_t<<endl;

	cin.get(); cin.get();
	return 0;
}