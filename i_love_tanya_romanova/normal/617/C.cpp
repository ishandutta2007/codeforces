/*
I've seen the road and it's snares
I bore the load though it wears
I've heard your curses and taunts and yet it won't stop me
I've heard your curses and slights and still it won't stop me
Slept through the coldest of nights
From ever calling You king
Or hide the Gospel we bring
It's burning bright in my eyes
Come grow, come grow and light up the skies

We're hungry, tired, and sick
Faced with resistance on every end (in You we hide)
I've felt the scorn you inflict
Attack this mission I will defend
Still onward we will ride
We will ride
Onward we will ride
Forward with no end in sight
In You we shall hide
Our hope is found in the light

Tonight I rest, I rest in peace
Your will is greater than mine
And I haven't a thirst for wealth or man's empty praise
For the glory is Thine
And I haven't a want of fame in this world to claim at all

We will ride
We will face the world
We will ride
We will face the world

We're dirty, restless, and sore
But count it joy to be found worthy (against this test)
Endless assaults to endure
Upon our bodies with no worry
For one day I'll have rest
I've seen the road and it's snares
I bore the load though it wears
I've heard your curses and slights and yet it won't stop me
And yet it won't stop me

Tonight I rest, I rest in peace
Your will is greater than mine
And I haven't a thirst for wealth or man's empty praise
For the glory is Thine
And I haven't a want of fame in this world to claim
When the vile take aim on my flesh I'll call Your name

I've seen the road and it won't stop me
With Your strength bestowed upon me freely
And Your grace has flowed in us completely
Now let us cut through the night so that in me they would see light
I've seen the road and it won't stop me
No end in sight as far as I see
And I'll bear the weight of the victim
Onward we ride till kingdom come
I've seen the road and it won't stop me
No end in sight as far as I see
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
long long n;
pt f[10], p[10000];
long long ans;

long long get_d(pt a, pt b)
{
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

long long solve(pt pp)
{
	long long D = get_d(f[0], pp);
	long long d2 = 0;
	for (int i = 1; i <= n; i++)
	{
		long long here = get_d(f[0], p[i]);
		if (here <= D)
			continue;
		long long here2 = get_d(f[1], p[i]);
		d2 = max(d2, here2);
	}
	return D + d2;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	cin >> f[0].x >> f[0].y >> f[1].x >> f[1].y;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].x >> p[i].y;
	}

	ans = 1e18;

	for (int i = 1; i <= n; i++)
	{
		ans = min(ans, solve(p[i]));
	}

	swap(f[0], f[1]);
	for (int i = 1; i <= n; i++)
	{
		ans = min(ans, solve(p[i]));
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}