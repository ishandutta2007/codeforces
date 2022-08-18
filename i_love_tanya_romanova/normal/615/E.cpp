/*
In life you're moving forward
But sometime for the worse
Always keep a step ahead
Never in reverse

The cars are stacked against you
In everything you do
But you try to get out alive
When you don't have a clue

You always feel the tension
Breathing down your back
To be the best that you can be
To be on the attack

Kicking down the wall
And kicking your face in
Means I'm moving forward
My new life can begin

Forward march in your face
Taking back, taking place
Before you die, living fast
Take a chance, hauling ass

Forward march in your face
Taking back, taking place
Before you die, living fast
Take a chance, hauling ass

Forward march
Forward march
Forward march
Never move in reverse

Here I am
I'm moving straight, fuckin' forward
And I'm taking all the steps
To blow on right past you

I'm never gonna back down
To you and all your people
Who think that you're the best
No one can beat you

Well, I've got some news for you, you motherfucker
There's a new man in town who isn't any sucker
So if you don't back down I'll put my bat
To an angry motherfucker such as you

Now I'm going to wipe out
All those who say they're first
I'll be the first in line
My attitude's the worst

Because I am so spoiled
And never second best
I will leave you in the dust
And lay your ass to rest

So never underestimate
The mind of evil thoughts
I will bring you down
Spit you out before I'm caught

Because I have the power
And the upper hand
Everybody in the way
Will know that I'm the man

Forward march in your face
Taking back, taking place
Before you die, living fast
Take a chance, hauling ass

Forward march in your face
Taking back, taking place
Before you die, living fast
Take a chance, hauling ass

Forward march
Forward march
Forward march
Never move in reverse

Here I am
I'm moving straight, I'm fuckin' forward
And I'm taking all the steps
Blowing right past you

I'm never gonna back down
To you and all the people
That think that you're the best
No one can beat you

Well, I've got some news for you, you motherfucker
There's a new man in town who isn't any sucker
So if you don't back down I'll put my bat
To an angry motherfucker such as yourself

In life you're moving forward
But sometime for the worse
Always keep a step ahead
Never in reverse

The cards are stacked against you
In everything you do
But you try to get out alive
When you don't have a clue

You always feel the tension
Breathing at your back
To be the best that you can be
To be on the attack

Kicking down the wall
And kicking your face in
Means I'm moving forward
My new life can begin

Forward march in your face
Taking back, taking place
Before you die, living fast
Take a chance, hauling ass

Forward march in your face
Taking back, taking place
Before you die, living fast
Take a chance, hauling ass

Never, never, never move in reverse
Never, never, never move in reverse
Never, never, never move in reverse
Never, never, never move in reverse
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

#define eps 1e-8
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 2150;

using namespace std;

long long l, r;
long long n;

long long full_circles(long long x)
{
	return x*(x + 1)*3+1;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;

	if (n == 0)
	{
		cout << 0 << " " << 0 << endl;
		return 0;
	}

	l = 0;
	r = 1e9;

	while (l < r)
	{
		long long mid = l + r+1;
		mid /= 2;
		if (full_circles(mid) <= n)
		{
			l = mid;
		}
		else
			r = mid - 1;
	}
//	cout << full_circles(0) << endl;
	//cout << l << endl;

	long long rem = n - full_circles(l);

	long long qx = 1 + 2 * l;
	long long qy = 2;
	//cout << qx << "%" << qy << endl;

//	cout << rem << endl;
	//--rem;

	// up
	if (rem <= l)
	{
		cout << qx - rem << " " << qy + 2 * rem << endl;
		return 0;
	}
	rem -= l;
	qx -= l;
	qy += 2 * l;

	// left
	if (rem <= l + 1)
	{
		cout << qx - 2 * rem << " " << qy << endl;
		return 0;
	}
	rem -= l + 1;
	qx -= 2 * (l + 1);
	
	// down left

	if (rem <= l + 1)
	{
		cout << qx - rem << " " << qy - 2 * rem << endl;
		return 0;
	}
	rem -= l + 1;
	qx -= l + 1;
	qy -= 2 * (l + 1);

	// down right

	if (rem <= l + 1)
	{
		cout << qx + rem << " " << qy - 2 * rem << endl;
		return 0;
	}
	rem -= l + 1;
	qx += l + 1;
	qy -= 2 * (l + 1);

	// right

	if (rem <= l + 1)
	{
		cout << qx + 2 * rem << " " << qy << endl;
		return 0;
	}
	rem -= l + 1;
	qx += 2 * (l + 1);
	
	//cout << qx << "%" << qy << " " << rem << endl;

	cout << qx + rem << " " << qy + 2 * rem << endl;

	cin.get(); cin.get();
	return 0;
}