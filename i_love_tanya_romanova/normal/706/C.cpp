/*
The sinners masquerade
An asylum for the weak
A feast for the wolf
Our faces lost in the deep
Empty space our souls to keep

The hour of twilight
As silent as sin
Drifting beyond dreaming
Erasing all therein
Into black nightmare
Cry in vain
The eyes set sail
Towards ebony rain

The mirror cease to live
Images all gone
Cutting through our hearts
A slice of ended life
Will our memories stain the knife
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
const int N = 130000;

int n;
int ar[N];
long long dp[N][2];
string name[N];

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> name[i];
	}

	dp[1][0] = 0;
	dp[1][1] = ar[1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			dp[i][j] = 1e18;
		}
		for (int p = 0; p <= 1; p++)
		{
			for (int q = 0; q <= 1; q++)
			{
				string st1 = name[i - 1];
				string st2 = name[i];
				if (p)
					reverse(st1.begin(), st1.end());
				if (q)
					reverse(st2.begin(), st2.end());
				if (st1 <= st2)
					dp[i][q] = min(dp[i][q], dp[i - 1][p] + ar[i] * q);
			}
		}
	}

	long long res = min(dp[n][1], dp[n][0]);
	if (res > 1e17)
		res = -1;
	cout << res << endl;

	cin.get(); cin.get();
	return 0;
}