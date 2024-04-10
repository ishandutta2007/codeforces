/*
I can feel it grow
Starting like a little storm
Itching in my toes
But it's will to take over
Ain't quite that small
I can feel it grow
I can hear it moan
I can hear it's bitter cries
In my veins it crawls
Underneath my tongue it hides
I'm in control

An error in my genesis
The reason why I started this
Where did we go wrong?

Don't you know
In the end you're no stronger of hand
You are no stronger of heart
Don't you know
In the end, we'll be tragically torn apart
If we can't control the storm

Does it get to you?
Fury in your fingertips
It doesn't get me too
Turning hands to angry fists
In rageful bliss
Oh does it get to you?
Crying all your lullabies
Do you lick your wounds
Wondering how we could try to stop this useless fight

An error in my genesis
The reason why I started this
Where did we go wrong?

Don't you know
In the end you're no stronger of hand
You are no stronger of heart
Don't you know
In the end, we'll be tragically torn apart
If we can't control the storm
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

int ar[N];
int n;

int dp[102][4041][103][2];

int get_dp_res(int r, int l, int k, int goes, int base)
{
	if (r + 1 < l)
		return -1;
	return dp[r % 100][l][k][goes];
}

long long S[10000];

long long eval(int ans_state)
{
	int ans_l = ans_state / 10000;
	int ans_r = ans_state % 10000;
	if (ans_l > ans_r+1)
		return -1;
	return S[ans_l-1] - (S[n] - S[ans_r]);
}

int better(int a, int b, int who)
{
	if (a == -1)
		return b;
	if (b == -1)
		return a;

	long long res1 = eval(a);
	long long res2 = eval(b);
	if (res1 > res2)
	{
		if (who == 0)
			return a;
		else
			return b;
	}
	else
	{
		if (who == 0)
			return b;
		else
			return a;
	}
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/input.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
//		ar[i] = rand() % 10;
	}


	for (int i = 1; i <= n; i++)
	{
		S[i] = S[i - 1] + ar[i];
	}

	for (int r = 1; r <= n; ++r)
	{
		for (int cur_move = 1; cur_move >= 0; --cur_move)
		{
			for (int k = 1; k < 100; k++)
			{
				dp[r % 100][r+1][k][cur_move] = 10000 * (r+1) + r;
				int start_l, end_l;
				start_l = 1;
				end_l = n + 1;
				int used = n - r;

				if (cur_move == 0)
					start_l = max(start_l, used - k-25),
					end_l = min(end_l, used + k+25);

				else
					start_l = max(start_l, used - (k+25) + k),
					end_l = min(end_l, used + (k+25) + k);

				for (int l = start_l; l <= end_l; l++)
				{
					if (l>r + 1)
						continue;

					dp[r % 100][l][k][cur_move] = -1;

					if (l == r + 1)
					{
						dp[r % 100][l][k][cur_move] = 10000 * l + r;
						continue;
					}

					if (cur_move == 0)// left side
					{
						int state1 = get_dp_res(r, l + k, k, 1 - cur_move, 0);
						int state2 = get_dp_res(r, l + k + 1, k + 1, 1 - cur_move, 0);
						if (state1 == -1 && state2 == -1)
							dp[r % 100][l][k][cur_move] = l * 10000 + r;
						else
							dp[r % 100][l][k][cur_move] = better(state1, state2, 0);
					}
					else
					{
						int state1 = get_dp_res(r - k, l, k, 1 - cur_move, 1);
						int state2 = get_dp_res(r - k - 1, l, k + 1, 1 - cur_move, 1);
						if (state1 == -1 && state2 == -1)
							dp[r % 100][l][k][cur_move] = l * 10000 + r;
						else
							dp[r % 100][l][k][cur_move] = better(state1, state2, 1);
					}
				}
			}
		}
	}

	int ans_state = dp[n % 100][1][1][0];
//	cout << ans_state / 10000 << " " << ans_state % 10000 << endl;

	cout << eval(ans_state) << endl;


	cin.get(); cin.get();
	return 0;
}