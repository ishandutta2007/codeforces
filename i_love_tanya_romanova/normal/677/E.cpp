/*
You were under the impression
That when you were walking forward
You'd end up further onward
But things ain't quite that simple.

You got altered information
You were told to not take chances
You missed out on new dances
Now you're losing all your dimples.

My jacket's gonna be cut and slim and checked,
Maybe a touch of seersucker, with an open neck.
I ride a G.S. scooter with my hair cut neat,
Wear my wartime coat in the wind and sleet.

Love Reign O'er Me.
Love Reign O'er Me.
Love.

I've had enough of living
I've had enough of dying
I've had enough of smiling
I've had enough of crying
I've taken all the high roads
I've squandered and I've saved
I've had enough of childhood
I've had enough of graves...

Get a job and fight to keep it,
Strike out to reach a mountain.
Be so nice on the outside
But inside keep ambition

Don't cry because you hunt them
Hurt them first they'll love you
There's a millionaire above you
And you're under his suspicion.

I've had enough of dancehalls
I've had enough of pills
I've had enough of streetfights
I've seen my share of kills
I'm finished with the fashions
And acting like I'm tough
I'm bored with hate and passion
I've had enough of trying to love.
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
const int N = 1040;

int n;
string st;
int board[N][N];
int tozero[N][N][8];
long double sum1[N][N], sum2[N][N], sum3[N][N], sum4[N][N];
int ansx, ansy, anstp, ansl;
long double ans_log;
long double L[N];

long double get_log(int cx, int cy, int len, int tp)
{
	--len;
	long double res;

	if (tp == 0)// veritcal
	{
		res = sum2[cx + len][cy] - sum2[cx - len - 1][cy] + sum4[cx][cy + len] - sum4[cx][cy - len - 1];
	}
	else
	{
		res = sum1[cx + len][cy + len] - sum1[cx - len - 1][cy - len - 1] + sum3[cx + len][cy - len] - sum3[cx - len - 1][cy + len + 1];
	}
	//cout << cx << "%" << cy << " " << tp << " " << res << " "<<len<< endl;
	res -= L[board[cx][cy]];
	return res;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	L[2] = log(2);
	L[3] = log(3);
	L[1] = log(1);

	int nzero = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> st;
		for (int j = 0; j < st.size(); j++)
		{
			board[i+1][j+1] = st[j] - 48;
			if (board[i + 1][j + 1])
				nzero = 1;
		}
	}
	
	if (nzero == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			tozero[i][j][0] = tozero[i - 1][j][0] + 1;
			tozero[i][j][7] = tozero[i - 1][j - 1][7] + 1;
			tozero[i][j][6] = tozero[i][j - 1][6] + 1;
			tozero[i][j][1] = tozero[i - 1][j + 1][1] + 1;
			if (board[i][j] == 0)
				tozero[i][j][0] = tozero[i][j][7] = tozero[i][j][6] = tozero[i][j][1] = 0;
		}
	}

	for (int i = n; i; --i)
	{
		for (int j = n; j; --j)
		{
			tozero[i][j][2] = tozero[i][j + 1][2] + 1;
			tozero[i][j][3] = tozero[i + 1][j + 1][3] + 1;
			tozero[i][j][4] = tozero[i + 1][j][4] + 1;
			tozero[i][j][5] = tozero[i + 1][j - 1][5] + 1;
			if (board[i][j] == 0)
			{
				for (int q = 2; q <= 5; q++)
				{
					tozero[i][j][q] = 0;
				}
			}
		}
	}

	for (int i = 1; i <= n+1; i++)
	{
		for (int j = 1; j <= n+1; j++)
		{
			sum1[i][j] = sum1[i - 1][j - 1];
			sum2[i][j] = sum2[i - 1][j];
			sum3[i][j] = sum3[i - 1][j + 1];
			sum4[i][j] = sum4[i][j - 1];
			if (board[i][j] != 0)
				sum1[i][j] += L[board[i][j]],
				sum2[i][j] += L[board[i][j]],
				sum3[i][j] += L[board[i][j]],
				sum4[i][j] += L[board[i][j]];
		}
	}

	for (int cx = 1; cx <= n; cx++)
	{
		for (int cy = 1; cy <= n; cy++)
		{
			// vertical

			if (board[cx][cy] == 0)
				continue;
			int mx = n;
			mx = min(mx, tozero[cx][cy][0]);
			mx = min(mx, tozero[cx][cy][2]);
			mx = min(mx, tozero[cx][cy][4]);
			mx = min(mx, tozero[cx][cy][6]);

			long double cur_log = get_log(cx, cy, mx, 0);
			if (cur_log > ans_log)
			{
				ans_log = cur_log;
				ansx = cx;
				ansy = cy;
				ansl = mx;
				anstp = 0;
			}

			mx = n;
			for (int D = 1; D <= 7; D += 2)
			{
				mx = min(mx, tozero[cx][cy][D]);
			}
			//cout << cx << " " << cy << " " << mx << endl;
			cur_log = get_log(cx, cy, mx, 1);
			if (cur_log > ans_log)
			{
				ans_log = cur_log;
				ansx = cx;
				ansy = cy;
				ansl = mx;
				anstp = 1;
			}
		}
	}

	//cout << ansx << " " << ansy << " " << anstp << endl;

	long long ans = 1;
	//cout << ansl << endl;
	--ansl;
	if (anstp == 0)// vert
	{
		for (int i = ansx - ansl; i <= ansx + ansl; i++)
		{
			ans = ans*board[i][ansy];
			ans %= bs;
		}
		for (int j = ansy - ansl; j <= ansy + ansl; j++)
		{
			if (j != ansy)
			{
				ans = ans*board[ansx][j];
				ans %= bs;
			}
		}
	}
	else
	{
		for (int dx = -ansl; dx <= ansl; dx++)
		{
			//cout << dx << " " << ans << endl;
			ans = ans*board[ansx + dx][ansy + dx];
			ans %= bs;
		}
		for (int dx = -ansl; dx <= ansl; dx++)
		{
			if (dx == 0)
				continue;
			ans = ans*board[ansx + dx][ansy - dx];
			ans %= bs;
		}
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}