/*
Don't know where to begin
It comes from within
It's my story
Started as a boy
Music was my toy
It's my glory
Never passed a day
That I didn't play
My heart out
I'll never let it go
It's all I wanna know
That's what I'm about
That's what I'm about

I do it for the love
It's all I'm thinking of
It's in my heart
I feel it in my soul
It's my only goal
I do my part
Never will pass a day
That I won't play
My heart out
I'll never let it go
I'll just let you know
That's what I'm about
That's what I'm about
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
const int N = 122231;

long long dp[N], ans, n;

int main(){
	//freopen("king.in","r",stdin);
	//freopen("king.out","w",stdout);
//	freopen("F:/input.txt", "r", stdin);
//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i <= 500; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cin >> n;

	for (int i = 0; i <= 500; i++)
	{
		if (n < dp[i])
			break;
		ans = i;
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}