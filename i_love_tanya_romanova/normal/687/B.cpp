/*
I feel it welling up inside and Robert Smith lied
Boys do cry and with blood tears in my eyes
I'm an Anne Rice novel come to life
I can't hide the monster, anymore

One can, only feel desolate for so long until
One starts to change into
Something the mirror doesn't recognize
Metamorphosize, the darkness has been biding its time

To claim its latest victim
Fresh meat for carnal desires
To become, what I became
I viewed the sun for the last time

Will you still hold me
When you see what I have done?
Will you still kiss me the same
When you taste my victim's blood?

So crimson and red
I feel it flowing from your lips
(Crimson and red)
My heart is dead and so are you

And it pulses through
The desire to change to deconstruct
All of my
All of my past failings

But where to begin because when you live in sin
It's hard to look at saints
Without them reflecting
Your jet black, aura back on you

And all I have is hope
My inner burn's not fading
I'll wipe the blood from my cheek
And get on with my day

Will you still hold me
When you see what I have done?
Will you still kiss me the same
When you taste my victim's blood?

So crimson and red
I feel it flowing from your lips
(Crimson and red)
My heart is dead and so are you

And all I have is hope
And all I need is time
To bury in pine under six feet of time
The lies I told me about myself

Claw my way out
Pick the splinters from under my fingernails
I won't lose hope
I won't give in

Just live and breathe, try not to die again
Just live and breathe, try not to die again
Just live and breathe, try not to die again
Try not to die again

Will you still hold me
When you see what I have done?
Will you still kiss me the same
When you taste my victim's blood?

So crimson and red
I feel it flowing from your lips
(Crimson and red)
My heart is dead and so are you

Will you still hold me
When you see what I have done?
Will you still kiss me the same
When you taste my victim's blood?

So crimson and red
I feel it flowing from your lips
(When you taste my victim's blood)
My heart is dead and so are you
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
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 1000031;

int pr[N];
int memo[N], mdeg[N];

int n, k;

void factorize(int x)
{
	while (x > 1)
	{
		int val = pr[x];
		int cnt = 0;
		while (x%val == 0)
		{
			cnt++;
			x /= val;
		}
		mdeg[val] = max(mdeg[val], cnt);
	}
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	pr[1] = 1;

	for (int i = 2; i <= 1000000; i++)
	{
		if (pr[i] == 0)
		{
			for (int j = i; j <= 1000000; j += i)
			{
				pr[j] = i;
			}
		}
	}

	cin >> n >> k;

	factorize(k);
	for (int i = 1; i <= 1000000; i++)
	{
		memo[i] = mdeg[i];
		mdeg[i] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		int val;
		scanf("%d", &val);
		factorize(val);
	}

	for (int i = 1; i <= 1000000; i++)
	{
		if (memo[i] > mdeg[i])
		{
			puts("No");
			return 0;
		}
	}

	puts("Yes");

	cin.get(); cin.get();
	return 0;
}