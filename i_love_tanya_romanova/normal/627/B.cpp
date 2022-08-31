/*
Where I was, not one to follow
You gave me something
I did not believe
was ever meant for me
Oh my god, I

I am grateful, you know that
But I have nothing
to give in return for this
My life for what?
What else was I good for?

You know me,
I can't be redeemed
What do you want from me?
You took me out of play and now
you choose to free me again?
I have no cause
I don't believe
I kill, that's all I know
I am the villain of this story, what else could I ever be?

My penance weaved into this conflict,
this hidden war
I can't believe
you gave me back
what I thought for sure lost

But I don't see what I can do here
What is it you want me to be for you?
My life for what?
What else was I good for?

Even though I can't feel what you feel
I understand, and we move forward
Better than alone

Yeah, I am

I'm so much better by your side
than lost in night

I have my own reasons
but I'll believe

for you

You know me,
I can't be redeemed
What do you want from me?
You took me out of play and now
you choose to free me again?
I have no cause
I don't believe
I kill, that's all I know
I am the villain of this story, what else could I ever?

You know me,
I can't be redeemed
What do you want from me?
You took me out of play and now
you choose to free me again?
I have no cause
I don't believe
I kill, that's all I know
I am the villain of this story, what else could I ever be?

You know me,
I can't be redeemed
What do you want from me?
You took me out of play and now
you choose to free me again?
I have no cause
I don't believe
I kill, that's all I know
I am the villain of this story, what else could I ever?

You know me,
I can't be redeemed
What do you want from me?
You took me out of play and now
you choose to free me again?
I have no cause
I don't believe
I kill, that's all I know
I am the villain of this story, what else could I ever be?
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

const int N = 205000;

using namespace std;

int n, k, a, b, p, q;
int d, val;
long long t1[N * 4], t2[N * 4];
long long am1[N], am2[N];

void update(int v, int tl, int tr,int ps)
{
	if (tl == tr)
	{
		t1[v] = am1[tl];
		t2[v] = am2[tl];
		return;
	}
	int tm = tl + tr;
	tm /= 2;
	if (ps <= tm)
		update(v * 2, tl, tm, ps);
	else
		update(v * 2 + 1, tm + 1, tr, ps);
	t1[v] = t1[v * 2] + t1[v * 2 + 1];
	t2[v] = t2[v * 2] + t2[v * 2 + 1];
}

int get(int v, int tl, int tr, int l, int r, int tp)
{
	if (l > r)
		return 0;
	if (tl == l&&tr == r)
	{
		if (tp == 1)
			return t1[v];
		else
			return t2[v];
	}
	int tm = tl + tr;
	tm /= 2;
	return get(v * 2, tl, tm, l, min(r, tm), tp) + get(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, tp);
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> k >> a >> b >> q;

	for (int i = 1; i <= q; i++)
	{
		int tp;
		cin >> tp;
		if (tp == 1)
		{
			long long toadd;
			long long val;
			cin >> d >> val;
			if (am1[d] < b)
			{
				toadd = min(b - am1[d], val);
				am1[d] += toadd;
			}
			if (am2[d] < a)
			{
				toadd = min(a - am2[d], val);
				am2[d] += toadd;
			}
			update(1, 1, n, d);
		}
		else
		{
			int val;
			cin >> val;
			cout << get(1, 1, n, 1, val - 1, 1) + get(1, 1, n, val + k, n, 2) << endl;
		}
	}

	cin.get(); cin.get();
	return 0;
}