/*
One, two, three, four, five against one
Five, five, against one
Said one, two, three, four, five against one
Five, five, five, five, five against one

Torture from you to me
Abducted from the street

I'd rather be
I'd rather be with
I'd rather be with an animal

Why would you wanna hurt me? Oh
Oh, so frightened of your pain

I'd rather be
I'd rather be with
I'd rather be with an animal
I'd rather be
I'd rather be
I'd rather be with an animal

I'd rather be
I'd rather be with
I'd rather be with an animal
I'd rather be
I'd rather be
I'd rather be with an animal

Said one, two, three, four, five against one
Five, five, five, five, five against one
One, two, three, four, five against one
Five, five, five, five, five against one
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
const int N = 3000031;

int n, ar[N];
int cnt[N];
long long total[N], below[N];
int tests, val;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		cnt[ar[i]]++;
	}

	for (int i = 1; i <= 3000000; i++)
	{
		if (cnt[i] == 0)
			continue;

		for (int j = 1; j*i <= 3000000; j++)
		{
			total[i*j] += 1ll*cnt[i] * cnt[j];
			if (i == j)
				total[i*j] -= cnt[i];
		}
	}

	for (int i = 1; i <= 3000000; i++)
	{
		below[i] = below[i - 1] + total[i - 1];
	}

	long long RES = 1ll * n*(n - 1);

	cin >> tests;
	for (; tests; --tests)
	{
		cin >> val;
		cout << RES - below[val] << "\n";
	}

	cin.get(); cin.get();
	return 0;
}