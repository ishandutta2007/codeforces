/*
From the dawn of time we came
To find the place of promise
Moving silently down
Through war disabled centuries

Living many secret lives
Unrecognised by human eyes
Struggling to reach the aim
To dwell in perpetuality

We are the messengers
Of inmost thought
Our words of confession
Fall away to nought

Domination of the universe
Contains our vital interests
Swift coursing blood of our veins
Cured the grieving pains

When the few who remain
Will battle to the last
For enchanted lands
Take charge of reign
Leave behind the past
Early history in our hands
Living in the land of promise
Beyond the other world

Our mission is done
Fear neither men nor fates
Pray for disease
But escape your soul

Duration of 100 lives
Get the worlds undoing
Because no one ever knows
We are among you

From the dawn of time we came
To find the place of promise
Moving silently down
Through war disabled centuries

Living many secret lives
Unrecognised by human eyes
Struggling to reach the aim
To dwell in perpetuality
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
const int N =105031;

int n, fi, fj;
string st[10000];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> st[i];
		if (st[i][0] == 'O'&&st[i][1] == 'O')
			fi = i, fj = 0;
		if (st[i][3] == 'O'&&st[i][4] == 'O')
			fi = i, fj = 1;
	}

	if (fi == 0)
	{
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	for (int i = 1; i <= n; i++)
	{
		if (fi == i)
		{
			st[i][fj * 3] = st[i][fj * 3 + 1] = '+';
		}
		cout << st[i] << endl;
	}

	cin.get(); cin.get();
	return 0;
}