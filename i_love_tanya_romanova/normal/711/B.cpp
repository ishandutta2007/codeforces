/*
Product of my breeding
Inauspicious shapes
Formed by depravity
Abnegation of my past

Resigning, ireful
Watching the depopulation
Danger, impotence
Envelope the world with fear
Unnatural decay
Disclose the human need
Ptomaine, cremation
Baptism of fire we'll not survive

Abject and spirited
Getting excessive with results
Dislike a normal life
Excruciating waste away

Resigning, ireful
Watching the depopulation
Danger, impotence
Envelope the world with fear
Unnatural decay
Disclose the human need
Ptomaine, cremation
Baptism of fire we'll not survive

Symptoms of pathogenia
Depropotionate your body
Incurable disfigurement
Bones decompose alive

Resigning, ireful
Watching the depopulation
Danger, impotence
Envelope the world with fear
Unnatural decay
Disclose the human need
Ptomaine, cremation
Baptism of fire we'll not survive

Return to biogenetics
Turn over a new leaf
To form a vicious circle
Till end of time
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
const int N = 531;

int n;
long long ar[N][N];
int bi, bj;
long long need;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n;
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> ar[i][j];
			if (ar[i][j] == 0)
			{
				bi = i;
				bj = j;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (i == bi)
			continue;
		long long S = 0;
		for (int j = 1; j <= n; j++)
		{
			S += ar[i][j];
		}
		need = S;
		break;
	}

	long long have = 0;
	for (int i = 1; i <= n; i++)
	{
		have += ar[bi][i];
	}

	ar[bi][bj] = need - have;

	if (ar[bi][bj] <= 0 || ar[bi][bj] > 1e18)
	{
		cout << -1 << endl;
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		long long S = 0;
		for (int j = 1; j <= n; j++)
		{
			S += ar[i][j];
		}
		if (S != need)
		{
			cout << -1 << endl;
			return 0;
		}
		S = 0;
		for (int j = 1; j <= n; j++)
		{
			S += ar[j][i];
		}
		if (S != need)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	long long S = 0;
	for (int i = 1; i <= n; i++)
	{
		S += ar[i][i];
	}
	if (S != need)
	{
		cout << -1 << endl;
		return 0;
	}
	S = 0;
	for (int i = 1; i <= n; i++)
	{
		S += ar[i][n - i + 1];
	}
	if (S != need)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << ar[bi][bj] << endl;

	cin.get(); cin.get();
	return 0;
}