/*
All these moments of pain
Must add up to something,
Our bodies have been trained to keep it all in,
But our hearts, still hold on

Some say to release it, forget about your past,
Instead we count the cost, it's part of us
That doesn't mean that we cannot move on,
It's just a memory of what we were once were

No matter what it is we've faced
It's now part of us (part of us)
We can overcome

Why rid of fuel that can make us stronger
When properly put behind us (put behind us)
And in the same way that
Everything good in life can be taken away
So can all this pain

No matter what it is we've faced
It's now part of us (part of us)
No matter what we've faced in this life
We can overcome

Trying to forget is a burden we can never bear,
When facing trials openly,
There's nothing left to hide,
New paths of strength come alive

No matter what it is we've faced
It's now part of us (part of us)
No matter what we've faced in this life
We can overcome

We can overcome
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
#define PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 2550;

using namespace std;

int n;
int a[N][N];

unsigned int one = 1;
unsigned int bmask[N][N / 32+2];
vector<pair<pair<int, int>, pair<int, int> > > order;

bool solve()
{
	for (int i = 0; i < n; i++)
	{
if (a[i][i]!=0)
return false;
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != a[j][i])
				return false;
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			order.push_back(make_pair(make_pair(a[i][j], 1), make_pair(i, j)));
			order.push_back(make_pair(make_pair(a[i][j], 2), make_pair(i, j)));
		}
	}
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			bmask[i][j / 32] |= (one << (j % 32));
		}
	}*/
	
	sort(order.begin(), order.end());
	for (int i = 0; i < order.size(); i++)
	{
		if (order[i].first.second == 2)// turn off
		{
			int ps1, ps2;
			ps1 = order[i].second.first;
			ps2 = order[i].second.second;
			bmask[ps1][ps2 / 32] += (one << (ps2 % 32));
			if (ps1 != ps2)
			{
				bmask[ps2][ps1 / 32] += (one << (ps1 % 32));
			}
		}
		else
		{
			int ps1 = order[i].second.first;
			int ps2 = order[i].second.second;
			for (int p = 0; p <= n / 32; p++)
			{
//				cout << ps1 << " " << ps2 << " " << p << (bmask[ps1][p] & bmask[ps2][p]) << endl;
				if (bmask[ps1][p] & bmask[ps2][p])
					return false;
			}
		}
	}
	return true;
}

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
//			a[i][j] = 1;
			scanf("%d", &a[i][j]);
		}
	}


	if (solve())
	{
		puts("MAGIC");
	}
	else
	{
		puts("NOT MAGIC");
	}

	cin.get(); cin.get();
	return 0;
}