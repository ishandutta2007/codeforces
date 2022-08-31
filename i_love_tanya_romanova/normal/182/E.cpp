/*
Masquarade as he rides through the night
Blitzkrieg torture blade shining bright
In his eyes dreams of pain
As he kills the lovely shame
Messengers from fiery will
Speaking out what no one will
Violence for the virgin
Death falls from his bloody skin
Deny the father deny the mother
Burning the sister poison the brother
Sworn to take lives with weapons of death
In his hands
Born in the demonic rooms of hate
Torture is in his eyes like a glowing blade
Inhuman soul like an animal beast
The blood of Jesus one thousend people fall the priest
Son of evil
Awake to bring the neverending end
Kreator of demons and monsters command
Ruler of the darkness that is his kingdom
Equal as the blood death will make it all his own
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
#include <ctime> 
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define prev asdfasdgasdg

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

const int N = 3200;

using namespace std;

int n, l;
int a[N][3], b[N][3];
int dp[N][105][3];

void add(int &a, int &b)
{
	a += b;
	if (a >= bs)
		a -= bs;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i][0] >> b[i][0];
		a[i][1] = b[i][0];
		b[i][1] = a[i][0];
	}

	for (int i = 1; i <= n; i++)
	{
		dp[a[i][0]][i][0] += 1;
		if (a[i][0] != b[i][0])
			dp[b[i][0]][i][1] += 1;
	}

	for (int i = 1; i <= l; i++)
	{
		for (int cur = 1; cur <= n; cur++)
		{
			for (int rot1 = 0; rot1 <= 1; rot1++)
			{
				for (int to = 1; to <= n; to++)
				{
					if (to!=cur)
					for (int rot2 = 0; rot2 <= 1; rot2++)
					{
						if (a[to][0] == b[to][0] && rot2 == 1)
							continue;
						if (b[cur][rot1] == a[to][rot2])
							add(dp[i +a[to][rot2]][to][rot2], dp[i][cur][rot1]);
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			add(ans, dp[l ][i][j]);
		}
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}