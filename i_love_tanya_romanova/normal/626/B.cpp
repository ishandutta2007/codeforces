/*
You don't know where it is you're going
But you know you're on your way
Life only gives what you apply
Spend every day just searching
For something to pass the time
So many ways to waste a life

Debasing
Replacing
Embracing
Time wasting
Quit thinking
Mind shrinking

Wasting your life

Wasting away in a pseudo-existence
Let reality pass you by
Apathy and consciousness collide
You can join the real world
Don't let it be denied
Cut the cord: activate your mind

You don't know where it is you're going
But you know you're on your way
Life only gives what you apply
Don't let it be a last-minute decision
To stop throwing away your time
Before you know it, it's over and you die

Stop wasting your life
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 250;

using namespace std;

int dp[N][N][N];
int cnt[10];
int n;
string st;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	cin >> st;
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] == 'B')
			++cnt[0];
		if (st[i] == 'G')
			++cnt[1];
		if (st[i] == 'R')
			++cnt[2];
	}

	dp[cnt[0]][cnt[1]][cnt[2]] = 1;

	for (int sum = 200; sum > 0; --sum)
	{
		for (int i = 0; i <= 200; i++)
		{
			for (int j = 0; j <= 200; j++)
			{
				if (i + j > sum)
					continue;
				int rem = sum - i - j;
				if (dp[i][j][rem] == 0)
					continue;
				if (i > 1)
					dp[i - 1][j][rem] = 1;
				if (j > 1)
					dp[i][j - 1][rem] = 1;
				if (rem > 1)
					dp[i][j][rem - 1] = 1;
				if (i > 0 && j > 0)
					dp[i - 1][j - 1][rem + 1] = 1;
				if (i > 0 && rem > 0)
					dp[i - 1][j + 1][rem - 1] = 1;
				if (j > 0 && rem > 0)
					dp[i + 1][j - 1][rem - 1] = 1;
			}
		}
	}

	string ans = "";
	if (dp[1][0][0])
		ans += "B";
	if (dp[0][1][0])
		ans += "G";
	if (dp[0][0][1])
		ans += "R";

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}