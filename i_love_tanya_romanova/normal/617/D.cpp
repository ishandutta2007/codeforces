/*
Like an unsung melody
The truth is waiting there for you to find it
It's not a blight, but a remedy
A clear reminder of how it began
Deep inside your memory
Turned away as you struggled to find it
You heard the call as you walked away
A voice of calm from within the silence
And for what seemed an eternity
You're waiting, hoping it would call out again
You heard the shadow reckoning
Then your fears seemed to keep you blinded
You held your guard as you walked away

When you think all is forsaken
Listen to me now (all is not forsaken)
You need never feel broken again
Sometimes darkness can show you the light

An unforgivable tragedy
The answer isn't' where you think you'd find it
Prepare yourself for the reckoning
For when your world seems to crumble again
Don't be afraid, don't turn away
You're the one who can redefine it
Don't let hope become a memory
Let the shadow permeate your mind and
Reveal the thoughts that were tucked away
So that the door can be opened again
Within your darkest memories
Lies the answer if you dare to find it
Don't let hope become a memory

When you think all is forsaken
Listen to me now (all is not forsaken)
You need never feel broken again
Sometimes darkness can show you the light

Sickening, weakening
Don't let another somber pariah consume your soul
You need strengthening, toughening
It takes an inner dark to rekindle the fire burning in you
Ignite the fire within you

When you think all is forsaken
Listen to me now (all is not forsaken)
You need never feel broken again
Sometimes darkness can show you the light

Don't ignore, listen to me now (all is not forsaken)
You need never feel broken again
Sometimes darkness
Can show you the light
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 600000;

using namespace std;

struct pt
{
	long long x;
	long long y;
};

pt p[4];

bool same_line(pt a, pt b)
{
	return (a.x == b.x || a.y == b.y);
}

bool is_inside(int a, int b, int c)
{
	if (c < a)
		swap(a, c);
	return (a <= b&&b <= c);
}

bool is_corner(pt a, pt b, pt c)
{
	if (!same_line(a, b))
		return false;
	if (b.x == a.x&&is_inside(a.y, b.y, c.y))
		return true;
	if (b.y == a.y&&is_inside(a.x, b.x, c.x))
		return true;
	return false;
}
long long solve()
{
	if (p[0].x == p[1].x&&p[1].x == p[2].x)
		return 1;
	if (p[0].y == p[1].y&&p[1].y == p[2].y)
		return 1;
	if (is_corner(p[0], p[1], p[2]) || is_corner(p[0], p[2], p[1]) || is_corner(p[1], p[0], p[2]) || is_corner(p[1], p[2], p[0]) ||
		is_corner(p[2], p[0], p[1]) || is_corner(p[2], p[1], p[0]))
		return 2;
	return 3;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	for (int i = 0; i < 3; i++)
	{
		cin >> p[i].x >> p[i].y;
	}

	cout << solve() << endl;


	cin.get(); cin.get();
	return 0;
}