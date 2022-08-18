/*
I got no reason, to lie to you
What's in the cards, that's what I do
I was born a-running and laughing out loud
With my feet on the ground and my head in the clouds

You better run, baby you better run
I got a blade like lightning, silver bullets in my gun

I'm short and I'm tall, I'm black and I'm white
Sometimes I be wrong, sometimes I be right
I'm iron and steel, I'm bad to the bone
You come looking for trouble, honey don't you come alone

You better run, oh baby you better run
I got a blade like lightning, silver bullets in my gun

I seen 'em come, and I seen 'em go
I seen things and been people, that nobody knows
I'm talking in pictures and I'm painting them black
I seen Satan coming honey, in a big black Cadillac

You better run, baby you better run, oh yeah
I got a blade like lightning, silver bullets in my gun

Watch out
*/

//#pragma comment(linker, "/STACK:16777216")
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 700;

using namespace std;

int n, m, board[N][N], s1[N][N], s2[N][N];
int ar1[N][N], ar2[N][N];

int tests;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("C:/input.txt","r",stdin);
	//freopen("C:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string st;
		cin >> st;
		for (int j = 1; j <= m; j++)
		{
			if (st[j - 1] == '#')
				board[i][j] = 1;
			else
				board[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j] == 0 && board[i][j + 1] == 0)
				ar1[i][j] = 1;
			if (board[i][j] == 0 && board[i + 1][j] == 0)
				ar2[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			s1[i][j] = s1[i - 1][j] + s1[i][j - 1] - s1[i - 1][j - 1] + ar1[i][j];
			s2[i][j] = s2[i - 1][j] + s2[i][j - 1] - s2[i - 1][j - 1] + ar2[i][j];
		}
	}

	cin >> tests;
	for (; tests; --tests)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = 0;
		//x2, y2-1
		ans = s1[x2][y2 - 1] - s1[x1 - 1][y2 - 1] - s1[x2][y1 - 1] + s1[x1 - 1][y1 - 1];
		//x2-1,y2
		ans += s2[x2 - 1][y2] - s2[x1 - 1][y2] - s2[x2 - 1][y1 - 1] + s2[x1 - 1][y1 - 1];
		cout << ans << endl;
	}

	cin.get(); cin.get();
	return 0;
}