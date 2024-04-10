/*
Your face, my face
You breathe and I breathe
You fail, I fake
I pray, I pray...
You lose and I lose
You bruise, I bruise
I hunt, you stay
My prey, my prey

My Masquerade
(My Masquerade)
My Masquerade
(My Masquerade)
If you're not afraid
(You not afraid)
To take a step into my world

My Masquerade
(My Masquerade)
My Masquerade
(My Masquerade)
If you're not afraid
(You not afraid)
To take a step into my world
My Masquerade

A ball, tonight
Cover your eyes
By touch and taste
We'll find our way
Your secrets deep
Yes I will keep
I hunt, you stay
My prey, my prey

My Masquerade
(My Masquerade)
My Masquerade
(My Masquerade)
If you're not afraid
(You not afraid)
To take a step into my world

My Masquerade
(My Masquerade)
My Masquerade
(My Masquerade)
If you're not afraid
(You not afraid)
To take a step into my world
My Masquerade

Take off your mask
The world will see
The freak in you
The freak in me
Tonight we hide
From judging eyes

Take off your mask
The world will see
The freak in you
The freak in me
Tonight we hide
From judging eyes
We'll dance until sunrise

My prey, my prey

My Masquerade
(My Masquerade)
My Masquerade
(My Masquerade)
If you're not afraid
(You not afraid)
To take a step into my world

My Masquerade
(My Masquerade)
My Masquerade
(My Masquerade)
If you're not afraid
(You not afraid)
To take a step into my world
My Masquerade
*/

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

#define eps 1e-6
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

const int INF = 1e9;
const int N = 200031;

int n, m, l[N], r[N], min_len;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	min_len = 50000000;

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> l[i] >> r[i];
		min_len = min(min_len, r[i] - l[i]+1);
	}

	cout << min_len << endl;

	for (int i = 1; i <= n; i++)
	{
		if (i > 1)
			cout << " ";
		cout << i%min_len;
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}