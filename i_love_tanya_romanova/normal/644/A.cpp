/*
With life's four-way stop
The change in your shadow drops
Fate pulls you down for the count
With broken promises to amount

Time seal our ways to the heart of our hiding placce
When all our life lies are crossed
Some scars can never heal from what we lost

To fail the test and the power destroy
To light the way where you have gone
For all your funerals to come
A requiem in death of some

And it seems to be that consistency is not what lingers ahead
But a virtue of the dead
One of these days
Hours pass the night's stage
When your spirit won't turn on you
The world shuts down with no replay to undo you

Breathing, lifeless, not afraid to die
Breathing, lifeless, you're afraid not to live

Breathing, lifeless, not afraid to die
Breathing, lifeless, you're afraid not to live

To fail the test and the power destroy
To light the way where you have gone
For all your funerals to come
A requiem in death of some
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

using namespace std;

int n, a, b;
vector<int> v1, v2;
int ans[200][200];

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> a >> b;

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
			v1.push_back(i);
		else
			v2.push_back(i);
	}
	
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			if (i % 2 == j % 2)
			{
				if (v2.size() == 0)
					continue;
				ans[i][j] = v2.back();
				v2.pop_back();
			}
			else
			{
				if (v1.size() == 0)
					continue;
				ans[i][j] = v1.back();
				v1.pop_back();
			}
		}
	}

	if (v1.size() || v2.size())
	{
		cout << -1 << endl;
	}

	else
	{
		for (int i = 1; i <= a; i++)
		{
			for (int j = 1; j <= b; j++)
			{
				if (j > 1)
					cout << " ";
				cout << ans[i][j];
			}
			cout << endl;
		}
	}

	cin.get(); cin.get();
	return 0;
}