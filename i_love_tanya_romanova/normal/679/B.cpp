/*
Skeletons of steel and glass
Tombstones of a time gone by
Whispered stories - fairy tales
No one knows who and why

100 years in an age of darkness
Many plagues have cleaned the land
Kill them all - saints and sinners
Fertile lands now desert sand

Gangs and tribes lead the lives
None proud nation has survived

Welcome to the quest for fire
Pledge allegiance and be sworn
Hold your ground in a world so torn
Blood and iron - blood and iron
The way to pay for all
To an age of pain we're gonna fall

Fear the places cursed and damned
Stick to new rules and obey
New slaughters and new lambs
The repeating history

Everlasting, deadly silence
'Til the winds disturb the peace
Sounds of tumbling walls and bridges
All our progress... deceased

Forged in fire forged in pain
And you lead a life in vain

Howling winds in the ruins - unreal story time
Mind pictures of the lost - pure as a bell chime
And a spark glimmers on - once a fire of life to become

Will you dare to listen
How much pain can you take
The oath of gods and mortals
A chain no one can break
And the flame is burning on - a fire of life to become
*/

#pragma comment(linker, "/STACK:16777216")
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
const int N = 1510000;

int cubes[N];
pair<long long, long long> res[N];

pair<long long, long long> better(pair<long long, long long> p1, pair<long long, long long> p2)
{
	if (p1.first != p2.first)
		return p1.first > p2.first ? p1 : p2;
	return p1.second > p2.second ? p1 : p2;
}

pair<long long, long long> solve(long long x)
{
	if (x < 1e6)
	{
		return res[x];
	}
	long long best_below = pow(x + .5, 1.0 / 3);
	long long best2 = best_below - 1;
	pair<long long, long long> P1 = solve(best_below*best_below*best_below - best2*best2*best2 - 1);
	P1.first++;
	P1.second += best2*best2*best2;
	pair<long long, long long> P2 = solve(x - best_below*best_below*best_below);
	P2.first++;
	P2.second += best_below*best_below*best_below;
	return better(P1, P2);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	for (int i = 1; i <= 1000000; i++)
	{
		int totake = pow(i + .5, 1. / 3);
		cubes[i] = cubes[i - totake*totake*totake] + 1;
	}

	for (int i = 1; i <= 1000000; i++)
	{
		res[i] = res[i - 1];
		if (cubes[i] >= res[i].first)
		{
			res[i] = make_pair(cubes[i], i);
		}
	}

	long long n;
	cin >> n;
	
	pair<long long, long long> res = solve(n);

	cout << res.first << " " << res.second << endl;

	cin.get(); cin.get();
	return 0;
}