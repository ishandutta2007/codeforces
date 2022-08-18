/*
Early in the morning
Only flashes on my mind
I've been loving you for years and tears away
I've taken all I wanted
I've been lost and despaired
Hell knows I've grown so sad
Gosh, life is so unfair

Words will not relieve my pain (Am I ever smiling again?)
She will never be back home (tears away)
So my heart is crashing
It burns in so much pain because I remember your love

Should I leave it behind?
Shall I keep burning?
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
#define bs 100000007
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 500331;

int n;
int ar[N];

int ans;
int ps[N];

int eval()
{
	for (int i = 1; i <= n; i++)
	{
		ps[ar[i]] = i;
	}
	return abs(ps[1] - ps[n]);
}

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

	for (int a = 1; a <= n; a++)
	{
		for (int b = a + 1; b <= n; b++)
		{
			swap(ar[a], ar[b]);
			ans = max(ans, eval());
			swap(ar[a], ar[b]);
		}
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}