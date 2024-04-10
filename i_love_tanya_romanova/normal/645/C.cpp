/*
I see all things
From my mind's innocence
When they call me
I hear their prophecy

You say I must
Face my own deliverance
Did you choose me?
Have I lost sanity?

These eyes can see right through me
I feel your soul inside
What have you waiting for me?
I'll do what you decide

And now this possession
Becomes my one obsession
Adrift in illusion
I'm sent into confusion

Such torment and sadness
That overwhelms like madness
So fearful and intense
It burns inside

I'll spread the word around the world
My name will last eternally
I have the power, I have the choice
They'll hear my voice for centuries

Pandora's box is open
Too late, no turning round
A paradox has woken
I serve with honor bound

I take this possession
And make it my obsession
Alive in illusion
To make sense from confusion

Come torment, come sadness
Give me the joy of madness
This fear and this intent
Runs deep inside

This deepest possession for my life
I want this obsession in my life
I claim this possession, take my life
*/

//#pragma comment(linker, "/STACK:16777216")
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 300000;

using namespace std;

int n, k;
string st;
int s[N];
int ar[N];

int check(int span)
{
	int best = 0;
	for (int center = 1; center <= n; center++)
	{
		if (ar[center] == 1)
			continue;
		int l, r;
		l = center - span;
		r = center + span;
		if (l < 1)
			l = 1;
		if (r>n)
			r = n;
		int here = s[r] - s[l - 1];
		if (here > best)
			best = here;
	}
	return best;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k;

	cin >> st;

	for (int i = 1; i <= st.size(); i++)
	{
		s[i] = s[i - 1];
		if (st[i - 1] == '0')
			++s[i];
		else
			ar[i] = 1;
	}

	int l, r;
	l = 0;
	r = n;
	while (l < r)
	{
		int mid = l + r;
		mid /= 2;
		if (check(mid)>=k+1)
			r = mid;
		else
			l = mid + 1;
	}
	cout << l << endl;

	cin.get(); cin.get();
	return 0;
}