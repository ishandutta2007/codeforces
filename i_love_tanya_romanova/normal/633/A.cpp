/*
In the smoke and the red
Workin' the late night sweat
You're the one to go to
When I wanna forget
Like hangin' off the moon
I don't wanna come down
Yeah you get me so high
It's hell on the ground

Just one little glass
Makes the night go fast
You can have what you want
If you pay the girl cash

I said girls
Girls in Black
I said girls
Girls in Black

Your the hot bright neon
In the cold dark night
When I'm feelin' down
You make me feel so right
Yeah your bait comes free
But your hooks cut deep
You make the badboys smile
And the good boys weep

Just one little glass
Makes the night go fast
You can have what you want
If you pay the girl cash

I said girls
Girls in Black
I said girls
Girls in Black
I said girls
Girls in Black
I said girls
Girls in Black

Just one little glass
Makes the night go fast
You can have whatever you want
If you pay the girl cash

I said girls
Girls in Black
I said girls
Girls in Black

I said girls
Girls in Black
I said girls
Girls in Black oh yeah
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

const int N = 15000;

using namespace std;

int a, b, c, dp[N];

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> a >> b >> c;
	dp[0] = 1;
	for (int i = 0; i < c; i++)
	{
		if (dp[i] == 0)
			continue;
		dp[i + a] = 1;
		dp[i + b] = 1;
	}
	if (dp[c])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	cin.get(); cin.get();
	return 0;
}