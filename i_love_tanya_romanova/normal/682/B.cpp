/*
It's in the eyes
You can tell she wants it
It's no surprise by the way she flaunts it

Dressed from head to toe
In seductive clothes
Men attempt in droves
To get her alone

Her intentions aren't fake
But you made a mistake
And she just cannot wait
To put you in your place

It's in the eyes
You can tell she needs it
It's no surprise
And you're going to feed it!

She goes wild
For one filler
Thirsts death
She's a killer

It's her game
She's not dumb
You'll get played
You're one hacked up stud

She is horny for blood!

Next time you're brought home
Hopefully you'll know
That you should watch your step
Or get sliced from head to toe

Because it's in her eyes
And you can tell she needs it
It's no surprise that you're going to feed it

Horny for blood
*/

#pragma comment(linker, "/STACK:16777216")
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
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200000;

int n;
int ar[N];
int ptr;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	sort(ar, ar + n);
	int ptr = 1;
	for (int i = 0; i < n; i++)
	{
		if (ar[i] >= ptr)
			++ptr;
	}
	cout << ptr << endl;

	cin.get(); cin.get();
	return 0;
}