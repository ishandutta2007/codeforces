/*
Greed has caused you to become a monster
Greed has caused you to become so cold
You said you loved him, then you put him away
"Till death do us part" means nothing to you
Greed has caused you to betray your family
Greed has caused you to become so jaded
We've got some news for you, every dollar you save

Will cushion your pillow in hell
You act like we're blind, deaf and dumb
Betrayal has now left us numb
We're sorry we can't escape from
This choice now we all must succumb
He's been thrown away, left for dead
This is the only father we've had
Thrown away, left for dead

How could you choose money instead
Greed has caused you to become a monster
Greed has caused you to become so cold
We've got some news for you, every dollar you save

Will cushion your pillow in hell
You act like we're blind, deaf and dumb
Betrayal has now left us numb
We're sorry we can't escape from
This choice now we all must succumb
He's been thrown away, left for dead
This is the only father we've had
Thrown away, left for dead
How could you choose money instead
We will never forget that you're the reason

This sadness has overwhelmed us
This grief is too much to bear
How can we look you in the eyes
How could you ruin his life
After all the years of of joy he brought us

There is no 'we' anymore
There is no 'us' anymore
You will have to live your last days in infamy

How could you do this
How could you choose to have him
Thrown away, left for dead
This is the only father we've had
Thrown away, left for dead
How could you choose money instead
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

#define eps 1e-6
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

const int INF = 1e9;
const int N = 500031;

int n;
int sx, sy;
string st;

struct fig
{
	int tp;
	int x;
	int y;
};

vector<fig> figs;

bool cmp_xy(fig a, fig b)
{
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

bool cmp_yx(fig a, fig b)
{
	if (a.y != b.y)
		return a.y < b.y;
	return a.x < b.x;
}

bool cmp_ypxx(fig a, fig b)
{
	if (a.y + a.x != b.y + b.x)
		return a.y + a.x < b.y + b.x;
	return a.x < b.x;
}

bool cmp_ymxx(fig a, fig b)
{
	if (a.y - a.x != b.y - b.x)
		return a.y - a.x < b.y - b.x;
	return a.x < b.x;
}

int get_ps(vector<fig> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].tp == 0)
			return i;
	}
	return 0;
}

bool beats(fig a, fig b)
{
	if ((a.tp == 1||a.tp==3) && a.x + a.y == b.x + b.y)
		return 1;
	if ((a.tp == 1 || a.tp == 3) && a.x - a.y == b.x - b.y)
		return 1;
	if ((a.tp == 2 || a.tp == 3) && (a.x == b.x || a.y == b.y))
		return 1;
	return 0;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	cin >> sx >> sy;

	fig king;
	king.tp = 0;
	king.x = sx;
	king.y = sy;

	figs.push_back(king);

	for (int i = 1; i <= n; i++)
	{
		cin >> st;
		int x, y;
		cin >> x >> y;
		fig temp;
		int here;
		if (st[0] == 'B')
			temp.tp = 1;
		if (st[0] == 'R')
			temp.tp = 2;
		if (st[0] == 'Q')
			temp.tp = 3;
		temp.x = x;
		temp.y = y;
		figs.push_back(temp);
	}

	int ans = 0;

	// xy
	sort(figs.begin(), figs.end(), cmp_xy);
	int ps = get_ps(figs);

	if (ps > 0 && beats(figs[ps - 1], figs[ps]))
		ans = 1;
	if (ps + 1 < figs.size() && beats(figs[ps + 1], figs[ps]))
		ans = 1;

	//yx
	sort(figs.begin(), figs.end(), cmp_yx);
	ps = get_ps(figs);

	if (ps > 0 && beats(figs[ps - 1], figs[ps]))
		ans = 1;
	if (ps + 1 < figs.size() && beats(figs[ps + 1], figs[ps]))
		ans = 1;

	sort(figs.begin(), figs.end(), cmp_ypxx);
	ps = get_ps(figs);

	if (ps > 0 && beats(figs[ps - 1], figs[ps]))
		ans = 1;
	if (ps + 1 < figs.size() && beats(figs[ps + 1], figs[ps]))
		ans = 1;

	sort(figs.begin(), figs.end(), cmp_ymxx);
	ps = get_ps(figs);

	if (ps > 0 && beats(figs[ps - 1], figs[ps]))
		ans = 1;
	if (ps + 1 < figs.size() && beats(figs[ps + 1], figs[ps]))
		ans = 1;

	if (ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	cin.get(); cin.get();
	return 0;
}