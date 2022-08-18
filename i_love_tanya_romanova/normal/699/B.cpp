/*
He was standing at the rock
Gathering the flock
And getting there with no directions
And underneath the arch
It turned into a march
And there he found the spark to
Set this fucker off

Set it off
Set it off now children
Set it right
Set it off
Set it off now children
Set it off
Set it off now children
Set a fire
Set it off
Set it off now children

Suddenly a shot
Ripped into his heart
He lay in need of some attention
And there he played his card
Going into shock
The last thing that he said was
Set this fucker off

Set it off
Set it off now children
Set it right
Set it off
Set it off now children
Set it off
Set it off now children
Set a fire
Set it off
Set it off now children

Alright

Jesus at the back door
Everything is all right
All we need is some direction
Every time the wind blows
Everything you don't know
Turns into a revelation
And it all adds up inside your head
Time is wasting

Set it off
Set it off now children
Set it right
Set it off
Set it off now children
Set it off
Set it off now children
Set a fire
Set it off
Set it off now children

Alright
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
#define bs 1234567891
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200000;

int board[1050][1050], si[1050], sj[1050];
int n, m, found, fi, fj;
int total;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string st;
		cin >> st;
		for (int j = 1; j <= m; j++)
		{
			if (st[j - 1] == '*')
			{
				board[i][j] = 1;
				si[i]++;
				sj[j]++;
				total++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int here = si[i] + sj[j] - board[i][j];
			if (here == total)
			{
				found = 1;
				fi = i;
				fj = j;
			}
		}
	}

	if (found)
		cout << "YES" << endl << fi << " " << fj << endl;
	else
		cout << "NO" << endl;

	cin.get(); cin.get();
	return 0;
}