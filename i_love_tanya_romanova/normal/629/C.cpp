/*
Sitting on the swing
Trying to relate to just anything
Wonder where it's at
Conversations of where it's at

Ooh yeah
Ohh yeah

People come and stare
Wondering who's really there
He smiles and says,
"I could've been one of them"

Oh Eddie, Eddie

He was something different
Oh well he never hurt no one
And I wonder if his father said
"Oh god, he's not my son"
And "Oh God, he's not my son"

Oh Eddie

He was all alone
Walked the streets
No place to call home
Fingers to his head
No one put him to his death

Oh Eddie

He was something different
But he never hurt no one
And I wonder if his father said
"Oh God, he's not my son"
And "Oh God, he's not my son"

Yeah, tell me something about him
'Cause music's his only prayer

He was something different
But he never hurt no one
And I wonder if his father said
"Oh God, he's not my son"

Oh now Eddie
Oh Eddie
Oh Eddie
Oh now Eddie

No Eddie you're not my son
No Eddie you're not my son
No Eddie you're not my son
No Eddie you're not my son

No Eddie you're not my son
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

const int N = 2050;

const double INF = 1e18;

using namespace std;

int n, m;
string st;
int dp[N][N];

void add(int&a, int b)
{
	a += b;
	if (a >= bs)
		a -= bs;
}

int bal, minbal, sum_bal;
int ans;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;
	cin >> st;

	dp[0][0] = 1;
	for (int i = 0; i < 2000; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			add(dp[i + 1][j + 1], dp[i][j]);
			if (j)
				add(dp[i + 1][j - 1], dp[i][j]);
		}
	}

	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] == '(')
			++bal;
		else
			--bal;
		minbal = min(minbal, bal);
	}

	sum_bal = bal;

	for (int len_pref = 0; len_pref <= n - m; len_pref++)
	{
		for (int bal = -minbal; bal <= len_pref; bal++)
		{
			long long ways1 = dp[len_pref][bal];
			int rem_len = n - m - len_pref;
			int rem_bal = bal + sum_bal;
			if (rem_bal <= 2000 && rem_bal >= 0)
				ways1 *= dp[rem_len][rem_bal];
			else
				ways1 = 0;
			ans += ways1%bs;
			ans %= bs;
		}
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}