/*
Resolute, a stance of defiance
Always teetering on the brink
Nothing can hold you back when
When you're not holding back a thing

Open arms, we embrace tomorrow
Closed fists, tarnishing today
We're not afraid to open our mouths and scream
We believe in what we say

Like a whisper to the dusk
An oath against the shadows
Denying the dark
Fight, fight, fight til the break of dawn

Like a prayer unto the dawn
In arms against the shadows
Destroying the dark
Fight, fight, fight til the break of dawn

Covered in sweat and blood
Yet still our heads held high
Actions have consequences
When you live for foolish pride

Been careful not to lose ourselves
Stand together one passion, one hate
We believe in a better tomorrow
We believe in what we say

Like a whisper to the dusk
An oath against the shadows
Denying the dark
Fight, fight, fight til the break of dawn

Like a prayer unto the dawn
In arms against the shadows
Destroying the dark
Fight, fight, fight til the break of dawn
Fight, fight, fight til the break of dawn

We'll fight our battles, we'll wage our wars
We'll settle the scores with honor and blood
We'll wear our scars like medals of hope
Like medals of hope, like medals of hope

We'll fight our battles, we'll wage our wars
Settle the scores with honor and blood
We'll wear our scars like medals of hope
Like medals of hope, like medals of hope

Like a whisper to the dusk
An oath against the shadows
Denying the dark
Fight, fight, fight til the break of dawn

Like a prayer unto the dawn
In arms against the shadows
Destroying the dark
(Whisper to the dusk)

In arms against the shadows
Destroying the dark
(Whisper to the dusk)
In arms against the shadows
Destroying the dark

Fight, fight, fight til the break of dawn
Fight, fight, fight til the break of dawn
Fight, fight, fight til the break of dawn
Fight, fight, fight til the break of dawn
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
const int N = 100031;

int n;
string st;
pair<int, int> ps[2000];

int get_x(char c)
{
	if (c == '0')
		return 3;
	return (c - '1') / 3;
}

int get_y(char c)
{
	if (c == '0')
		return 1;
	return (c - '1') % 3;
}

pair<int, int> eval(char a, char b)
{
	int dx = get_x(a) - get_x(b);
	int dy = get_y(a) - get_y(b);
	return (make_pair(dx, dy));
}

int cnt;

bool outside(int x, int y)
{
	if (x<0 || y<0 || x>3 || y>2)
		return true;
	if (x == 3 && y != 1)
		return true;
	return false;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	cin >> st;

	for (int i = 1; i < st.size(); i++)
	{
		ps[i] = eval(st[0], st[i]);
	}

	for (int i = '0'; i <= '9'; i++)
	{
		bool ok = 1;

		for (int j = 1; j < n; j++)
		{
			int qx = get_x(i) - ps[j].first;
			int qy = get_y(i) - ps[j].second;
			if (outside(qx, qy))
				ok = 0;
		}
		if (ok)
			++cnt;
	}

	if (cnt == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	cin.get(); cin.get();
	return 0;
}