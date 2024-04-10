/*
Authorised to kill, fuming with rage
Urged by sexual instinct
Absorbed massacre, casualties
No chance to get away
Bloodthirstiness, dismemberment
Pathological satisfaction
Stimulated thoughts, increased wantonness
Until redeemed climax

Time will come to balance the account
Send you legally to hell
Electric chair is reserved sure enough
Your death struggle rings the bell

Brutal rapes, child mistreated
Unscrupulous crimes
Greed of flesh, naked skin
There is no relent
Wince bodies, torn genitals
Stamped by sadism
Chasted newborns, attractive females
Indescribable ecstasies

Time will come to balance the account
Send you legally to hell
Electric chair is reserved sure enough
Your death struggle rings the bell

Intimate kisses, secret wishes
With corporal beings
Ardent love, shameless intercourse
Just make sure it moves
Unmerciful disfigurement, a fleshy joy
Heart warming death
Coursing of souls, suck up the blood
Totally insane

Authorised to kill, fuming with rage
Urged by sexual instinct

Bloodthirstiness, dismemberment
Pathological satisfaction

Time will come to balance the account
Send you legally to hell
Electric chair is reserved sure enough
Your death struggle rings the bell
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
const int N = 131;

int n, m, k;
long long dp[N][N][N];
int cost[N][N];
int ar[N];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m >> k;

	for (int i = 0; i <= n; i++)
	{
		for (int last = 0; last <= m; last++)
		{
			for (int groups = 0; groups <= k; groups++)
			{
				dp[i][last][groups] = 1e18;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
	}

	for (int i = 1; i <= n;i++)
	for (int j = 1; j <= m; j++)
	{
		cin >> cost[i][j];
	}

	for (int i = 1; i <= m; i++)
	{
		if (ar[1] != 0 && ar[1] != i)
			continue;
		dp[1][i][1] = 0;
		if (ar[1] == 0)
			dp[1][i][1] = cost[1][i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int q = 1; q <= n; q++)
			{
				for (int nc = 1; nc <= m; nc++)
				{
					if (ar[i + 1] != 0 && ar[i + 1] != nc)
						continue;
					int cost_pay = (ar[i + 1] == 0 ? cost[i + 1][nc] : 0);
					dp[i + 1][nc][q + (nc != j)] = min(dp[i + 1][nc][q+(nc!=j)], dp[i][j][q] + cost_pay);
				}
			}
		}
	}

	long long ans = 1e18;
	for (int i = 1; i <= m; i++)
	{
		ans = min(ans, dp[n][i][k]);
	}
	if (ans > 1e17)
		cout << -1 << endl;
	else
		cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}