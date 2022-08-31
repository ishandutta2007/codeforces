/*
No one dared to
Speak of the terrible danger
The hideous ancient warnings
Forged in the void of night

He has risen up
Out of the blackness
Chaos belongs to the prophet's sinister
A sickening monstrous sight

Through that stifling heat underneath the pale green moon
Hungered with the thirst to see things not yet seen
Climbing endless stairs, leading to the choking room
Eager to explore this most shocking mystery

Drifting beyond all time
Out of a churning sky
Drawn to the beckoning light
Of the dark eternal night

Black forces
Rage in a vortex, fighting
Rays of destruction
Swallowing the emblem of the universe

I am the last
Born of the blood of the Pharaohs
The ultimate God of rotten creation
Sent to unleash this curse

Restless crowds draw near
Nameless herd in forms of fear
Amidst fallen ruins
Grotesque creatures battle

Settle on a stream
Yellow evil face near
Vacant monuments
Corpses of dead worlds left behind

Drifting beyond all time
Out of a churning sky
Drawn to the beckoning light
Of the dark eternal night

Trapped in a hellish dream
Spinning past worlds unseen
And frightfully vanishing
Into the dark eternal night

Drifting beyond all time
Out of a churning sky
Drawn to the beckoning light
Of the dark eternal night

Trapped in a hellish dream
Spinning past worlds unseen
And frightfully vanishing
Into the dark eternal night
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 600;

using namespace std;

int n, m;
int ar[N][N];
int shit;
vector<int> g[N];
int clr[N];

void dfs(int v, int c)
{
	clr[v] = c;
	for (int i = 1; i <= n; i++)
	{
		if (ar[v][i] == 0 && clr[i] == 0)
		{
			dfs(i, 4 - c);
		}
	}
}

int nei(int a, int b)
{
	if (abs(a - b) < 2)
		return true;
	return false;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		ar[a][b] = 1;
		ar[b][a] = 1;
	}

	for (int i = 1; i <= n; i++)
		ar[i][i] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (clr[i])
			continue;
		if (g[i].size() == n - 1)
		{
			clr[i] = 2;
			continue;
		}
		dfs(i,1);
	}
	/*
	for (int i = 1; i <= n; i++)
	{
		cout << clr[i] << " ";
	}
	cout << endl;
	cin.get();
	*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (ar[i][j] != nei(clr[i], clr[j]))
				shit = 1;
		}
	}

	if (shit)
	{
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << char('a' + clr[i] - 1);
	}
	cout << endl;

	cin.get(); cin.get();
	return 0;
}