/*
There is nothing left for me to see
The thought of end is killing me
I guess it's time for my demise
There's no more time, I'm left aside

There's no more pain, there's no more tears
There's no more feeling, no more fear
The darkness creeps upon my skin
These wounds won't heal, this is my sin

This is the black abyss
My life's apocalypse
Eternal suffering
No future for me to see

This is the black abyss
Executor of my soul
This darkness fills my eyes
And I'm now left behind

As my life rots away
I long the day for my decay
I'll soon be there in death's grasp
And won't let go, now I'm dead

This paranoia, I can't last
These days are now my last
The sense of evil is closing in
It is a phobia that kills within

This is the black abyss
My life's apocalypse
Eternal suffering
No future for me to see

This is the black abyss
Executor of my soul
This darkness fills my eyes
And I'm now left behind

This is the black abyss
My life's apocalypse
Eternal suffering
No future for me to see

This is the black abyss
Executor of my soul
This darkness fills my eyes
And I'm now left behind
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 100031;

map<long long, long long> cost;
int tests;
long long tp, a, b, v1, v2;
long long q;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> tests;
	for (; tests; --tests)
	{
		cin >> tp;
		if (tp == 1)
		{
			cin >> v1 >> v2 >> q;
			while (v1 != v2)
			{
				if (v1 > v2)
				{
					cost[v1] += q;
					v1 /= 2;
				}
				else
				{
					cost[v2] += q;
					v2 /= 2;
				}
			}
		}
		else
		{
			cin >> a >> b;
			long long res = 0;
			while (a != b)
			{
				if (a > b)
				{
					res += cost[a];
					a /= 2;
				}
				else
				{
					res += cost[b];
					b /= 2;
				}
			}
			cout << res << endl;
		}
	}

	cin.get(); cin.get();
	return 0;
}