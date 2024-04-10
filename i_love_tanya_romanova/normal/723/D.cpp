/*
You can read it in the papers
In some places it comes in thirty-two flavors
But you wouldn't tell no one
Your favorite if you could

From the White House to the alleys
From the President down to Long Tall Sally
Can't live with it but
You'll die without it - yes you would

Senorita's in the kitchen
She's a fistful of dynamite
You call 911 but you
Can't stop the fun tonite, it's alright

[Chorus:]
You can't start a fire without a spark
But there's something that I guarantee
You can't hide when infection starts
Because love is a social disease

Where you look you can find it
Try to run but you're always behind it
So you play hide and seek like a blind kid
Till you're caught - yeah you're caught

So you'll say that you had some
But they took it and held it for ransom
Were they tall, dark, skinny or
Handsome - you won't talk

So you telephone your doctor
Just to see what pill to take
You know there's no prescription
Gonna wipe this one away

[Chorus]

So full of high grade octane
She could run the bullet train on 38 double d's
Now you know for sure, you know the cure
To make a blind man see
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
#define have adsgagshdshfhds

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200031;

int n, m, k;
int board[200][200];
int used[200][200];
vector<pair<int, int>  >comp;
vector<pair<int, vector<pair<int, int> > > > LAKES;
int ans;

bool borderline(int a, int b)
{
	return (a == 1 || a == n || b == 1 || b == m);
}

bool outside(int a, int b)
{
	return (a<1 || a>n || b<1 || b>m);
}

void dfs(int a, int b)
{
	comp.push_back(make_pair(a, b));
	used[a][b] = 1;
	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			if (abs(dx) + abs(dy) != 1)
				continue;
			if (outside(a + dx, b + dy))
				continue;
			if (used[a + dx][b + dy] || board[a + dx][b + dy])
				continue;
			dfs(a + dx, b + dy);
		}
	}
}
int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		string st;
		cin >> st;
		for (int j = 1; j <= m; j++)
		{
			if (st[j - 1] == '.')
				board[i][j] = 0;
			else
				board[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j] == 1)
				continue;
			if (used[i][j])
				continue;
			comp.clear();
			dfs(i, j);
			int flag = 0;
			for (int q = 0; q < comp.size(); q++)
			{
				if (borderline(comp[q].first, comp[q].second))
					flag = 1;
			}
			if (flag)
				continue;
			LAKES.push_back(make_pair(comp.size(), comp));
		}
	}

	sort(LAKES.begin(), LAKES.end());

	while (LAKES.size() > k)
	{
		ans += LAKES[0].first;
		comp = LAKES[0].second;
		for (int i = 0; i < comp.size(); i++)
		{
			int a = comp[i].first;
			int b = comp[i].second;
			board[a][b] = 1;
		}
		LAKES.erase(LAKES.begin());
	}

	cout << ans << endl;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j] == 1)
				cout << "*";
			else
				cout << ".";
		}
		cout << endl;
	}

	cin.get(); cin.get();
	return 0;
}