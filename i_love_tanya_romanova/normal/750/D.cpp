/*
Next stop on the KLM
Two lips and a sturdy stem
A funny thing always happens when
I get a heavy jam
I'm gonna turn it into hydrogen
I I, I I, I I, I I I I, I

Cowgirl and a troubadour
Mgm and the lion's roar
A straight shot to the corner store
I wanna show you what
I wanna show you what your head is for
I I, I I, I I, I I I I, I

So much I, wish I could
So many I, wish I would
So much I, wish I could
Count on you not to defeat me

So much I, wish I could
So many I, wish I would
So much I, wish I could
Count on you not to defeat me

Please don't turn away again
Please don't turn me into them
Please don't turn away friend
Please don't turn me into them

Stand by for the great eclipse
Rip it out now shake your hips
Backing off the apocalypse
I gotta loosen up
I gotta loosen up to get my grip
I I, I I, I I, I I I I, I

So much I, wish I could
So many I, wish I would
So much I, wish I could
Count on you not to defeat me

So much I, wish I could
So many I, wish I would
So much I, wish I could
Count on you not to defeat me

Please don't turn away again
Please don't turn me into them
Please don't turn away friend
Please don't turn me into them

Please don't turn away again
Please don't turn me into them
*/

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
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n, t[500];
char used[400][400][152][8];
int s;
int is_split[5000];
int dx[100], dy[100];

void dfs(int x, int y, int t, int dir)
{
//	cout << x << " " << y << " " << t << " " << dir << endl;

	if (used[x][y][t][dir])
		return;
	used[x][y][t][dir] = 1;
	if (t == s)
		return;
	if (!is_split[t])
	{
		dfs(x + dx[dir], y + dy[dir], t + 1, dir);
	}
	else
	{
		dfs(x + dx[(dir + 1) % 8], y + dy[(dir + 1) % 8], t + 1, (dir+1)%8);
		dfs(x + dx[(dir + 7) % 8], y + dy[(dir + 7) % 8], t + 1, (dir+7)%8);
	}
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	dx[1] = dx[2] = dx[3] = 1;
	dx[5] = dx[6] = dx[7] = -1;
	dy[7] = dy[0] = dy[1] = 1;
	dy[3] = dy[4] = dy[5] = -1;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];
//		t[i] = 5;
		s += t[i];
		is_split[s] = 1;
	}

	dfs(200, 200, 1, 0);

	int ans = 0;
	for (int i = 0; i < 400; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			int found = 0;

			for (int T = 0; T <= s;T++)
			for (int dir = 0; dir < 8; dir++)
			{
				if (used[i][j][T][dir])
					found = 1;
			}

			if (found)
				++ans;
		}
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}